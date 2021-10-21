#include "myQsort.h"

void myQsort (void* _Base, 
              size_t _NumOfElements, 
              size_t _SizeOfElements, 
              int _CompareFunction(void const*, void const*)) 
{
    assert( _Base );

    if ( _NumOfElements <= 1 ) return;

    int lhs = 0;
    int rhs = _NumOfElements - 1;
    int mid = _NumOfElements / 2;

    do {
        while ( _CompareFunction((char*)_Base + lhs * _SizeOfElements, (char*)_Base + mid * _SizeOfElements ) && lhs < _NumOfElements ) lhs++;
        while ( _CompareFunction((char*)_Base + mid * _SizeOfElements, (char*)_Base + rhs * _SizeOfElements)  && rhs > 0              ) rhs--;

        if (lhs <= rhs) {
            memSwap ((char*)_Base + lhs * _SizeOfElements, (char*)_Base + rhs * _SizeOfElements, _SizeOfElements);
            lhs++;
            rhs--;
        }

    } while ( lhs <= rhs );


    if (rhs > 0) {
        myQsort ( _Base, rhs + 1, _SizeOfElements, _CompareFunction );
    }

    if (lhs < _NumOfElements) {
        myQsort( (void*) ( (char*)_Base + lhs * _SizeOfElements ), _NumOfElements - lhs, _SizeOfElements, _CompareFunction );
    }

    return;
}

void memSwap(void* p1, void* p2, size_t bytes) {
    assert(p1);
    assert(p2);
    
    char* buff = (char*) calloc (bytes, sizeof(char));

    memcpy ( buff, p1, bytes );
    memcpy ( p1, p2, bytes );
    memcpy ( p2, buff, bytes );

    free(buff);
}

