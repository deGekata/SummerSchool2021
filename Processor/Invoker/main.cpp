#include "Invoker.hpp"
#include "Windows.h"


int main(int argc, char* argv[]) {
    Invoker* invoker = (Invoker*) calloc(1, sizeof(Invoker));

    invoker->stk = (SafeStack*) calloc(1, sizeof(SafeStack));
    createStack(invoker->stk);

    if(argc < 3) assert(0 && "Not enough args");

    init_instructions();

    FILE* input = fopen(argv[1], "r");
    assert(input && "Cant open file");

    if(strlen(argv[2]) > 1) {
        assert(0 &&"is_debug arg len should be 1 character");
    } else if (argv[2][0] != '0' && argv[2][0] != '1') {
        assert(0 && "is_debug should be 0/1 character");
        return -1;
    }
    init_invoker(invoker, input);

    invoker->is_debug = argv[2][0] - '0';
    
    while(invoke_command(invoker)){};


    return 0;
}