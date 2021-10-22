DEF_CMD(HLT, 0, 1, empty, { 
    push(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(PUSH, 1, 1, immediate_constant | reg | mem,{ 
    push(&stk, get_arg(code[ip + 1])); 
})


DEF_CMD(POP, 2, 1, immediate_constant | reg | mem | empty,{ 
    pop(&stk, get_arg(code[ip + 1])); 
})

DEF_CMD(JMP, 3, 1, mark, { 
    pop(&stk, get_arg(code[ip + 1])); 
})


