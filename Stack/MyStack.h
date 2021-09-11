#pragma once
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024
#define REALLOC_BAR 128

static int is_initialised = false;


enum MODE {
    ACCESS     = -1,
    INIT       =  0,
};


unsigned int hashFunc(const char * str);

static struct MyStack;

static struct SafeStack;

static struct InstancePair;

static SafeStack* descriptor(int identifier, MODE mode);

int top (MyStack* st);

void pop (MyStack* st);

MyStack* createStack();

void freeStack (MyStack* st);


