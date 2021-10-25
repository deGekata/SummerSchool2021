#undef CANARY_SPECIAL_NUMBER

#undef BLOCK_SIZE

#undef REALLOC_BAR

#undef EMPTY_STACK_RETURN

#undef NULL_SPECIAL_PTR

#undef NO_PROTECTION

#undef CANARY

#undef HASH

#undef FULL_PROTECTION

#undef PROTECTION_LEVEL

#undef is_VALID

typedef int my_type;
static const char* type_name_ = "int";
static const char* log_file_location = "log.txt";
#define PRINTF_TYPE_SPEC "d"

#define EMPTY_STACK_RETURN     0xF2EE
#define NULL_SPECIAL_PTR      (int*)0xbad

#define CANARY_SPECIAL_NUMBER  0xFee1Dead

//const int no_protection = 0;
//const int canary = 1;
//const int hash = 2;
//const int full_protection = 3;
//const int protection_level = full_protection;

const int null_ptr_err     = (1 << 0);
const int size_err         = (1 << 1);
const int capacity_err     = (1 << 2);
const int size_cap_err     = (1 << 3);
const int arr_null_ptr_err = (1 << 4);
const int hash_err         = (1 << 5);
const int f_canary_err     = (1 << 6);
const int s_canary_err     = (1 << 7);
const int arr_f_canary_err = (1 << 8);
const int arr_s_canary_err = (1 << 9);

#define NO_PROTECTION    0
#define CANARY           1
#define HASH             2
#define FULL_PROTECTION  3

#define PROTECTION_LEVEL NO_PROTECTION               

#define is_NOT_VALID(ptr)   is_not_valid_(ptr)
#define my_ASSERT(ptr)      my_assert_(ptr, #ptr, __FILE__, __FUNCTION__, __LINE__, caller_func_source, caller_func, call_line, type_name_)
#define call_INFO           const char* caller_func_source, const char* caller_func, int call_line
#define call_ARGS           __FILE__, __FUNCTION__, __LINE__
#define get_ELEM(ptr, ind)  ((my_type*)((char*)((ptr)->arr) + sizeof(uint64_t)) + ind)

#if PROTECTION_LEVEL == 0
    #define createStack(st)             createStack_(st)
    #define pushStack(stack, value)     push_(stack, value)
    #define top(stack)                  top_(st)
    #define pop(stack)                  pop_(stack)
    #define freeStack(stack)            freeStack_(stack)
    #define resize(stack, n_capacity)   resize_(stack, n_capacity)
#else
    #define createStack(st)             createStack_(st,    call_ARGS)
    #define pushStack(st, value)        push_       (st, value, call_ARGS)
    #define top(st)                     top_        (st,    call_ARGS)
    #define pop(stack)                  pop_        (stack, call_ARGS)
    #define freeStack(stack)            freeStack_  (stack, call_ARGS)
    #define resize(stack, n_capacity)   resize_     (stack, n_capacity, call_ARGS)
#endif

