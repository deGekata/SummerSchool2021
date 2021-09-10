#include "MyStack.h"


struct MyStack {
    int HANDLE = BLOCK_SIZE;
};

static struct SafeStack {
    int st_size;
    int* st_data;
};


static SafeStack* descriptor(int identifier) {
    if(is_initialised) {
        for(size_t it = 0; it < )
    } else {
        static size_t st_count = 0;
        static SafeStack* arr = 
    }
}


int top (MyStack* st){
    printf ("%d", is_initialised);
    return 0;
}

void push (MyStack* st) {
    
}

void pop (MyStack* st) {
    
}

MyStack* createStack () {
    if(is_initialised) {
        for(size_t it = 0; it < )
    }
}

void freeStack (MyStack* st);