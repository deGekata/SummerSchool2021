#include "Shared.hpp"

void extend_my_arr(my_arr* arr) {
    arr->capacity = arr->capacity * 2;
    arr->data = (label_struct*) realloc(arr->data, arr->capacity * sizeof(label_struct));
    return;
}

int64_t hashFunc_(const char * str, size_t len, int64_t init) {
    unsigned long long int hash = init;
    for (size_t it = 0; it < len; str++, it++) {
        hash += (unsigned char)(*str);
        hash += (hash << 20);
        hash ^= (hash >> 12);
    }

    hash += (hash << 6);
    hash ^= (hash >> 22);
    hash += (hash << 29);

    return hash;
}

bool is_control_transfer(int command_id) {
    return (command_id == CMD_JMP)  ||
           (command_id == CMD_JE)   ||
           (command_id == CMD_JNE)  ||
           (command_id == CMD_JG)   ||
           (command_id == CMD_JGE)  ||
           (command_id == CMD_JL)   ||
           (command_id == CMD_JLE)  ||
           (command_id == CMD_CALL);
}