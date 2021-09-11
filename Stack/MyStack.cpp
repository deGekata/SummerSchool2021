#include "MyStack.h"



unsigned int hashFunc(unsigned int init, const char * str, int len) {
    unsigned int hash = init;
    for (int it = 0; it < len; str++, it++) {
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
    SafeStack* st;
};

int checkCanaryIntegrity(SafeStack* st) {
    
}

int checkHashIntegrity(SafeStack* st);

static struct InstancePair {
    MyStack* prototype;
    SafeStack* object;
    int is_temporary;
};

static SafeStack* descriptor (MyStack* prototype, MODE mode) {
    //assert(prototype);

    static size_t st_count = 0;
    static size_t max_count = REALLOC_BAR;
#if defined CANARY or defined FULL_PROTECTION
    static InstancePair* arr = (InstancePair*) calloc(REALLOC_BAR + 2, sizeof(*arr));

#endif // 

    
    if (mode == ACCESS) {
        /*if (prototype == NULL) { return NULL; }*/
        
    } else if (mode == INIT) {

        for (size_t it = 0; it < st_count; it++) {
            if ( arr[it].prototype != 0) {
                            
            }   
        }
    }

    

}

SafeStack* createStack () {
        
    SafeStack* stack = (SafeStack*) calloc (1, sizeof(*stack));
    assert(stack);

#if defined CANARY or defined FULL_PROTECTION
    stack->data = (int*) calloc (BLOCK_SIZE + 2, sizeof( *stack->data ));
    stack->max_size = BLOCK_SIZE - 2;
    stack->data[0] = CANARY_SPECIAL_NUMBER;
    stack->data[1] = CANARY_SPECIAL_NUMBER;
#endif

#if defined HASH or defined NO_PROTECTION
    stack->data = (int*) calloc (BLOCK_SIZE, sizeof( *stack->data ));

    stack->max_size = BLOCK_SIZE;
#endif        

    stack->size = 0;

#if defined HASH or defined FULL_PROTECTION
    stack->size_hash = hashFunc (0, (const char*) ( &(stack->size)  ), sizeof( stack->size )      );
    stack->data_hash = hashFunc (0, (const char*) ( stack->data     ), sizeof( stack->size + 2 )  );
    stack->hash      = hashFunc (0, (const char*) ( &(stack->size_hash)), sizeof( stack->size_hash) * 2 );
#endif
        
    return stack;
}

int top (SafeStack* st){
    printf ("%d");
    return 0;
}

void push (SafeStack* st, int value) {
    if (st == NULL) {
        return;
    }

#ifdef defined CANARY or defined FULL_PROTECTION 
    if (value == CANARY_SPECIAL_NUMBER) {
        return;
    }
#endif  

    if (st->size == st->max_size) {
        int* buff = (int*) realloc (st->data, (BLOCK_SIZE + st->size) * sizeof(*st->data));

        if(buff == NULL) {
            return;
        }
        
        free(st->data);
        st->data = buff;
        st->max_size += BLOCK_SIZE;
    }

#ifdef NO_PROTECTION 
    st->data[ st->size ] = value;
    st->size += 1;
#endif 

#ifndef NO_PROTECTION
    if (st->data == NULL) {
        printf("Data error: structure on pointer %p is corrupted\n"
               "Pointer data in structure is 'NULL'\n");
        return;
    }
#endif // !NO_PROTECTION


#ifdef CANARY
    
#endif


}

void pop (SafeStack* st) {
    
}

void freeStack (MyStack* st);