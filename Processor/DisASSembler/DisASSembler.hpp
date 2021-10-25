#include "../Shared/Shared.hpp"

static my_arr jmp_locations, mark_locations;

static const char* command_str_ptrs[CMD_MAX];
static int command_str_len[CMD_MAX];

void init_command_ptr();

void disassemble(FILE* input, FILE* output);

int fill_additional_data(MyString* program, MyString* program_label_counters);

void write_program_on_disk(MyString* program, MyString* program_label_counters, FILE* output);

int get_command_len(MyString* string, int cur_ip);

void create_buff(MyString** string, int size);