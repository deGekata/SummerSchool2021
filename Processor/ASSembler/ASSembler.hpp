#include "Lexer.hpp"
#include <string.h>
// #include "../config.hpp"


bool compile_program(FILE* input_file, FILE* output_file);

MyString* decode_lexems(Text* text);

void write_programm_on_disk(MyString* program, FILE* out_file);

bool is_args_mathing(int64_t command, uint8_t flags);

void write_command(MyString* programm, size_t prev_ip_command, int command_id, int8_t command_flags);

void write_args(MyString* programm, size_t* ip_offset, command_args* command_arg);

void parse_write_args(MyString* program,
                      int64_t   command,
                      int8_t    args_cunt, 
                      int8_t*   command_flags,
                      MyString* string, 
                      size_t*   offset,
                      size_t*   ip_offset);

// //TODO
// void fill_command_params(CommandParams* params, MyString* str, size_t begin, size_t end);

// //TODO
// bool is_arg_valid(MyString* str, size_t begin, size_t end);

// //TODO
// void write_command(MyString* str, size_t begin, size_t end, size_t buff_offset);


// //TODO
// void write_param(MyString* str, size_t begin, size_t end, size_t buff_offset);