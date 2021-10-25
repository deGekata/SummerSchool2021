#include "Lexer.hpp"
#include <string.h>
// #include "../config.hpp"


static my_arr jmp_locations, mark_locations;



bool compile_program(FILE* input_file, FILE* output_file);

MyString* encode_lexems(Text* text);

void write_programm_on_disk(MyString* program, FILE* out_file);

int find_label(int64_t hash);

void link_labels(MyString* program);

void parse_write_args(MyString* program,
                      int64_t   command,
                      int8_t    args_cunt, 
                      int8_t*   command_flags,
                      MyString* string, 
                      size_t*   offset,
                      size_t*   ip_offset);

bool is_args_mathing(int64_t command, uint8_t flags);

void write_command(MyString* programm, size_t prev_ip_command, int command_id, int8_t command_flags);

void write_args(MyString* programm, size_t* ip_offset, command_args* command_arg);

void add_mark(MyString* strings, size_t *offset, int ip_command);


