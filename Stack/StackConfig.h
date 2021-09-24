#pragma once

#undef CANARY_SPECIAL_NUMBER

#undef CANARY_SPECIAL_NUMBER

#undef BLOCK_SIZE

#undef REALLOC_BAR

#undef CANARY_SPECIAL_NUMBER

#undef VOID_STACK_RETURN

#undef NULL_SPECIAL_PTR

#undef NO_PROTECTION

#undef CANARY

#undef HASH

#undef FULL_PROTECTION

#undef PROTECTION_LEVEL

#undef is_VALID

#define BLOCK_SIZE 1024
#define REALLOC_BAR 128
#define CANARY_SPECIAL_NUMBER 0xFee1Dead
#define VOID_STACK_RETURN 0xF2EE
#define NULL_SPECIAL_PTR (int*)0xbad


#define NO_PROTECTION 0
#define CANARY 1
#define HASH 2
#define FULL_PROTECTION 3

#define PROTECTION_LEVEL HASH


