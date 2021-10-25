#include "Invoker.hpp"

int main(int argc, char* argv[]) {
    Invoker* invoker = (Invoker*) calloc(1, sizeof(Invoker));

    invoker->stk = (SafeStack*) calloc(1, sizeof(SafeStack));
    createStack(invoker->stk);

    push_(invoker->stk, 10);
    printf("top: %d\n", top_(invoker->stk));
    push_(invoker->stk, 11);
    printf("top: %d\n", top_(invoker->stk));
    push_(invoker->stk, 12);
    printf("top: %d\n", top_(invoker->stk));
    push_(invoker->stk, 13);
    printf("top: %d\n", top_(invoker->stk));
    push_(invoker->stk, 14);
    printf("top: %d\n", top_(invoker->stk));
    
    printf("pop: %d\n", pop_(invoker->stk));
    printf("pop: %d\n", pop_(invoker->stk));
    printf("pop: %d\n", pop_(invoker->stk));
    printf("pop: %d\n", pop_(invoker->stk));
    printf("pop: %d\n", pop_(invoker->stk));


    if(argc < 2) assert(0 && "Not enough args");

    init_instructions();

    FILE* input = fopen(argv[1], "r");

    init_invoker(invoker, input);
    printf("invoker params: %d \n", invoker->ip);
    printf("loool");

    while(true) {
        invoke_command(invoker);
    }
    printf("loool");
    printf("yep top: %d", top_(invoker->stk));

    // char buff[10];
    // fread(buff, 1, 3, input);
    // printf("LOL %hhu", buff[2]);
    // // instruction_HLT(&invoker, 0);
    // print_inst(&invoker, buff[2]);

    return 0;
}