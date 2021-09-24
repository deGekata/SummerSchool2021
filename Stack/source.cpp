#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include "MyStack.h"
#pragma warning (disable:4996)

using namespace std;



int main() {   
    
    SafeStack* st = createStack();

    #if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
        int adder = 2;
    #else
        int adder = 0;
    #endif
    pushStack(st, 10);
    printf("top return: %d\n", top(st));
    printf("--------array:\n");
    for(int i = 0; i < st->size + adder; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");


    pushStack(st, 15);
    printf("top return: %d\n", top(st));
    printf("---------array:\n");
    for(int i = 0; i < st->size + adder; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");


    pushStack(st, 50);
    printf("top return: %d\n", top(st));
    printf("----------array:\n");
    for(int i = 0; i < st->size + adder; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");


    pushStack(st, 7);
    printf("top return: %d\n", top(st));
    printf("---------array:\n");
    for(int i = 0; i < st->size + adder; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");

    printf("\n\n ----------------POPS---------------\n");
    resize(st, adder);


    printf("pop return: %d\n", top(st));
    printf("--------array:\n");
    for(int i = 0; i < st->size + adder; ++i) {
        printf("%d\n", st->arr[i]);
    }
    printf("--------endarray\n\n");
    pop(st);


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
