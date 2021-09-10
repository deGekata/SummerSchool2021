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

//int comparatorStraight (const void* lhs, const void* rhs) {
//    assert(lhs);
//    assert(rhs);
//
//    MyStrPair* l = (MyStrPair*) lhs;  
//    MyStrPair* r = (MyStrPair*) rhs;
//
//    int pos = 0;
//    while ( *getSym (l, pos) != '\0' && *getSym (r, pos) != '\0') {
//        if ( *getSym (l, pos) != *getSym (r, pos) ) 
//            return *getSym (l, pos) < *getSym (r, pos);
//        ++pos;
//    }
//    
//    return *getSym (l, pos) == '\0' && *getSym (r, pos) != '\0';  
//}

int comparatorStraight(const void* s_void, const void* t_void)
{
    MyStrPair* l = (MyStrPair*) s_void;  
    MyStrPair* r = (MyStrPair*) t_void;
    char* s = (char*) l->begin;
    char* t = (char*) r->begin;
    while (*s != '\0' && *t != '\0')
    {
        if (*s < *t) {
            return -1;

        } else if (*s > *t) {
            return 1;
        
        } else {
            ++s;
            ++t;
        }
    }
    if (*s == '\0' && *t != '\0')
        return -1;
    if (*t == '\0' && *s != '\0')
        return 1;

    return 0;
}

void makeMagicPrint (FILE* fp_in, FILE* fp_out) {
    Text* mas =  readPoem(fp_in);

    qsort(mas->strings, mas->lines_cnt, sizeof(MyStrPair), comparatorStraight );

    for(int it = 0; it < mas->lines_cnt; ++it){
        fprintf(fp_out, (mas->strings + it)->begin);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");

    myQsort(mas->strings, mas->lines_cnt, sizeof(MyStrPair), comparatorReversed);
    
    for(int it = 0; it < mas->lines_cnt; ++it){
        fprintf(fp_out, (mas->strings + it)->begin);
        fprintf(fp_out, "\n");
    }
    fprintf(fp_out, "\n");
    
    int offset = 0;
    for(int it = 0; it < mas->lines_cnt; ++it) {
        offset += fprintf(fp_out, (mas->raw_line + 1 + offset)) + 1;
        fprintf(fp_out, "\n");
    }

    destructor(mas);
    free(mas);

    return;
}



