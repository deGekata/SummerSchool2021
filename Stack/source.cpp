#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stdio.h>
#include "MyStack.h"

int main() {
    SafeStack stack;
    createStack(&stack);

    pushStack(&stack, 'l');
    pushStack(&stack, 'c');
    pushStack(&stack, 'a');
    pushStack(&stack, 'b');
    printf("Stack_pop: %" PRINTF_TYPE_SPEC "\n\n\n", pop(&stack));
    printf("looool\n\n");
    /*--------------First-------------*/
    //stack.capacity = 0;
    //stack.size = 0;
    //stack.arr = (my_type*)NULL_SPECIAL_PTR;
    /*--------------------------------*/

    /*--------------Second-------------*/
    #if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
        //int64_t hashFunc_(const char * str, size_t len, int64_t init);
        SafeStackHashes* makeHash_(SafeStack* st);
        stack.arr[2] = 10;
        stack.hash = *(int64_t*)makeHash_(&stack);
    #endif
    /*--------------------------------*/

    pushStack(&stack, 10);

    //stack.capacity = -1;
    //pushStack(&stack, 1);

    return 0;

    SafeStack st;
    createStack(&st);

    #if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        int adder = 2;
    #else
        int adder = 0;
    #endif
    pushStack(&st, 'l');
    printf("top return: %" PRINTF_TYPE_SPEC "\n", top(&st));
    printf("--------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%" PRINTF_TYPE_SPEC "\n", *get_ELEM((&st), i));
    }
    printf("--------endarray\n\n");
    //st->data_hash = 0;
    //*(((int*)st) + 3) = 1;
    pushStack(&st, 'o');
    printf("top return: %d\n", top(&st));
    printf("---------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%" PRINTF_TYPE_SPEC "\n", *get_ELEM((&st), i));
    }
    printf("--------endarray\n\n");


    pushStack(&st, 'l');
    printf("top return: %d\n", top(&st));
    printf("----------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%" PRINTF_TYPE_SPEC "\n", *get_ELEM((&st), i));
    }
    printf("--------endarray\n\n");


    pushStack(&st, 7);
    printf("top return: %d\n", top(&st));
    printf("---------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%" PRINTF_TYPE_SPEC "\n", *get_ELEM((&st), i));
    }
    printf("--------endarray\n\n");

    printf("\n\n ----------------POPS---------------\n");
    /*resize(&st, adder + 1);
    int a = 2;
    //*(((int*)&st) + 3) = 100;
    st.capacity = 0;
    st.size = 0;
    st.arr = (my_type*)NULL_SPECIAL_PTR;
    //st->size = 100;
       printf("pop return: %d\n", top(&st));
    printf("--------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%" PRINTF_TYPE_SPEC "\n", *get_ELEM((&st), i));
    }
    printf("--------endarray\n\n");*/
    pop(&st);




    std::set<int64_t> hashes;
    for(int64_t i = 0; i < 1000000; ++i) {
        hashes.insert(hashFunc_((const char*)&i, sizeof(i), 0));
    }
    printf("\n\n\n unique elems in 10^6: %d", hashes.size());



    /*printf("pop return: %d\n", top(st));
    printf("---------array:\n");
    for(int i = 0; i < st->size + 2; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");
    pop(st);


    printf("pop return: %d\n", top(st));
    printf("----------array:\n");
    for(int i = 0; i < st->size + 2; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");
    pop(st);


    printf("pop return: %d\n", top(st));
    printf("---------array:\n");
    for(int i = 0; i < st->size + 2; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");
    pop(st);*/

    //printf("%d   %d   %d   %d ", st->size);
    getchar ();
    return 0;
}
