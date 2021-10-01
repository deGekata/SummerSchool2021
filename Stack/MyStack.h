#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "StackConfig.h"
#include "stdint.h"



#define is_NOT_VALID(ptr) is_not_valid_(ptr)
#define my_ASSERT(ptr) my_assert_(ptr, #ptr, __FILE__, __FUNCTION__, __LINE__, caller_func_source, caller_func, call_line, type_name_)
#define call_INFO const char* caller_func_source, const char* caller_func, int call_line
#define call_ARGS __FILE__, __FUNCTION__, __LINE__
#define get_ELEM(ptr, ind) ((my_type*)((char*)(ptr->arr) + sizeof(uint64_t)) + ind)

#if PROTECTION_LEVEL == 0
    #define createStack() createStack_()
    #define push(stack, value) push(stack, value)
    #define top(stack) top_(st)
    #define pop(stack) pop_(stack)
    #define freeStack(stack) freeStack_(stack)
    #define resize(stack) resize_(stack)
#else
    #define createStack() createStack_(call_ARGS)
    #define pushStack(st, value) push_(st, value, call_ARGS)
    #define top(st) top_(st, call_ARGS)
    #define pop(stack) pop_(stack, call_ARGS)
    #define freeStack(stack) freeStack_(stack, call_ARGS)
    #define resize(stack, n_capacity) resize_(stack, n_capacity, call_ARGS)
#endif

#if PROTECTION_LEVEL != 0
struct SafeStackStats {
#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    int hash_ch, hash_arr_ch, hash_data_ch;
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    int f_canary_ch, s_canary_ch, arr_f_canary_ch, arr_s_canary_ch;
#endif

    int capacity_ch, size_ch, size_cap_ch, arr_ch, ptr_ch;

};
#endif

#if PROTECTION_LEVEL != 0
struct StackCreationInfo {
    const char* caller_func_source;
    const char* caller_func;
    int call_line;
};
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
struct SafeStackHashes {
    int64_t hash, data_hash, arr_hash;
};
#endif

struct SafeStack {

#if defined HASH or defined FULL_PROTECTION
    int64_t hash, data_hash, arr_hash;
#endif

#if defined CANARY or FULL_PROTECTION
    long long int f_canary;
#endif

    int size;
    int capacity;
    my_type* arr;

#if PROTECTION_LEVEL != 0
    StackCreationInfo* info;
#endif

#if defined CANARY or FULL_PROTECTION
    long long int s_canary;
#endif

};


#if PROTECTION_LEVEL == 0
SafeStack* createStack_();
#else 
SafeStack* createStack_(call_INFO);
#endif

#if PROTECTION_LEVEL == 0
void resize_(SafeStack * st, int n_capacity);
#else
int resize_(SafeStack* st, int n_capacity, call_INFO);
#endif

#if PROTECTION_LEVEL == 0
void freeStack_(SafeStack* st);
#else 
void freeStack_(SafeStack* st, call_INFO);
#endif

#if PROTECTION_LEVEL == 0
void push_(SafeStack* st, int value){
#else 
void push_(SafeStack* st, my_type value, call_INFO);
#endif

void shrink_(SafeStack* st);

#if PROTECTION_LEVEL == 0
int top_(SafeStack* st);
#else 
my_type top_(SafeStack* st, call_INFO);
#endif

#if PROTECTION_LEVEL == 0
void pop_(SafeStack* st);
#else 
void pop_(SafeStack* st, call_INFO);
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
SafeStackHashes* makeHash_(SafeStack* st);
#endif

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
void makeApplyHash_(SafeStack* st);
#endif

#if defined HASH or defined FULL_PROTECTION
unsigned long long int hashFunc_(const char* str, int len, unsigned long long int init = 0);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
int is_not_valid_(SafeStack* ptr);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
void my_assert_(SafeStack* ptr, const char* var_name, const char* low_function_caller_source, const char* low_function_caller, int assert_line, call_INFO, const char* st_base_type);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
void fillStats(SafeStackStats* stats, int prototype);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
    void Dump_stack_(SafeStack* st, 
                SafeStackStats* stat, 
                const char* var_name, 
                int assert_line, 
                const char* low_function_caller, 
                const char* low_function_caller_source,
                const char* caller_func_source, 
                const char* caller_func, 
                int call_line, 
                const char* st_type );
#endif



enum MODE {
    ACCESS     = -1,
    INIT       =  0,
};


