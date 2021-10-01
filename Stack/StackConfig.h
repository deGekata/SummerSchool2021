#pragma once

#undef CANARY_SPECIAL_NUMBER

#undef BLOCK_SIZE

#undef REALLOC_BAR

#undef EMPTY_STACK_RETURN

#undef NULL_SPECIAL_PTR

#undef NO_PROTECTION

#undef CANARY

#undef HASH

#undef FULL_PROTECTION

#undef PROTECTION_LEVEL

#undef is_VALID

typedef char my_type;
static const char const* type_name_ = "char"; 

#define EMPTY_STACK_RETURN 0xF2EE
#define NULL_SPECIAL_PTR (int*)0xbad

#define CANARY_SPECIAL_NUMBER 0xFee1Dead

#define NO_PROTECTION 0
#define CANARY 1
#define HASH 2
#define FULL_PROTECTION 3

#define PROTECTION_LEVEL FULL_PROTECTION


