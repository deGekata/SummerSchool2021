/*!
 * \file StringSorter.h
 * \author Gekata
 * \brief Sorts poem
 */

#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include "StringFileParser.h"


/*!
 * \brief get symbol on position pos from inp
 */
char* getSym (MyStrPair* inp, int pos);

/*!
 * \brief Reversed comparator for strings
 */
int comparatorReversed (const void* lhs, const void* rhs);

/*!
 * \brief Straight comparator for strings
 */
int comparatorStraight (const void* lhs, const void* rhs);

/*!
 * \brief Magicaly prints Poem 3 times
 * \details Firstly prints straight-sorted, secondly prints reverse-sorted, finaly prints source text
 */
void makeMagicPrint(FILE* fp_in, FILE* fp_out);





