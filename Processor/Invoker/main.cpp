#include "Invoker.hpp"

int main(int argc, char* argv[]) {
    Invoker* invoker = (Invoker*) calloc(1, sizeof(Invoker));

    invoker->stk = (SafeStack*) calloc(1, sizeof(SafeStack));
    createStack(invoker->stk);

    if(argc < 2) assert(0 && "Not enough args");

    init_instructions();

    FILE* input = fopen(argv[1], "r");

    init_invoker(invoker, input);
    
    while(invoke_command(invoker)){};

    return 0;
}