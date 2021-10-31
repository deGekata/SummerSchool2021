#include "StringFileParser.h"


int getFileSize (FILE* inp) {
    assert(inp);
    fseek(inp, 0L, SEEK_END);
    int size = ftell(inp);
    fseek(inp, 0L, SEEK_SET);
    return size;
    // struct stat file_stat_buff;
    // fstat (_fileno (inp), &file_stat_buff); //-
    // return file_stat_buff.st_size;
}

char* createFileBuff (size_t file_size) {
    return ( char* ) calloc (file_size + 2, sizeof (char));
}


//TODO skip_item
int countLines (char* text, size_t file_size, char delimiter, char skip_item) {
    assert(text);

    skip_item = skip_item;
    int cnt = 0;

    for (size_t it = 0; it < file_size + 1; ++it) {

        if ( text[it] == delimiter ) {
            text[it] = '\0';
        }

        if ( text[it] == '\0' ) {
            cnt += 1;
        }

    }    

    return cnt - 1;
}

Text* readFromFile (FILE* inp, char delimiter, char skip_item) {
    assert(inp);

    //TODO delimiter
    delimiter = delimiter;
    if(skip_item == '\0') return NULL;

    Text* text = (Text*) calloc(1, sizeof(Text));

    fillText(text, inp, skip_item);

    return text;
}

void buildStrPointers (Text* text, char skip_item) {
    assert(text);

    int string_len = 0, offset = 1;

    MyString* strings = (MyString*) calloc (text->lines_cnt, sizeof(MyString));

    for (size_t it = 0; it < text->lines_cnt; ++it) {

        while ( text->raw_line[offset + string_len] != '\0' && 
                text->raw_line[offset + string_len] !=  skip_item) {                    
                    string_len += 1;
        }

        strings[ it ].begin = text->raw_line + offset;
        strings [ it ].size = string_len;
        offset = offset + string_len;

        if (text->raw_line[offset] == skip_item) {
            
            text->raw_line[offset] = '\0';
            ++offset;

            while ( text->raw_line[offset] != '\0') {
                ++offset;
            }

        }

        ++offset;
        string_len = 0;

    }

    text->strings = strings;

}

void fillText (Text* text, FILE* inp, char skip_item) {
    assert(inp);
    assert(text);
    text->text_len = getFileSize (inp);

    text->raw_line = createFileBuff (text->text_len);
    fread (text->raw_line + 1, sizeof(char), text->text_len, inp);

    if (text->raw_line[text->text_len + 1] != '\n') {
        text->raw_line[text->text_len + 1] = '\n';
        text->text_len += 1;
    }
    text->lines_cnt = countLines(text->raw_line, text->text_len);

    buildStrPointers(text, skip_item);
}

void destructor(Text* text) {
    assert(text);

    free(text->strings);
    free(text->raw_line);

    text->strings  = NULL;
    text->raw_line = NULL;
}