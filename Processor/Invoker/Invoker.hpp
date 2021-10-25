#include "../Libs/Stack/MyStack.h"
#include "../Shared/Shared.hpp"



struct Invoker {
    char* memory;
    char* code;
    SafeStack* stk ;
    int ip;
    int regs[4];
    
};

static bool (*instructions[CMD_MAX])(Invoker*, char);

void init_instructions();

void init_invoker(Invoker* invoker, FILE* input);

bool invoke_command(Invoker* invoker);

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    bool instruction_ ## cmd (Invoker* invoker, char Cmd);

#include "../Shared/CMD_DEF.hpp"

#undef DEF_CMD

void print_inst(Invoker* invoker, int num) ;
