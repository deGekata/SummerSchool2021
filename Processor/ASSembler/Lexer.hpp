#include "../Libs/StringLib/StringFileParser.h"
#include "string.h"
#include <inttypes.h>

const uint8_t immediate_constant  = (uint8_t)1 << 5;
const uint8_t reg                 = (uint8_t)1 << 6;
const uint8_t mem                 = (uint8_t)1 << 7;

#define DEF_CMD(cmd, NUM, ARGS_CUNT, code) \
    CMD_ ## cmd = NUM,

enum Commands {
    ERROR_CMD = -2,
    EMPTY_CMD = -1, 
    #include "../CMD_DEF.hpp"
    CMD_MARK,
    CMD_MAX
};
#undef DEF_CMDx

enum Registers {
    no_reg = -1,
    ax,
    bx,
    cx,
    dx
};


struct command_args {
    int64_t reg_num;
    int64_t constant;
    uint8_t flags;
};


void init_commands_hashes();

void printf_commands_hashes();

int64_t hashFunc_(const char* str, size_t len, int64_t init = 0);

inline bool is_delimiter(char elem);



int64_t get_command_id(MyString* string, size_t* offset);

command_args* fill_command_arg(MyString* string, size_t* offset);

/*
/brief Parsing lexems
*/
// Text* parseLexems(FILE* input, char comment_symbol);

size_t skip_delimiters(MyString* string, size_t offset);

size_t get_lexem_offset(MyString* string, size_t offset);




