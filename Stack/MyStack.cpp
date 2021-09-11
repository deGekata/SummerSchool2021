#include "MyStack.h"



unsigned int hashFunc(const char * str) {
    unsigned int hash = 0;
    for (; *str; str++) {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

struct MyStack {
    int HANDLE;
};

static struct SafeStack {
    int st_size;
    int* st_data;
};

static struct InstancePair {
    MyStack* prototype;
    SafeStack* object;
    int is_temporary; 
};


static SafeStack* descriptor(int identifier, MODE mode) {
    static size_t st_count = 0;
    static SafeStack* arr = (SafeStack*) calloc(REALLOC_BAR, sizeof(*arr));
    
    if (mode == ACCESS) {
        
    } else if (mode == INIT) {
        if(identifier)
    }

    identifier

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