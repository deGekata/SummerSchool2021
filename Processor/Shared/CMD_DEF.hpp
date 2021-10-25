DEF_CMD(HLT, 0, 1, !(empty ^ flags), 
{ 
    printf("chel....");
    printf("yep top: %d", top_(invoker->stk));

    exit(0);
})

DEF_CMD(PUSH, 1, 1, !((mem | reg | immediate_constant) ^ flags) || 
                    !((mem | reg) ^ flags)                      || 
                    !(reg ^ flags)                              || 
                    !((mem | immediate_constant) ^ flags)       ||
                    !((reg | immediate_constant) ^ flags)       ||
                    !(immediate_constant ^ flags)               ||
                    !(reg ^ flags),
{  
    printf("laki %hhu \n\n", Cmd);
    invoker->ip++;
    int ptr = 0;
    if(Cmd & reg) {
        ptr += reg[invoker->code + invoker->ip];
        printf("cur ptr: %s\n", ptr);
        invoker->ip++;
    }

    if(Cmd & immediate_constant) {
        ptr +=  *(int*)(invoker->code + invoker->ip);
        invoker->ip += sizeof(int);
    }

    if(Cmd & mem) {
        ptr =  ((int*)(invoker->memory))[ptr];
    }

    push_(invoker->stk, ptr);

})


DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                   !((mem | reg) ^ flags)                      || 
                   !(reg ^ flags)                              || 
                   !((mem | immediate_constant) ^ flags)       ||
                   !(reg ^ flags)                              ||
                   !(empty ^ flags),
{
})

DEF_CMD(ADD, 3, 1, !(empty ^ flags),
{
    push_(invoker->stk, pop_(invoker->stk) + pop_(invoker->stk)); 
    invoker->ip++;
    printf("addd");
})

DEF_CMD(SUB, 4, 1, !(empty ^ flags), {
    push_(invoker->stk, pop_(invoker->stk) - pop_(invoker->stk)); 
    invoker->ip++;
})

DEF_CMD(MUL, 5, 1, !(empty ^ flags), {
    push_(invoker->stk, pop_(invoker->stk) * pop_(invoker->stk)); 
    invoker->ip++;
})


DEF_CMD(CALL, 6, 1, !(mark ^ flags), { 
    push_(invoker->stk, invoker->ip);
    invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JMP, 7, 1, !(mark ^ flags), { 
    invoker->ip = *(int*)(invoker->memory + ip + 1);
})


DEF_CMD(JE, 8, 1, !(mark ^ flags), {
    if ( pop_(invoker->stk) == pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JNE, 9, 1, !(mark ^ flags), { 
    if ( pop_(invoker->stk) != pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JG, 10, 1, !(mark ^ flags), { 
    if ( pop_(invoker->stk) > pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JGE, 11, 1, !(mark ^ flags), { 
    if ( pop_(invoker->stk) >= pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JL, 12, 1, !(mark ^ flags), { 
    if ( pop_(invoker->stk) < pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(JLE, 13, 1, !(mark ^ flags), { 
    if ( pop_(invoker->stk) <= pop_(invoker->stk ))
        invoker->ip = *(int*)(invoker->memory + ip + 1);
})

DEF_CMD(RET, 14, 1, !(empty ^ flags), { 
    
        invoker->ip = pop_(invoker->stk);
})


DEF_CMD(IN, 15, 1, !(empty ^ flags), { 
})

DEF_CMD(OUT, 16, 1, !(empty ^ flags), { 
})

DEF_CMD(STR_OUT, 17, 1, !(mark ^ flags), { 
})

DEF_CMD(DB, 18, 1, !(flags), { 
})




