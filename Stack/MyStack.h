#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "StackConfig.h"
#include "Logger.h"




#define is_NOT_VALID(ptr) is_not_valid_(ptr)
#define my_ASSERT(ptr) my_assert_(ptr, #ptr, __LINE__, __FUNCTION__, caller_func_source, caller_func, call_line)

#if PROTECTION_LEVEL == 0
    #define createStack() createStack_()
    #define push(stack, value) push(stack, value)
    #define top(stack) top_(st)
    #define pop(stack) pop_(stack)
    #define freeStack(stack) freeStack_(stack)
    #define resize(stack) resize_(stack)
#else
    #define createStack() createStack_(__LINE__, __FUNCTION__, __FILE__)
    #define pushStack(st, value) push_(st, value, __LINE__, __FUNCTION__, __FILE__)
    #define top(st) top_(st, __LINE__, __FUNCTION__, __FILE__)
    #define pop(stack) pop_(stack, __LINE__, __FUNCTION__, __FILE__)
    #define freeStack(stack) freeStack_(stack, , __LINE__, __FUNCTION__, __FILE__)
    #define resize(stack, n_capacity) resize_(stack, n_capacity, __LINE__, __FUNCTION__, __FILE__)
#endif

struct SafeStack {
#if defined HASH or defined FULL_PROTECTION
    unsigned int hash, data_hash, arr_hash;
#endif

#if defined CANARY or FULL_PROTECTION
    int f_canary;
#endif

    int size;
    int capacity;
    int* arr;

#if defined CANARY or FULL_PROTECTION
    int s_canary;
#endif

};

#if PROTECTION_LEVEL != 0
struct SafeStackStats {
#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    int hash_ch, hash_arr_ch, hash_data_ch;
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    int f_canary_ch, s_canary_ch, arr_f_canary_ch, arr_s_canary_ch;
#endif

    int capacity_ch, size_ch, arr_ch, ptr_ch;

};
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
struct SafeStackHashes {
    int hash, data_hash, arr_hash;
};
#endif

#if PROTECTION_LEVEL == 0
SafeStack* createStack_();
#else 
SafeStack* createStack_(int call_line, const char* caller_func, const char* caller_func_source);
#endif

#if PROTECTION_LEVEL == 0
void resize_(SafeStack * st, int n_capacity);
#else
int resize_(SafeStack* st, int n_capacity, int call_line, const char* caller_func, const char* caller_func_source);
#endif

#if PROTECTION_LEVEL == 0
void freeStack_(SafeStack* st);
#else 
void freeStack_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source);
#endif

#if PROTECTION_LEVEL == 0
void push_(SafeStack* st, int value){
#else 
void push_(SafeStack* st, int value, int call_line, const char* caller_func, const char* caller_func_source);
#endif

void shrink_(SafeStack* st);

#if PROTECTION_LEVEL == 0
int top_(SafeStack* st);
#else 
int top_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source);
#endif

#if PROTECTION_LEVEL == 0
void pop_(SafeStack* st);
#else 
void pop_(SafeStack* st, int call_line, const char* caller_func, const char* caller_func_source);
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
SafeStackHashes* makeHash_(SafeStack* st);
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
void makeApplyHashes_(SafeStack* st);
#endif

#if defined HASH or defined FULL_PROTECTION
unsigned int hashFunc_(const char* str, int len, unsigned int init = 0);
#endif

#if defined CANARY or defined FULL_PROTECTION
int checkCanaryIntegrity_(SafeStack* st);
#endif

#if defined HASH or defined FULL_PROTECTION
int checkHashIntegrity_(SafeStack* st);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
bool is_valid_(SafeStack* ptr);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
void my_assert_(SafeStack* ptr, const char* var_name, int assert_line, const char* low_function_caller, const char* caller_func_source, const char* caller_func, int call_line);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
void fillStats(SafeStackStats* stats, int prototype);
#endif
//static struct MyStack;
//
//static struct InstancePair;
//
//static SafeStack* descriptor (MyStack* prototype, MODE mode);
//
//void freeStack (MyStack* st);


enum MODE {
    ACCESS     = -1,
    INIT       =  0,
};


