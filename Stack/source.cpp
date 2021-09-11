#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include "MyStack.h"
#pragma warning (disable:4996)

using namespace std;



int main() {   
    
    SafeStack* st = createStack ();
    printf("%d   %d   %d   %d ", st->size);
    getchar ();
    return 0;
}