/*!
 * \file StringFileParser.h
 * \author Gekata
 * \brief Parses text from file
 */

#include <stdlib.h>
#include <assert.h>
// #include <sys\stat.h>
#include <stdio.h>

/*!
 * \brief struct with pointers to begin and size
 */
struct MyString {
    char* begin;
    size_t size;
};

/*!
 * \brief container for text string
 */
struct Text {
    MyString* strings;
    size_t lines_cnt;
    size_t text_len;
    char* raw_line;
};

/*!
 * \brief reads Poem from inp to buff, returns pointers to strings from buff
 */
Text* readFromFile (FILE* inp,  char delimiter='\n', char skip_item = '\n');

/*!
 * \brief Get file size from file properties
 */
int getFileSize (FILE* inp);

/*!
 * \brief creates special format buffer for Text 
 */
char* createFileBuff (size_t file_size);

/*!
 * \brief count lines from text and replaces 'delimiter' with \0
 */
int countLines (char* text, size_t file_size, char delimiter ='\n', char skip_item = '\n');

/*!
 * \brief Builds String pointers for Text.strings field
 */
void buildStrPointers (Text* text, char skip_item = '\n');

/*!
 * \brief constructor for Text from inp file
 */
void fillText (Text* text, FILE* inp, char skip_item = '\n');


void destructor(Text* text);
