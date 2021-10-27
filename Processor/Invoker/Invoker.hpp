#include "../Libs/Stack/MyStack.h"
#include "../Shared/Shared.hpp"
#include "SDL2/SDL.h"


struct Invoker {
    bool is_debug = false;
    char* memory;
    char* code;
    SafeStack* stk ;
    int code_size;
    int ip;
    int regs[5];
    SDL_Surface* screen_surface;
    SDL_Window *win;
    SDL_Renderer *ren;
    SDL_Texture *tex;
};

static bool (*instructions[CMD_MAX])(Invoker*, char);

void init_instructions();

void init_invoker(Invoker* invoker, FILE* input);

bool invoke_command(Invoker* invoker);

void invoker_debug(Invoker* invoker);

void invoker_debug_print_regs(Invoker* invoker);

void invoker_debug_print_code(Invoker* invoker);

void invoker_debug_print_stack(Invoker* invoker);

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    bool instruction_ ## cmd (Invoker* invoker, char Cmd);

#include "../Shared/CMD_DEF.hpp"

#undef DEF_CMD

void print_inst(Invoker* invoker, int num) ;

void init_video(Invoker* invoker);

void draw_video(Invoker* invoker);
