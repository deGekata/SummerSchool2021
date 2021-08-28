/*!
 * \file Solver.h
 * \author Gekata
 * \brief Parses poem from file
 */

#pragma once
#include "StringFileParser.h"

MyStrPairArr* readPoem (FILE* inp, char** buff) {
    assert(inp);

    struct stat file_stat_buff;
    fstat (_fileno (inp), &file_stat_buff);

    *buff = ( char* ) calloc (file_stat_buff.st_size + 2, sizeof (char));
    (*buff)[0] = '\0';

    fread (*buff + 1, sizeof(char), file_stat_buff.st_size, inp);

    int string_len = 1, cnt = 0, offset = 0;

    for (int it = 0; it < file_stat_buff.st_size + 1; ++it) {

        if ((*buff)[it] == '\n') {
            (*buff)[it] = '\0';
        }
        if ((*buff)[it] == '\0') {
            cnt += 1;
        }

    }    
    (*buff)[file_stat_buff.st_size + 1] = '\0';

    offset = 1;
    string_len = 0;
    MyStrPair* strings = (MyStrPair*) calloc (cnt, sizeof(MyStrPair));

    for (int it = 0; it < cnt; ++it) {

        while ( (*buff)[offset + string_len] != '\0' ) string_len += 1;
       
        strings[ it ].begin = *buff + offset;
        strings [ it ].r_begin = *buff + offset + string_len - 1;

        offset = offset + string_len + 1;
        string_len = 0;

    }

    MyStrPairArr* res = (MyStrPairArr*) calloc (1, sizeof(MyStrPairArr));
    res->p = strings;
    res->len = cnt;

    return res;
}

