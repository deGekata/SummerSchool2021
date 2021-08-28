#pragma once
#include "StringFileParser.h"


int getFileSize (FILE* inp) {
    assert(inp);

    struct stat file_stat_buff;
    fstat (_fileno (inp), &file_stat_buff); //-
    return file_stat_buff.st_size;
}

char* createFileBuff (size_t file_size) {
    return ( char* ) calloc (file_size + 2, sizeof (char));
}

int countLines (char* text, size_t file_size) {
    assert(text);

    int cnt = 0;

    for (size_t it = 0; it < file_size + 1; ++it) {

        if ( text[it] == '\n' ) {
            text[it] = '\0';
        }

        if ( text[it] == '\0' ) {
            cnt += 1;
        }

    }    

    return cnt;
}

Text* readPoem (FILE* inp) {
    assert(inp);

    Text* text = (Text*) calloc(1, sizeof(Text));
    fillText(text, inp);

    return text;
}

void buildStrPointers (Text* text) {
    assert(text);

    int string_len = 1, offset = 1;
    string_len = 0;
    MyStrPair* strings = (MyStrPair*) calloc (text->lines_cnt, sizeof(MyStrPair));

    for (int it = 0; it < text->lines_cnt; ++it) {

        while ( text->raw_line[offset + string_len] != '\0' ) string_len += 1;
       
        strings[ it ].begin = text->raw_line + offset;
        strings [ it ].r_begin = text->raw_line + offset + string_len - 1;

        offset = offset + string_len + 1;
        string_len = 0;

    }

    text->strings = strings;

}

void fillText (Text* text, FILE* inp) {
    assert(inp);
    assert(text);
    text->text_len = getFileSize (inp);

    text->raw_line = createFileBuff (text->text_len);

    fread (text->raw_line + 1, sizeof(char), text->text_len, inp);

    text->lines_cnt = countLines(text->raw_line, text->text_len);

    buildStrPointers(text);
}

void destructor(Text* text) {
    assert(text);

    free(text->strings);
    free(text->raw_line);

    text->strings  = NULL;
    text->raw_line = NULL;
}