#include "ASSembler.hpp"
#include <stdio.h>

int main() {
    init_commands_hashes();
    printf_commands_hashes();

    FILE* input = fopen("./ASSembler/input.txt", "r");
    FILE* output = fopen("output.txt", "wb");
    printf("%d %d", input, output);
    compile_program(input, output);
    fclose(input);
    fclose(output);

        printf("%ld \n\n", hashFunc_("PUSH", strlen("PUSH"), 0));
    MyString* str = (MyString*) calloc(1, sizeof(*str));
    char* st = (char*) calloc(10, sizeof(char));
    int nn;
    scanf("%10s%n", st, &nn);
    printf("%s   %d\n\n\n", st, nn);
    // st[0] = 'a';
    // st[1] = 'x';
    // st[2] = ' ';
    // st[3] = 'P';
    // st[4] = 'O';
    // st[5] = 'P';
    // st[6] = ' ';
    // st[7] = 'O';
    // st[8] = 'P';
    // st[9] = ' ';
    str->begin = st;
    str->size = strlen(st);
    size_t off = 0;
    command_args* arg = fill_command_arg(str, &off);
    printf("\n lex  %cx : %d   %d\n\n", char(arg->reg_num + 'a'), arg->constant, arg->reg_num);
    printf("%d flags", arg->flags);
    
    return 0;
}