#define HLT_() return true;

#define PARSE_PUSH_ARG_(ptr)                                  \
    invoker->ip++;                                             \
    int ptr = 0;                                                \
    if (Cmd & reg) {                                             \
        ptr += invoker->regs[int(*(invoker->code + invoker->ip))];\
        invoker->ip++;                                             \
    }                                                               \
    if (Cmd & immediate_constant) {                                  \
        ptr +=  *(int*)(invoker->code + invoker->ip);                 \
        invoker->ip += sizeof(int);                                    \
    }                                                                   \
    if (Cmd & mem) {                                                     \
        ptr =  ((int*)(invoker->memory))[ptr];                            \
    }                                                        


#define PARSE_POP_ARG_(ptr)                                  \
    invoker->ip++;                                          \
    uint8_t cmd_ = invoker->code[invoker->ip - 1];\
    int num = 0;                                               \
    int* ptr;\
    if ((cmd_ & mem) != 0) {                                      \
        ptr = (int*)invoker->memory;                              \
        if (cmd_ & reg) {                                           \
            ptr += invoker->regs[*(invoker->code + invoker->ip++)]; \
        }                                                            \
        if (cmd_ & immediate_constant) {                               \
            ptr += *(int*)(invoker->code + invoker->ip);               \
            invoker->ip += 4;                                           \
        }                                                                \
    } else {                                                              \
        ptr = &invoker->regs[*(invoker->code + invoker->ip++)];            \
    }                                                                       \
                                                                             \
    if ((cmd_ & immediate_constant) != 0) {                                    \
        *ptr += immediate_constant;                                            \
    }





#define PUSH_(arg) push_(invoker->stk, arg)

#define POP_(arg)  int arg = pop_(invoker->stk)

// #define POP_()  pop_(invoker->stk)

#define CALL_()    push_(invoker->stk, invoker->ip + 5); invoker->ip = *(int*)(invoker->code + invoker->ip + 1);

#define JMP_() invoker->ip = *(int*)(invoker->code + invoker->ip + 1);

#define JMP_COND(arg1, arg2, cond)              \
    if ( (arg1) cond (arg2)){                    \
        JMP_();                                   \
    } else {                                       \
        invoker->ip += sizeof(char) + sizeof(int);  \
    }

#define RET_() \
    invoker->ip = pop_(invoker->stk);

#define IN_(num)                                                \
    int num;                                                     \
    if (scanf("%d", &num) == -1) {                                \
        assert(0 && "error for 'IN' command: incorrect number ");  \
    }

#define OUT_(num)       \
    printf("%d\n", num);

#define STR_OUT_() \
    printf("not implemented\n");


#define DB_() \
    printf("db not implemented");

