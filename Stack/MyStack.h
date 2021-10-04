#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "StackConfig.h"
#include "stdint.h"





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
    int64_t hash;
};
#endif

struct SafeStack {

#if PROTECTION_LEVEL == HASH or PROTECTION_LEVEL == FULL_PROTECTION
    int64_t hash;
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    long long int f_canary;
#endif

    int size;
    int capacity;
    my_type* arr;

#if PROTECTION_LEVEL != 0
    StackCreationInfo* info;
#endif

#if PROTECTION_LEVEL == CANARY or PROTECTION_LEVEL == FULL_PROTECTION
    long long int s_canary;        
#endif

};


#if PROTECTION_LEVEL == NO_PROTECTION
SafeStack* createStack_(SafeStack* st);
#else 
SafeStack* createStack_(SafeStack* st, call_INFO);
#endif

#if PROTECTION_LEVEL == NO_PROTECTION
int resize_(SafeStack * st, int n_capacity);
#else
int resize_(SafeStack* st, int n_capacity, call_INFO);
#endif

#if PROTECTION_LEVEL == NO_PROTECTION
void freeStack_(SafeStack* st);
#else 
void freeStack_(SafeStack* st, call_INFO);
#endif

#if PROTECTION_LEVEL == NO_PROTECTION
void push_(SafeStack* st, my_type value);
#else 
void push_(SafeStack* st, my_type value, call_INFO);
#endif

void shrink_(SafeStack* st);

#if PROTECTION_LEVEL == NO_PROTECTION
my_type top_(SafeStack* st);
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
int64_t hashFunc_(const char* str, int len, int64_t init = 0);
#endif

#if PROTECTION_LEVEL != NO_PROTECTION
int is_not_valid_(SafeStack* ptr);

int my_assert_(SafeStack* ptr, const char* var_name, const char* low_function_caller_source, const char* low_function_caller, int assert_line, call_INFO, const char* st_base_type);

void fillStats(SafeStackStats* stats, int prototype);

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