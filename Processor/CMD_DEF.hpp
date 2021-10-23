DEF_CMD(HLT, 0, 1, ~empty & flags, { //emtpty 
    push(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(PUSH, 1, 1, ~(mem | reg | immediate_constant) & flags,
{  //immediate_contant | reg | mem
    push(&stk, get_arg(code[ip + 1])); 
})


DEF_CMD(POP, 2, 1, (~(mem | reg | immediate_constant) & flags) || 
                      (~(mem | reg) & flags)                   || 
                      (~reg & flags)                           || 
                      (~(mem | immediate_constant) & flags)  ,
{
    pop(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(JMP, 3, 1, mark, { 
    pop(&stk, get_arg(code[ip + 1])); 
})


