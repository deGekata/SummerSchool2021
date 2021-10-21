#include "Lexer.hpp"
#include <string.h>
// #include "../config.hpp"

struct CommandParams {
    int command_id;
    int command_args_cnt;
};

MyString* compile_program(Text* text, FILE* out_file);

MyString* decode_lexems(Text* text);

void write_programm_on_disk(MyString* program, FILE* out_file);

//TODO
void fill_command_params(CommandParams* params, MyString* str, size_t begin, size_t end);

//TODO
bool is_arg_valid(MyString* str, size_t begin, size_t end);

//TODO
void write_command(MyString* str, size_t begin, size_t end, size_t buff_offset);


//TODO
void write_param(MyString* str, size_t begin, size_t end, size_t buff_offset);