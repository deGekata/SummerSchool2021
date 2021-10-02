#include "MyStack.h"


#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
unsigned long long int hashFunc_(const char * str, int len, unsigned long long int init) {
    unsigned long long int hash = init;
    for (int it = 0; it < len; str++, it++) {
        hash += (unsigned char)(*str);
        hash += (hash << 20);
        hash ^= (hash >> 12);
    }

    hash += (hash << 6);
    hash ^= (hash >> 22);
    hash += (hash << 30);

    return hash;
}
#endif

#if PROTECTION_LEVEL == 0
SafeStack* createStack_() {
#else 
SafeStack* createStack_(call_INFO) {
#endif

    SafeStack* stack = (SafeStack*) calloc (1, sizeof(*stack));
    assert(stack);

    #if PROTECTION_LEVEL != 0
        stack->info = (StackCreationInfo*) calloc(1, sizeof(StackCreationInfo));
        assert(stack->info && "No extra memory");
        stack->info->caller_func_source = caller_func_source;
        stack->info->caller_func = caller_func;
        stack->info->call_line = call_line;
    #endif

    stack->arr = (my_type*)NULL_SPECIAL_PTR;
    stack->capacity = stack->size = 0;

#if PROTECTION_LEVEL == CANARY 
    stack->arr = (my_type*) calloc (sizeof(stack->f_canary) * 2, sizeof( char ));
    *get_ELEM(stack, 0) = *get_ELEM(stack, 1) = CANARY_SPECIAL_NUMBER;
    stack->f_canary = stack->s_canary = CANARY_SPECIAL_NUMBER;
#endif

#if PROTECTION_LEVEL == HASH
    makeApplyHash_(stack);
#endif     

#if PROTECTION_LEVEL == FULL_PROTECTION
    stack->arr = (my_type*) calloc (sizeof(stack->f_canary) * 2, sizeof( int64_t ));
    assert(stack->arr && "No memory space");
    *(int64_t*)(stack->arr) = *(int64_t*)((char*)stack->arr + sizeof(uint64_t)) = CANARY_SPECIAL_NUMBER;
    //stack->arr[0] = stack->arr[1] = CANARY_SPECIAL_NUMBER;
    stack->f_canary = stack->s_canary = CANARY_SPECIAL_NUMBER;
    
    printf("f_arr create caaaanary %x\n\n", *(int64_t*)(stack->arr));
    printf("s_arr create caaaanary %x\n\n", *(int64_t*)((char*)stack->arr + sizeof(uint64_t)));

    makeApplyHash_(stack);
#endif  
       
    return stack;
}

//TODO
#if PROTECTION_LEVEL == 0
void push_(SafeStack* st, my_type value){
#else 
void push_(SafeStack* st, my_type value, call_INFO) {
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
    *get_ELEM(st, st->size + 1) = value;
    *get_ELEM(st, st->size + 2) = CANARY_SPECIAL_NUMBER;
    st->size += 1;
#elif PROTECTION_LEVEL == HASH
    st->arr[ st->size ] = value;
    st->size += 1;

    makeApplyHash_(st);

#elif PROTECTION_LEVEL == FULL_PROTECTION
    *get_ELEM(st, st->size) = value;
    *(int64_t*)get_ELEM(st, st->size + 1) = CANARY_SPECIAL_NUMBER;
    st->size += 1;

    makeApplyHash_(st);
#endif
    my_ASSERT(st);
}

#if PROTECTION_LEVEL == 0
int top_(SafeStack* st) {
#else 
my_type top_(SafeStack* st, call_INFO) {
    my_ASSERT(st); 
#endif

    if(st->size == 0) return EMPTY_STACK_RETURN;

#if PROTECTION_LEVEL == NO_PROTECTION or PROTECTION_LEVEL == HASH
    return st->arr[st->size - 1];

#elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    return *get_ELEM(st, st->size);
    /*return st->arr[st->size];*/
#endif
}

#if PROTECTION_LEVEL == 0
void pop_(SafeStack* st) {
#else 
void pop_(SafeStack* st, call_INFO) {
    my_ASSERT(st); 
#endif
    
    if(st->size <= 0) return;

    --st->size;

#if PROTECTION_LEVEL == HASH
    makeApplyHash_(st);

#elif PROTECTION_LEVEL == CANARY
    //st->arr[ st->size + 1] = CANARY_SPECIAL_NUMBER;
    //*(stack) = *(stack + sizeof(uint64_t)) = CANARY_SPECIAL_NUMBER;
    *get_ELEM(st, st->size + 1) = CANARY_SPECIAL_NUMBER;

#elif PROTECTION_LEVEL == FULL_PROTECTION
    //st->arr[ st->size + 1] = CANARY_SPECIAL_NUMBER;
    *get_ELEM(st, st->size + 1) = CANARY_SPECIAL_NUMBER;
    makeApplyHash_(st);
#endif

    return;
}

#if PROTECTION_LEVEL == 0
void freeStack_(SafeStack* st) {
#else 
void freeStack_(SafeStack* st, call_INFO) {
    my_ASSERT(st);
#endif
    
    #if PROTECTION_LEVEL != NO_PROTECTION 
        st->size = -1;

        //#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        //    memset(st->arr, 0xcdcd, st->capacity + 2);
        //#else
        //    memset(st->arr, 0xcdcd, st->capacity);
        //#endif

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
    if (st->arr == (my_type*)NULL_SPECIAL_PTR) { st->arr_hash = 123; } else
      { st_hashes->arr_hash  = hashFunc_((const char*) (st->arr         ), sizeof(st->size)             , 0); }
        st_hashes->hash      = hashFunc_((const char*) (&(st->data_hash)), sizeof(st->data_hash) * 2    , 0);
#else
        st_hashes->data_hash = hashFunc_((const char*) (&(st->f_canary)) , size_t(&(st->s_canary)) - size_t(&(st->f_canary)) + sizeof(int), 0);
    if (st->arr == (my_type*)NULL_SPECIAL_PTR) { st->arr_hash = 123; } else
      { st_hashes->arr_hash  = hashFunc_((const char*) (st->arr     )    , sizeof(st->size + 2 )                 , 0); }
        st_hashes->hash      = hashFunc_((const char*) (&(st_hashes->data_hash)), sizeof(st_hashes->data_hash) * 2             , 0);
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
void resize_(SafeStack * st, int n_capacity) {
#else
int resize_(SafeStack* st, int n_capacity, call_INFO) {    
    my_ASSERT(st);
#endif

    if(n_capacity < 0) return -1;
    
    if(n_capacity > st->capacity) {

    #if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == NO_PROTECTION
        my_type* buff = (my_type*) realloc(st->arr, n_capacity * sizeof(my_type));

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;

            #if PROTECTION_LEVEL == HASH
                makeApplyHash_(st);
            #endif

            return 1;

        } else {
            return 0;
        }

    #elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        my_type* buff = (my_type*) realloc(st->arr, n_capacity * sizeof(my_type) + sizeof(uint64_t) * 2);
        /*int* buff = (int*) realloc(st->arr, (n_capacity + 2) * sizeof(*st->arr));*/

        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            *get_ELEM(st, st->size + 1) = CANARY_SPECIAL_NUMBER;
            //st->arr[st->size + 1] = CANARY_SPECIAL_NUMBER;
            #if PROTECTION_LEVEL == FULL_PROTECTION
                makeApplyHash_(st);
            #endif

        } else {
            return 0;
        }
    #endif
    } else if (n_capacity < st->capacity) {

    #if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == NO_PROTECTION
        my_type* buff = (my_type*) realloc(st->arr, n_capacity * sizeof(my_type));
        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            st->size = n_capacity;

            #if PROTECTION_LEVEL == HASH
                makeApplyHash_(st);
            #endif
            return 1;

        } else {
            return 0;
        }

    #elif PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        //int* buff = (int*) realloc(st->arr, (n_capacity + 2) * sizeof(*st->arr));
        my_type* buff = (my_type*) realloc(st->arr, n_capacity * sizeof(my_type) + sizeof(uint64_t) * 2);
        if(buff != NULL){
            st->arr = buff;
            st->capacity = n_capacity;
            st->size = n_capacity;

            *(int64_t*)get_ELEM(st, st->capacity) = CANARY_SPECIAL_NUMBER;
            //st->arr[st->capacity + 1] = CANARY_SPECIAL_NUMBER;

            #if PROTECTION_LEVEL == FULL_PROTECTION
                makeApplyHash_(st);
            #endif

        } else {
            return 0;
        }
    #endif
    }
   
    return 1;
}



#if PROTECTION_LEVEL != NO_PROTECTION
    #define INCORRECT 1
void fillStats(SafeStackStats* stats, int prototype) {

    if(prototype & (1 << 0)) stats->ptr_ch      = INCORRECT; 
    
    if(prototype & (1 << 1)) stats->size_ch     = INCORRECT;
    if(prototype & (1 << 2)) stats->capacity_ch = INCORRECT;
    if(prototype & (1 << 3)) stats->arr_ch      = INCORRECT;
    if(prototype & (1 << 4)) stats->size_cap_ch = INCORRECT;
    
#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    if (prototype & (1 << 5)) stats->hash_ch      = INCORRECT;
    if (prototype & (1 << 6)) stats->arr_ch       = INCORRECT;
    if (prototype & (1 << 7)) stats->hash_data_ch = INCORRECT;
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    if(prototype & (1 << 8))  stats->f_canary_ch     = INCORRECT;
    if(prototype & (1 << 9))  stats->s_canary_ch     = INCORRECT;
    if(prototype & (1 << 10)) stats->arr_f_canary_ch = INCORRECT;
    if(prototype & (1 << 11)) stats->arr_s_canary_ch = INCORRECT;
#endif   
    return;
}
    #undef INCORRECT
#endif





#if PROTECTION_LEVEL != NO_PROTECTION
int is_not_valid_(SafeStack* stack) {
    int ret = 0;
    if(stack == NULL) { 
        ret |= (1 << 0); 
        return ret;
    }
    
    if(stack->size < 0)               ret |= (1 << 1);
    if(stack->capacity < 0)           ret |= (1 << 2);
    if(stack->capacity < stack->size) ret |= (1 << 3);
    if(stack->arr == 0)            {  ret |= (1 << 4); return ret; }
    
#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    SafeStackHashes* st_hash = makeHash_(stack);
    if (stack->hash != st_hash->hash)           ret |= (1 << 5);
    if (stack->arr_hash != st_hash->arr_hash)   ret |= (1 << 6);
    if (stack->data_hash != st_hash->data_hash) ret |= (1 << 7);
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    if(stack->f_canary != CANARY_SPECIAL_NUMBER)             ret |= (1 << 8);
    if(stack->s_canary != CANARY_SPECIAL_NUMBER)             ret |= (1 << 9);
    printf("f_arr caaaanary %x\n\n", *(int64_t*)(stack->arr));
    if(*(int64_t*)(stack->arr) != CANARY_SPECIAL_NUMBER)               ret |= (1 << 10);
    if(*(int64_t*)get_ELEM(stack, stack->size) != CANARY_SPECIAL_NUMBER) ret |= (1 << 11);
#endif
    return ret;
}
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
void my_assert_(SafeStack* ptr, const char* var_name,  const char* low_function_caller_source, const char* low_function_caller, int assert_line, call_INFO, const char* st_type) {
    int ret_val = is_not_valid_(ptr);
    if(ret_val) {
        SafeStackStats* stats = (SafeStackStats*) calloc(1, sizeof(SafeStackStats));
        fillStats(stats, ret_val);
        Dump_stack_(ptr, stats, var_name, assert_line, 
                    low_function_caller, low_function_caller_source, 
                    caller_func_source, caller_func, call_line, 
                    type_name_);
        assert(0 && "stack validation error: check log file");
    }
    return;
}
#endif







void Dump_stack_(SafeStack* st, 
                SafeStackStats* stat, 
                const char* var_name, 
                int assert_line, 
                const char* low_function_caller,
                const char* low_function_caller_source,
                const char* caller_func_source, 
                const char* caller_func, 
                int call_line, 
                const char* st_type ) {
    static const char* ok_message = "ok";
    static const char* error_message = "ERROR";
    printf("stack creation line: %d\n", st->info->call_line);
    printf("stack creation func: %s\n", st->info->caller_func);
    printf("stack creation file: %s\n", st->info->caller_func_source);

    printf("\n\n");
    printf("inp_args:\n");
    printf("var_name: %s\n", var_name);
    printf("assert_line: %d\n", assert_line);
    printf("low_function_caller: %s\n", low_function_caller);
    printf("caller_func: %s\n", caller_func);
    printf("caller_func_source: %s\n", caller_func_source);
    printf("call_line: %d\n", call_line);
    printf("st_type: %s\n", st_type);
    printf("\n\n");
    
    if(stat->ptr_ch) {
        printf("Stack<%s> \"%s\" ptr is NULL in \n"
           "\t %s() at %s(%d)\n", type_name_, var_name, low_function_caller, caller_func_source, st->info->caller_func_source, st->info->call_line);
        printf("Stack<%s> \"%s\" ptr is NULL in \n"
           "\t %s() at %s(%d)\n", type_name_, var_name, low_function_caller, caller_func_source, st->info->caller_func_source, st->info->call_line);

        return;
    }

    printf("Stack<%c> [%p] created at \n"
           "\t %s() at %s(%d)\n", type_name_, st, st->info->caller_func, st->info->caller_func_source, st->info->call_line);
    
    printf("{\n");


#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    printf("\t\t hash      :\t%p (%s)\n", st->hash,    *(  stat->hash_ch == 0    ? ok_message : error_message));


    printf("\t\t array_hash:\t%p (%s)\n", st->arr_hash,  stat->hash_arr_ch == 0  ? "ok" : "ERROR");
    printf("\t\t data_hash :\t%p (%s)\n", st->data_hash, stat->hash_data_ch == 0 ? "ok" : "ERROR");
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    printf("\t\t first data canary : %d (%s)\n", st->hash,      stat->hash_ch == 0      ? "poison" : "ERROR");
    printf("\t\t second data canary: %d (%s)\n", st->arr_hash,  stat->hash_arr_ch == 0  ? "poison" : "ERROR");
#endif


}

