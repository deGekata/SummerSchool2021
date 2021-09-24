#include "MyStack.h"


#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
unsigned int hashFunc_(const char * str, int len, unsigned int init) {
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
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
int checkCanaryIntegrity_(SafeStack* st) {
    assert(st);
    assert(st->arr);
    if (st->f_canary != CANARY_SPECIAL_NUMBER || st->s_canary != CANARY_SPECIAL_NUMBER) {
        return 0;
    }

    if (st->arr[0] != CANARY_SPECIAL_NUMBER || st->arr[st->size + 1] != CANARY_SPECIAL_NUMBER) {
        return 0;
    }

    return 1;
}
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
int checkHashIntegrity_(SafeStack* st) {
    assert(st);

    int check_data_hash = hashFunc_((const char*)((int*)(&(st->arr_hash)) + 1), sizeof(SafeStack) - int((char*)&st->arr_hash - (char*)st + 1));
    int check_hash      = hashFunc_((const char*)((int*)(  st            ) + 1),                     int((char*)&st->arr_hash - (char*)st    ));
    int chech_arr_hash  = hashFunc_((const char*)(         st->arr      )      , sizeof(int) * st->size                                        );

    if(st->data_hash != check_data_hash || st->arr_hash != chech_arr_hash || st->hash != check_hash) {
        return 0;
    }

    return 1;
}
#endif

#if PROTECTION_LEVEL == 0
SafeStack* createStack_() {
#else 
SafeStack* createStack_(int call_line, const char* caller_func, const char* caller_func_source) {
#endif
    printf("%d\n%s\n%s\n", call_line, caller_func, caller_func_source); 
    SafeStack* stack = (SafeStack*) calloc (1, sizeof(*stack));

    assert(stack);

    stack->arr = NULL_SPECIAL_PTR;
    stack->capacity = stack->size = 0;

#if PROTECTION_LEVEL == CANARY 
    stack->arr = (int*) calloc (stack->capacity + 2, sizeof( *stack->arr ));
    stack->arr[0] = stack->arr[1] = CANARY_SPECIAL_NUMBER;
    stack->f_canary = stack->s_canary = CANARY_SPECIAL_NUMBER;
#endif
//rebuild
#if PROTECTION_LEVEL == HASH
    stack->capacity = 1;
    stack->arr = (int*) calloc (stack->capacity, sizeof( *stack->arr ));

    makeApplyHashes_(stack);
    /*stack->data_hash = hashFunc (0, (const char*) ( &(stack->size)  ), sizeof( stack->size )      );
    stack->arr_hash  = hashFunc (0, (const char*) ( stack->arr     ), sizeof( stack->size + 2 )  );
    stack->hash      = hashFunc (0, (const char*) ( &(stack->data_hash)), sizeof( stack->data_hash) * 2 );*/
#endif     

#if PROTECTION_LEVEL == FULL_PROTECTION
    stack->arr = (int*) calloc (stack->capacity + 2, sizeof( *stack->arr ));
    stack->arr[0] = stack->arr[1] = CANARY_SPECIAL_NUMBER;
    stack->f_canary = stack->s_canary = CANARY_SPECIAL_NUMBER;

    makeApplyHashes_(stack);
    /*stack->data_hash = hashFunc ((const char*) ( &(stack->size)  )   , sizeof( stack->size )        , 0);
    stack->arr_hash  = hashFunc ((const char*) ( stack->arr     )    , sizeof( stack->size + 2 )    , 0);
    stack->hash      = hashFunc ((const char*) ( &(stack->data_hash)), sizeof( stack->data_hash) * 2, 0);*/
#endif  
       
    return stack;
}

//TODO
#if PROTECTION_LEVEL == 0
void push_(SafeStack* st, int value){
#else 
void push_(SafeStack* st, int value, int call_line, const char* caller_func, const char* caller_func_source) {
    my_ASSERT(st);
#endif

    #if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        if (value == CANARY_SPECIAL_NUMBER) return;
    #endif
    if (st->size == st->capacity) {
        resize(st, st->size * 1.5 + 1);
    }

#if PROTECTION_LEVEL == NO_PROTECTION
    st->arr[ st->size ] = value;
    st->size += 1;
#endif 
    
#if PROTECTION_LEVEL == CANARY
    st->arr[ st->size + 1] = value;
    st->arr[ st->size + 2 ] = CANARY_SPECIAL_NUMBER;
    st->size += 1;
#elif PROTECTION_LEVEL == HASH
    st->arr[ st->size ] = value;
    st->size += 1;

    makeApplyHashes_(st);

#elif PROTECTION_LEVEL == FULL_PROTECTION
    st->arr[ st->size + 1] = value;
    st->arr[ st->size + 2 ] = CANARY_SPECIAL_NUMBER;
    st->size += 1;

    makeApplyHashes_(st);
#endif

}

#if PROTECTION_LEVEL == 0
int top_(SafeStack* st) {
#else 
int top_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source) {
    my_ASSERT(st); 
#endif

    if(st->size == 0) return VOID_STACK_RETURN;

#if PROTECTION_LEVEL == NO_PROTECTION or PROTECTION_LEVEL == HASH
    return st->arr[st->size - 1];

#elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    return st->arr[st->size];
#endif
}

#if PROTECTION_LEVEL == 0
void pop_(SafeStack* st) {
#else 
void pop_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source) {
    my_ASSERT(st); 
#endif
    
    if(st->size <= 0) return;

    --st->size;

#if PROTECTION_LEVEL == HASH
    makeApplyHashes_(st);

#elif PROTECTION_LEVEL == CANARY
    st->arr[ st->size + 1] = CANARY_SPECIAL_NUMBER;   

#elif PROTECTION_LEVEL == FULL_PROTECTION
    st->arr[ st->size + 1] = CANARY_SPECIAL_NUMBER;

    makeApplyHashes_(st);
#endif

    return;
}

#if PROTECTION_LEVEL == 0
void freeStack_(SafeStack* st) {
#else 
void freeStack_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source) {
    my_ASSERT(st);
#endif
    
    #if PROTECTION_LEVEL != NO_PROTECTION 
        st->size = -1;

        #if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
            memset(st->arr, 0xcdcd, st->capacity + 2);
        #else
            memset(st->arr, 0xcdcd, st->capacity);
        #endif

        st->capacity = -1;
    #endif

    free(st->arr);
    st->arr = NULL;
    free(st);
    
    return;
}

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
SafeStackHashes* makeHash_(SafeStack* st) {
    SafeStackHashes* st_hashes = (SafeStackHashes*) calloc(1, sizeof(*st_hashes));
#if PROTECTION_LEVEL == HASH
        st_hashes->data_hash = hashFunc_((const char*) (&(st->size)     ), size_t(&(st->arr)) - size_t(&(st->size)) + sizeof(int), 0);
      { st_hashes->arr_hash  = hashFunc_((const char*) (st->arr         ), sizeof(st->size)             , 0); }
        st_hashes->hash      = hashFunc_((const char*) (&(st->data_hash)), sizeof(st->data_hash) * 2    , 0);
#else
        st_hashes->data_hash = hashFunc_((const char*) (&(st->f_canary)) , size_t(&(st->s_canary)) - size_t(&(st->f_canary)) + sizeof(int), 0);
    if (st->arr = NULL_SPECIAL_PTR) { st->arr_hash = 123; } else
      { st_hashes->arr_hash  = hashFunc_((const char*) (st->arr     )    , sizeof(st->size + 2 )                 , 0); }
        st_hashes->hash      = hashFunc_((const char*) (&(st->data_hash)), sizeof(st->data_hash) * 2             , 0);
#endif
    return st_hashes;
}
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
void makeApplyHash_(SafeStack* st) {
    SafeStackHashes* st_hashes = makeHash_(st);
    st->hash      = st_hashes->hash;
    st->arr_hash  = st_hashes->arr_hash;
    st->data_hash = st_hashes->data_hash;
    free(st_hashes);
}
#endif




#if PROTECTION_LEVEL == 0
void resize_(SafeStack * st, int n_size) {
#else
int resize_(SafeStack* st, int n_capacity, int call_line, const char* caller_func, const char* caller_func_source) {    
    my_ASSERT(st);
#endif

    if(n_capacity < 0) return -1;
    
    if(n_capacity > st->capacity) {

    #if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == NO_PROTECTION
        int* buff = (int*) realloc(st->arr, n_capacity * sizeof(*st->arr));

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;

            #if PROTECTION_LEVEL == HASH
                makeApplyHashes_(st);
            #endif

            return 1;

        } else {
            return 0;
        }

    #elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        int* buff = (int*) realloc(st->arr, (n_capacity + 2) * sizeof(*st->arr));

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            st->arr[st->size + 1] = CANARY_SPECIAL_NUMBER;
            #if PROTECTION_LEVEL == FULL_PROTECTION
                makeApplyHashes_(st);
            #endif

        } else {
            return 0;
        }
    #endif
    } else if (n_capacity < st->capacity) {

    #if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == NO_PROTECTION
        int* buff = (int*) realloc(st->arr, n_capacity * sizeof(*st->arr));

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            st->size = n_capacity;

            #if PROTECTION_LEVEL == HASH
                makeApplyHashes_(st);
            #endif
            return 1;

        } else {
            return 0;
        }

    #elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        int* buff = (int*) realloc(st->arr, (n_capacity + 2) * sizeof(*st->arr));

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            st->size = n_capacity;

            st->arr[st->capacity + 1] = CANARY_SPECIAL_NUMBER;

            #if PROTECTION_LEVEL == FULL_PROTECTION
                makeApplyHashes_(st);
            #endif

        } else {
            return 0;
        }
    #endif
    }
   
    return 1;
}

void fillStats(SafeStackStats* stats, int prototype) {
    
}

int is_not_valid_(SafeStack* ptr) {
    int ret = 0;
    if(ptr == NULL) { 
        ret &= (1 << 0); 
        return ret;
    }
    
    if(ptr->size < 0) ret &= (1 << 1);
    if(ptr->capacity < 0) ret &= (1 << 2);
    if(ptr->capacity < ptr->size) ret &= (1 << 3);
    
#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    if()    
#endif
}

void my_assert_(SafeStack* ptr, const char* var_name, int assert_line, const char* low_function_caller, const char* caller_func_source, const char* caller_func, int call_line) {
    int ret_val = is_not_valid_(ptr);
    if(ret_val) {
        SafeStackStats* stats = (SafeStackStats*) calloc(1, sizeof(SafeStackStats));
        fillStats(stats, ret_val);
        //LOG();
        abort();
    }
    return;
}
//static SafeStack* descriptor (MyStack* prototype, MODE mode) {
//    //assert(prototype);
//
//    static size_t st_count = 0;
//    static size_t max_count = REALLOC_BAR;
//#if defined CANARY or defined FULL_PROTECTION
//    static InstancePair* arr = (InstancePair*) calloc(REALLOC_BAR + 2, sizeof(*arr));
//
//#endif // 
//
//    
//    if (mode == ACCESS) {
//        /*if (prototype == NULL) { return NULL; }*/
//        
//    } else if (mode == INIT) {
//
//        for (size_t it = 0; it < st_count; it++) {
//            if ( arr[it].prototype != 0) {
//                            
//            }   
//        }
//    }
//
//    
//
//}

//struct MyStack {
//    int HANDLE;
//    SafeStack* st;
//};

//static struct InstancePair {
//    MyStack* prototype;
//    SafeStack* object;
//    int is_temporary;
//};