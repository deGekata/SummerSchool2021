#include "../Libs/Stack/MyStack.h"

#define WIDTH 400
#define HEIGHT 300
#define MAX_GPU_MEM_SIZE WIDTH * HEIGHT

#define MAX_RAM_SIZE 3000

struct Invoker {
    int memory[MAX_RAM_SIZE + MAX_GPU_MEM_SIZE];
    SafeStack* stk ;
    int po_ip_tebya_vichislu;
    
}


void invoke_command()