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
    printf("invoker params 1: %d \n", invoker->ip);

    memset(invoker->regs, 0, sizeof(invoker->regs));
    memset(invoker->memory, 0, sizeof(invoker->memory));
    printf("invoker params 2: %d \n", invoker->ip);

    createStack(invoker->stk);

    int file_size = getFileSize(input);
    printf("%d file-size", file_size);
    fread(invoker->memory, sizeof(char), file_size, input);

    invoker->code = invoker->memory + 2;
    invoker->memory += file_size; 
    invoker->code_size = file_size;
    printf("invoker params 4: %d \n", invoker->ip);

    return;
}


bool invoke_command(Invoker* invoker) {
    //assert ip
    int ret = instructions[invoker->code[invoker->ip] & ~(mem | reg | immediate_constant)](invoker, invoker->code[invoker->ip]);
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
    int mx_instr_size = 1 + 2;//log10(invoker->code_size) + 2;
    const char* first_spec = "\033[1;30;43m%*d\033[0m";
    const char* second_spec = "\033[1;30;42m%*d\033[0m";
    for(int cur_ip = 0; cur_ip < invoker->code_size; ++cur_ip) {
        printf(first_spec, mx_instr_size, cur_ip);
        const char* tmp = first_spec;
        first_spec = second_spec;
        second_spec = tmp;
    }
    printf("\n");
    for(int cur_ip = 0; cur_ip < invoker->code_size; ++cur_ip) {
        printf("%*.*X", mx_instr_size, 2, invoker->code[cur_ip]);
    }
    printf("\n");

    printf("%*c", invoker->ip * mx_instr_size + mx_instr_size - 2,' ');

    printf("\033[1;30;41m^^\033[0m\n");
    

    printf("current ip: %d\n", invoker->ip);

}

void invoker_debug_print_regs(Invoker* invoker) {
    const char* regs_offset_delim = "\033[1;30;41m###############\033[0m";
    int max_width = 12;
    for(int it = 0; it < 4; ++it ) printf("%s", regs_offset_delim);

    printf("\n\033[1;30;41m#\033[0m   ");
    for(int reg_num = 0; reg_num < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++reg_num) {
        printf("%*d \033[1;30;41m#\033[0m", max_width, invoker->regs[reg_num]);
    }


    printf("\n\033[1;30;41m#\033[0m   ");
    for(int reg_num = 0; reg_num < sizeof(invoker->regs) / sizeof(invoker->regs[0]); ++reg_num) {
        printf("%*cx \033[1;30;41m#\033[0m", max_width - 1, 'a' + reg_num);
    }
    printf("\n");

    for(int it = 0; it < 4; ++it ) printf("%s", regs_offset_delim);
    printf("\n\n");
}

void invoker_debug_print_stack(Invoker* invoker) {
    const char* regs_offset_delim = "\033[1;30;44m###############\033[0m\n";
    int max_width = 12;
    printf(regs_offset_delim);
    for(int it = invoker->stk->size - 1; it >= 0; --it) {
        printf("\033[1;30;44m#\033[0m");
        printf("%*d \033[1;30;44m#\033[0m\n", max_width, invoker->stk->arr[it]);
    }
    printf(regs_offset_delim);
    

}

void print_inst(Invoker* invoker, int num) {
    instructions[num](invoker, num);
}