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
struct MyStrPair{
    char* begin;
    char* r_begin;
};

/*!
 * \brief Container for MyStrPair
 */
struct MyStrPairArr{
    MyStrPair* p;
    int len;
};

/*!
 * \brief reads Poem from inp to buff, returns pointers to strings from buff
 */
MyStrPairArr* readPoem (FILE* inp, char** buff);
