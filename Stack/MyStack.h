#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BLOCK_SIZE 1024
#define REALLOC_BAR 128
#define CANARY_SPECIAL_NUMBER 0xffffffff

#define NO_PROTECTION
#define CANARY
#define HASH
#define FULL_PROTECTION

enum MODE {
    ACCESS     = -1,
    INIT       =  0,
};

unsigned int hashFunc(unsigned int init, const char * str, int len);

static struct MyStack;

struct SafeStack {
#if defined HASH or defined FULL_PROTECTION
    unsigned int hash, size_hash, data_hash;
#endif
    int size;
    int max_size;
    int* data;
};

int checkCanaryIntegrity(SafeStack* st);

int checkHashIntegrity(SafeStack* st);

static struct InstancePair;

static SafeStack* descriptor (MyStack* prototype, MODE mode);

void freeSafeStack (SafeStack* st);

int top (SafeStack* st);

void pop (SafeStack* st);

SafeStack* createStack ();

void freeStack (MyStack* st);


