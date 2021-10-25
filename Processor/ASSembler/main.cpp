#include "ASSembler.hpp"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    (ARGS_TYPE)

int main(int argc, char* argv[]) {
    if(argc < 3) assert(0 && "Not enough args");

    init_commands_hashes();
    printf_commands_hashes();

    FILE* input = fopen(argv[1], "r");
    // int output = open("output.txt", O_RDWR, O_BINARY);
    FILE* output = fopen(argv[2], "w+");
    setvbuf( output, (char *)NULL, _IONBF, 0 );

    printf("program dir: %s\n\n", argv[0]);
    printf("%d %d", input, output);
    compile_program(input, output);
    fclose(input);
    fclose(output);
    return 0;

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
    uint8_t 

    // 00000000

    // 00011111
    // 00111111
    // 01011111

    // 11000000
    
    flags = reg;
    printf("flags = reg; flags:%hu check res: %hu\n",  flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = mem;
    printf("flags = mem; flags:%hu check res: %hu\n",  flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = immediate_constant;
    printf("flags = immediate_constant; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = mark;
    printf("flags = mark; flags:%hu check res: %hu\n",  flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = mem | reg;
    // 11000000

    // 11000000
    printf("flags = mem | reg; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = mem | immediate_constant;
    printf("flags = mem | immediate_constant; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));
    flags = reg | immediate_constant;
    printf("flags = reg | immediate_constant; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = reg | mem | immediate_constant;
    printf("flags = reg | mem | immediate_constant; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    flags = mark | reg | mem | immediate_constant;
    printf("flags = mark | reg | mem | immediate_constant; flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));
    
    flags = mark | reg | immediate_constant;
    printf(" flags = mark | reg | immediate_constant flags:%hu check res: %hu\n", flags, DEF_CMD(POP, 2, 1, !((mem | reg | immediate_constant) ^ flags) || 
                      !((mem | reg) ^ flags)                   || 
                      !(reg ^ flags)                           || 
                      !((mem | immediate_constant) ^ flags)    ||
                      !(reg ^ flags)                             ,));

    return 0;
}