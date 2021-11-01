#ifndef PROCESSOR_DISASSEMBLER_DISASSEMBLER
#define PROCESSOR_DISASSEMBLER_DISASSEMBLER

#include "../Shared/Shared.hpp"


void init_command_ptr();

void disassemble(FILE* input, FILE* output);

int fill_additional_data(MyString* program, MyString* program_label_counters);

void write_program_on_disk(MyString* program, MyString* program_label_counters, FILE* output);

size_t get_command_len(MyString* string, size_t cur_ip);

void create_buff(MyString** string, size_t size);

#endif
