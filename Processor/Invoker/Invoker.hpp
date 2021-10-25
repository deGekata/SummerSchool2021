#include "../Libs/Stack/MyStack.h"
#include "../Shared/Shared.hpp"



struct Invoker {
    char* memory;
    char* code;
    SafeStack* stk ;
    int ip;
    int regs[4];
    
};

static void (*instructions[CMD_MAX])(Invoker*, char);

void init_instructions();

void init_invoker(Invoker* invoker, FILE* input);

void invoke_command(Invoker* invoker);

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    void instruction_ ## cmd (Invoker* invoker, char Cmd);

#include "../Shared/CMD_DEF.hpp"

#undef DEF_CMD

void print_inst(Invoker* invoker, int num) ;
