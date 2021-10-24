#include "Shared.hpp"

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

void extend_my_arr(my_arr* arr) {
    arr->capacity = arr->capacity * 2;
    arr->data = (label_struct*) realloc(arr->data, arr->capacity * sizeof(label_struct));
    return;
}