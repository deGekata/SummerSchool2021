DEF_CMD(HLT, 0, 1, !(empty ^ flags), 
{ 
    push(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(PUSH, 1, 1, !((mem | reg | immediate_constant) ^ flags) || 
                    !((mem | reg) ^ flags)                      || 
                    !(reg ^ flags)                              || 
                    !((mem | immediate_constant) ^ flags)       ||
                    !((reg | immediate_constant) ^ flags)       ||
                    !(immediate_constant ^ flags)               ||
                    !(reg ^ flags),
{  //immediate_contant | reg | mem
    push(&stk, get_arg(code[ip + 1])); 
})


DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                   !((mem | reg) ^ flags)                      || 
                   !(reg ^ flags)                              || 
                   !((mem | immediate_constant) ^ flags)       ||
                   !(reg ^ flags)                              ||
                   !(empty ^ flags),
{
    pop(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(ADD, 3, 1, !(empty ^ flags),
{
    pop(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(SUB, 4, 1, !(empty ^ flags),
{
    pop(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(MUL, 5, 1, !(empty ^ flags),
{
    pop(&stk, get_arg(code[ip + 1])); 
})




DEF_CMD(JMP, 6, 1, !(mark ^ flags), { 
    pop(&stk, get_arg(code[ip + 1])); 
})


