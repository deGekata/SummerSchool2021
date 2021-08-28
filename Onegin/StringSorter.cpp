#include "StringFileParser.h"
#include "StringSorter.h"
#include "myQsort.h"

char* getSym (MyStrPair* inp, int pos) {
    if (pos < 0) {
       return  inp->r_begin + pos + 1;
    }

    return inp->begin + pos;
}


int comparatorReversed (const void* lhs, const void* rhs) {
    assert(lhs);
    assert(rhs);

    MyStrPair* l = (MyStrPair*) lhs;  
    MyStrPair* r = (MyStrPair*) rhs;

    int pos = -1;
    while ( *getSym (l, pos) != '\0' && *getSym (r, pos) != '\0') {
        if ( *getSym (l, pos) != *getSym (r, pos) ) 
            return *getSym (l, pos) < *getSym (r, pos);
        --pos;
    }

    return *getSym (l, pos) == '\0' && *getSym (r, pos) != '\0';  
}

int comparatorStraight (const void* lhs, const void* rhs) {
    assert(lhs);
    assert(rhs);

    MyStrPair* l = (MyStrPair*) lhs;  
    MyStrPair* r = (MyStrPair*) rhs;

    int pos = 0;
    while ( *getSym (l, pos) != '\0' && *getSym (r, pos) != '\0') {
        if ( *getSym (l, pos) != *getSym (r, pos) ) 
            return *getSym (l, pos) < *getSym (r, pos);
        ++pos;
    }
    
    return *getSym (l, pos) == '\0' && *getSym (r, pos) != '\0';  
}

void makeMagicPrint (FILE* fp_in, FILE* fp_out) {
    char* buff;
    MyStrPairArr* mas =  readPoem(fp_in, &buff);

    myQsort(mas->p, mas->len, sizeof(MyStrPair), comparatorStraight);

    for(int it = 0; it < mas->len; ++it){
        fprintf(fp_out, (mas->p + it)->begin);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");

    qsort(mas->p, mas->len, sizeof(MyStrPair), comparatorReversed);
    
    for(int it = 0; it < mas->len; ++it){
        fprintf(fp_out, (mas->p + it)->begin);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");
    
    int offset = 0;
    for(int it = 0; it < mas->len; ++it) {
        offset += fprintf(fp_out, (buff + 1 + offset)) + 1;
        fprintf(fp_out, "\n");
    }

    return;
}



