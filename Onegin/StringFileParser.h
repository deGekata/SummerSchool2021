/*!
 * \file StringFileParser.h
 * \author Gekata
 * \brief Parses poem from file
 */

#pragma once
#include <stdlib.h>
#include <assert.h>
#include <sys\stat.h>
#include <stdio.h>

/*!
 * \brief struct with pointers to begin and r_begin
 */
struct MyStrPair {
    char* begin;
    char* r_begin;
};

/*!
 * \brief container for text string
 */
struct Text {
    MyStrPair* strings;
    size_t lines_cnt;
    size_t text_len;
    char* raw_line;
};

/*!
 * \brief reads Poem from inp to buff, returns pointers to strings from buff
 */
Text* readPoem (FILE* inp);

/*!
 * \brief Get file size from file properties
 */
int getFileSize (FILE* inp);

/*!
 * \brief creates special format buffer for Text 
 */
char* createFileBuff (size_t file_size);

/*!
 * \brief count lines from text and replaces \n with \0
 */
int countLines (char* text, size_t file_size);

/*!
 * \brief Builds String pointers for Text.strings field
 */
void buildStrPointers (Text* text);

/*!
 * \brief constructor for Text from inp file
 */
void fillText (Text* text, FILE* inp);


void destructor(Text* text);
