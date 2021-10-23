#include "ASSembler.hpp"
#include <stdio.h>


#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    !(ARGS_TYPE)

int main() {
    init_commands_hashes();
    printf_commands_hashes();

    // FILE* input = fopen("./ASSembler/input.txt", "r");
    // FILE* output = fopen("output.txt", "wb");
    // printf("%d %d", input, output);
    // compile_program(input, output);
    // fclose(input);
    // fclose(output);

    //     printf("%ld \n\n", hashFunc_("PUSH", strlen("PUSH"), 0));
    // MyString* str = (MyString*) calloc(1, sizeof(*str));
    // char* st = (char*) calloc(10, sizeof(char));
    // int nn;
    // scanf("%10s%n", st, &nn);
    // printf("%s   %d\n\n\n", st, nn);
    // // st[0] = 'a';
    // // st[1] = 'x';
    // // st[2] = ' ';
    // // st[3] = 'P';
    // // st[4] = 'O';
    // // st[5] = 'P';
    // // st[6] = ' ';
    // // st[7] = 'O';
    // // st[8] = 'P';
    // // st[9] = ' ';
    // str->begin = st;
    // str->size = strlen(st);
    // size_t off = 0;
    // command_args* arg = fill_command_arg(str, &off);
    // printf("\n lex  %cx : %d   %d\n\n", char(arg->reg_num + 'a'), arg->constant, arg->reg_num);
    // printf("%d flags", arg->flags);
    int8_t flags = reg | mem;
    printf("flags:%hu check res: %hu", flags, DEF_CMD(POP, 2, 1, (~(mem | reg | immediate_constant) & flags) || 
                      (~(mem | reg) & flags)                   || 
                      (~reg & flags)                           || 
                      (~(mem | immediate_constant) & flags)  ,
{
    pop(&stk, get_arg(code[ip + 1])); 
}));

    
    return 0;
}