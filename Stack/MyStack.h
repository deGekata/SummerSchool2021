#pragma once
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define REALLOC_BAR 128

static int is_initialised = false;



unsigned int hashFunc(const char * str)
{

    unsigned int hash = 0;

    for (; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;

}

static struct MyStack;

static struct SafeStack;

static SafeStack* descriptor(int identifier);

int top (MyStack* st);

void pop (MyStack* st);

MyStack* createStack();

void freeStack (MyStack* st);


