#include "DSL_DEF.hpp"

DEF_CMD(HLT, 0, 1, !(empty ^ flags), 
{ 
    printf("chel....");
    // printf("yep top: %d", top_(invoker->stk));
    return 0;
    
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
    
    PARSE_PUSH_ARG_(ptr);
    PUSH_(ptr);
    return 1;
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
    POP_(TEMP1);
    POP_(TEMP2);
    PUSH_(TEMP1 + TEMP2);
    invoker->ip++;
    return 1;
})

DEF_CMD(SUB, 4, 1, !(empty ^ flags), {
    POP_(TEMP1);
    POP_(TEMP2);
    PUSH_(TEMP1 - TEMP2);
    invoker->ip++;
    return 1;
})

DEF_CMD(MUL, 5, 1, !(empty ^ flags), {
    POP_(TEMP1);
    POP_(TEMP2);
    PUSH_(TEMP1 * TEMP2);
    invoker->ip++;
    return 1;
})

DEF_CMD(DIV, 6, 1, !(empty ^ flags), {
    POP_(TEMP1);
    POP_(TEMP2);
    PUSH_(TEMP1 - TEMP2);
    invoker->ip++;
    return 1;
})

DEF_CMD(CALL, 7, 1, !(mark ^ flags), { 
    CALL_();
    return 1;
})

DEF_CMD(JMP, 8, 1, !(mark ^ flags), { 
    JMP_();
    return 1;
})


DEF_CMD(JE, 9, 1, !(mark ^ flags), {
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, ==);
    return 1;
})

DEF_CMD(JNE, 10, 1, !(mark ^ flags), { 
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, !=);
    return 1;
})

DEF_CMD(JG, 11, 1, !(mark ^ flags), { 
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, >);
    return 1;
})

DEF_CMD(JGE, 12, 1, !(mark ^ flags), { 
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, >=);
    return 1;
})

DEF_CMD(JL, 13, 1, !(mark ^ flags), { 
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, <);
    return 1;
})

DEF_CMD(JLE, 14, 1, !(mark ^ flags), { 
    POP_(TEMP1);
    POP_(TEMP2);
    
    JMP_COND(TEMP1, TEMP2, <=);
    return 1;
})

DEF_CMD(RET, 15, 1, !(empty ^ flags), { 
        RET_();
        return 1;
})


DEF_CMD(IN, 16, 1, !(empty ^ flags), {
    IN_(num);
    PUSH_(num);
    return 1;
})

DEF_CMD(OUT, 17, 1, !(empty ^ flags), { 
    POP_(TEMP1);
    OUT_(TEMP1);
    invoker->ip++;
    return 1;
})

DEF_CMD(STR_OUT, 18, 1, !(mark ^ flags), { 
    STR_OUT_();
    return 1;
})

DEF_CMD(DB, 19, 1, !(flags), { 
    DB_();
    return 1;
})






