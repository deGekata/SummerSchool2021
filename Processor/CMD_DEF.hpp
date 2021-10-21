DEF_CMD(PUSH, 1, 1, { 
    push(&stk, get_arg(code[ip + 1])); 
})


DEF_CMD(POP, 2, 1, { 
    pop(&stk, get_arg(code[ip + 1])); 
})


