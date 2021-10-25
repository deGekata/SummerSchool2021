#include "Invoker.hpp"

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    void instruction_ ## cmd (Invoker* invoker, char Cmd) code

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
    fread(invoker->memory, sizeof(char), file_size, input);

    invoker->code = invoker->memory + 2;
    invoker->memory += file_size; 
    printf("invoker params 4: %d \n", invoker->ip);

    return;
}

void invoke_command(Invoker* invoker) {
    printf("command id :%d\n", invoker->code[invoker->ip]);
    instructions[invoker->code[invoker->ip] & ~(mem | reg | immediate_constant)](invoker, invoker->code[invoker->ip]);

}


void print_inst(Invoker* invoker, int num) {
    instructions[num](invoker, num);
}