#include <iostream>
#include "StringSorter.h"
#pragma warning(disable : 4996)

int main() {
    FILE* fp_in = fopen("input.txt", "r");

    if(!fp_in) {
        printf("no such file");
        return 0;
    }

    FILE* fp_out = fopen("output.txt", "w");
    makeMagicPrint(fp_in, fp_out);

    return 0;
}   

