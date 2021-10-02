#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include "MyStack.h"
#pragma warning (disable:4996)

using namespace std;



int main() {   
    
    SafeStack st;
    createStack(&st);

    #if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        int adder = 2;
    #else
        int adder = 0;
    #endif
    pushStack(&st, 'l');
    printf("top return: %d\n", top(&st));
    printf("--------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%d\n", (&st)->arr[i]);
    }
    printf("--------endarray\n\n");
    //st->data_hash = 0;
    //*(((int*)st) + 3) = 1;
    pushStack(&st, 'o');
    printf("top return: %d\n", top(&st));
    printf("---------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%d\n", (&st)->arr[i]);
    }
    printf("--------endarray\n\n");


    pushStack(&st, 'l');
    printf("top return: %d\n", top(&st));
    printf("----------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%d\n", (&st)->arr[i]);
    }
    printf("--------endarray\n\n");


    pushStack(&st, 7);
    printf("top return: %d\n", top(&st));
    printf("---------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%d\n", (&st)->arr[i]);
    }
    printf("--------endarray\n\n");

    printf("\n\n ----------------POPS---------------\n");
    resize(&st, adder + 1);
    int a = 2;
    *(((int*)&st) + 3) = 100;
    //st->size = 100;
       printf("pop return: %d\n", top(&st));
    printf("--------array:\n");
    for(int i = 0; i < (&st)->size + adder; ++i) {
        printf("%d\n", (&st)->arr[i]);
    }
    printf("--------endarray\n\n");
    pop(&st);


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
