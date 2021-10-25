#include <inttypes.h>
#include <string.h>
#include "../Libs/StringLib/StringFileParser.h"

#define WIDTH 400
#define HEIGHT 300
#define MAX_GPU_MEM_SIZE WIDTH * HEIGHT

#define MAX_RAM_SIZE 3000

const uint8_t empty               = (uint8_t)1 << 3;
const uint8_t mark                = (uint8_t)1 << 4;
const uint8_t immediate_constant  = (uint8_t)1 << 5;
const uint8_t reg                 = (uint8_t)1 << 6;
const uint8_t mem                 = (uint8_t)1 << 7;

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    CMD_ ## cmd = NUM,

enum Commands {
    ERROR_CMD = -2,
    EMPTY_CMD = -1, 
    #include "CMD_DEF.hpp"
    CMD_MARK,
    CMD_MAX
};
#undef DEF_CMD

enum Registers {
    no_reg = -1,
    ax,
    bx,
    cx,
    dx
};

struct command_args {
    int8_t reg_num;
    int32_t constant;
    uint8_t flags;
    MyString* mark_name;
};

struct label_struct {
    size_t location;
    int64_t hash;
};

struct my_arr {
    label_struct* data;
    size_t size;
    size_t capacity;
};

void extend_my_arr(my_arr* arr);

int64_t hashFunc(const char* str, size_t len, int64_t init = 0);

bool is_control_transfer(int command_id);