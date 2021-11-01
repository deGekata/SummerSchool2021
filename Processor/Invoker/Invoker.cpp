#include "Invoker.hpp"
#include <math.h>

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    bool instruction_ ## cmd (Invoker* invoker, char Cmd) code

#include "../Shared/CMD_DEF.hpp"

#undef DEF_CMD

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    instructions[NUM] = instruction_ ## cmd; 
void init_instructions() {
    #include "../Shared/CMD_DEF.hpp"
}
#undef DEF_CMD

void init_invoker(Invoker* invoker, FILE* input) {
    // invoker = (Invoker*) calloc (1, sizeof(Invoker));
    invoker->stk = (SafeStack*) calloc(1, sizeof(SafeStack));
    invoker->memory = (char*) calloc(MAX_RAM_SIZE + MAX_GPU_MEM_SIZE, sizeof(char));
    invoker->ip = 0;
    printf("invoker params 1: %zu \n", invoker->ip);

    memset(invoker->regs, 0, sizeof(invoker->regs));
    memset(invoker->memory, 0, MAX_RAM_SIZE + MAX_GPU_MEM_SIZE);
    printf("invoker params 2: %zu \n", invoker->ip);

    createStack(invoker->stk);

    size_t file_size = getFileSize(input);
    printf("%zu file-size", file_size);
    fread(invoker->memory, sizeof(char), file_size, input);

    invoker->code = invoker->memory + 2;
    invoker->memory += file_size; 
    invoker->code_size = file_size;
    printf("invoker params 4: %zu \n", invoker->ip);

    init_video(invoker);

    return;
}


bool invoke_command(Invoker* invoker) {
    //assert ip
    // printf("%d bef command\n", invoker->code[invoker->ip] & ~(mem | reg | immediate_constant));
    // printf("%hhu bef command ip val\n", invoker->code[invoker->ip]);
    // printf("%hhu bef command ip\n", invoker->ip);
    // printf("%p instr pointer\n", instructions[uint8_t(invoker->code[invoker->ip] & ~(mem | reg | immediate_constant))]);
    // printf("%p inst pop nter\n", instructions[2]);
    int ret = instructions[uint8_t(invoker->code[invoker->ip] & ~(mem | reg | immediate_constant))](invoker, invoker->code[invoker->ip]);
    // printf("cringe");
    if (invoker->is_debug) {
        invoker_debug(invoker);
        getchar();
        getchar();
    }

    // int ptr;
    // ptr += invoker->regs[*(invoker->code + invoker->ip++)];
    return ret;
    
}

void invoker_debug(Invoker* invoker) {
    printf("\n\n\n\n");

    invoker_debug_print_regs(invoker);
    invoker_debug_print_code(invoker);
    invoker_debug_print_stack(invoker);

}

void invoker_debug_print_code(Invoker* invoker) {
    // int mx_instr_size = 1 + 2;//log10(invoker->code_size) + 2;
    // const char* first_spec = "\033[1;30;43m%*d\033[0m";
    // const char* second_spec = "\033[1;30;42m%*d\033[0m";
    // for(int cur_ip = 0; cur_ip < invoker->code_size; ++cur_ip) {
    //     printf(first_spec, mx_instr_size, cur_ip);
    //     const char* tmp = first_spec;
    //     first_spec = second_spec;
    //     second_spec = tmp;
    // }
    // printf("\n");
    // for(int cur_ip = 0; cur_ip < invoker->code_size; ++cur_ip) {
    //     printf("%*.*X", mx_instr_size, 2, uint8_t(invoker->code[cur_ip]));
    // }
    // printf("\n");

    // printf("%*c", invoker->ip * mx_instr_size + mx_instr_size - 2,' ');

    // printf("\033[1;30;41m^^\033[0m\n");
    

    printf("current ip: %zu\n", invoker->ip);

}

void invoker_debug_print_regs(Invoker* invoker) {
    const char* regs_offset_delim = "\033[1;30;41m###############\033[0m";
    int max_width = 12;
    printf("\033[1;30;41m#\033[0m");
    for(size_t it = 0; it < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++it ) printf("%s", regs_offset_delim);
    printf("\033[1;30;41m#\033[0m");
    printf("\n\033[1;30;41m#\033[0m ");
    for(size_t reg_num = 0; reg_num < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++reg_num) {
        printf("%*d \033[1;30;41m#\033[0m ", max_width, invoker->regs[reg_num]);
    }


    printf("\n\033[1;30;41m#\033[0m");
    for(size_t reg_num = 0; reg_num < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++reg_num) {
        printf("%*cx \033[1;30;41m#\033[0m", max_width, char('a' + reg_num));
    }
    printf("\n");
    printf("\033[1;30;41m#\033[0m");
    for(size_t it = 0; it < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++it ) printf("%s", regs_offset_delim);
    printf("\033[1;30;41m#\033[0m");
    printf("\n\n");
}

void invoker_debug_print_stack(Invoker* invoker) {
    const char* regs_offset_delim = "\033[1;30;44m###############\033[0m\n";
    int max_width = 12;
    printf("%s", regs_offset_delim);
    for(int it = invoker->stk->size - 1; it >= 0; --it) {
        printf("\033[1;30;44m#\033[0m");
        printf("%*d \033[1;30;44m#\033[0m\n", max_width, invoker->stk->arr[it]);
    }
    printf("%s", regs_offset_delim);
    

}


void init_video(Invoker* invoker) {
    SDL_Init( SDL_INIT_EVERYTHING );

    invoker->win = SDL_CreateWindow("Hello World!", 300, 300, 900, 900, SDL_WINDOW_SHOWN);
    invoker->ren = SDL_CreateRenderer(invoker->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    invoker->screen_surface = SDL_GetWindowSurface(invoker->win);

    return;
}

void draw_video(Invoker* invoker) {
    printf("%d\n", __LINE__);
    invoker_debug_print_regs(invoker);
    invoker->screen_surface->pixels = (void*) ((int*)invoker->memory + invoker->regs[4]);
    printf("%p ptr invoker->win\n", invoker->win);
    printf("%p ptr invoker->tex\n", invoker->tex);
    printf("%p ptr invoker->ren\n", invoker->ren);
    printf("%p ptr invoker->screen_surface\n", invoker->screen_surface);
    printf("%d ptr invoker->screen_surface h\n", invoker->screen_surface->h);
    printf("%d ptr invoker->screen_surface w\n", invoker->screen_surface->w);
    printf("%d\n", __LINE__);
    invoker->tex = SDL_CreateTextureFromSurface(invoker->ren, invoker->screen_surface);
    printf("%p ptr invoker->tex\n", invoker->tex);
    printf("%p ptr invoker->ren\n", invoker->ren);
    printf("%p ptr invoker->screen_surface\n", invoker->screen_surface);
    printf("%d\n", __LINE__);
    SDL_RenderClear(invoker->ren);
    printf("%d\n", __LINE__);
    SDL_RenderCopy(invoker->ren, invoker->tex, NULL, NULL);
    printf("%d\n", __LINE__);
    SDL_RenderPresent(invoker->ren);
    printf("%d\n", __LINE__);
}