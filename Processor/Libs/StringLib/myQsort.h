/*!
 * \file myQsort.h
 * \author Gekata
 * \brief Custom qsort and memSwap
 */

#pragma once
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*!
 * \brief Basic qSort
 */
void myQsort (void* _Base, 
              size_t _NumOfElements, 
              size_t _SizeOfElements, 
              int _CompareFunction(void const*, void const*));
  
/*!
* \brief swaps bytes between p1 and p2 pointers
*/
void memSwap(void* p1, void* p2, size_t bytes);