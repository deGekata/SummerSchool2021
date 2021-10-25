#include "Lexer.hpp"

int64_t commands_hashes[CMD_MAX];

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, CODE) \
    commands_hashes[NUM] = hashFunc(#cmd, strlen(#cmd), 0);\
    printf(#cmd " hash: %ld\n\n", hashFunc(#cmd, strlen(#cmd), 0));

void init_commands_hashes() {
    #include "../Shared/CMD_DEF.hpp"
}
#undef DEF_CMD

void printf_commands_hashes() {
    for(int i = 0; i < CMD_MAX; ++i) {
        printf("%ld\n\n", commands_hashes[i]);
    }
}

inline bool is_delimiter(char elem) {
    return (elem == ' ');// || (elem == '\0');
}

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code)  \
    if(hash == commands_hashes[NUM]) {      \
        return NUM; \
    } else 

int64_t get_command_id(MyString* string, size_t* offset) {
    size_t begin = skip_delimiters(string, 0);
    printf("%ld offff beg\n\n", begin);
    if(begin == string->size - 1) {
        return -1;
    }

    *offset = get_lexem_offset(string, begin);
    printf("%ld offff lex\n\n ", *offset);

    int64_t hash = hashFunc(string->begin + begin, *offset - begin, 0);

    #include "../Shared/CMD_DEF.hpp"
    if (string->size > 1 && string->begin[string->size - 1] == ':') { 
        return CMD_MARK;
    } else if (string->begin[0] == 'D' && string->begin[1] == 'B') {
        return CMD_DB;
    }

    return -2;
}
#undef DEF_CMD


command_args* fill_command_arg(MyString* string, size_t* offset) {
    command_args* ret_args = (command_args*) calloc(1, sizeof(*ret_args));

//scanf_ret = sscanf(string->begin + *offset, "%1[[]%1[abcd]x%1[+]%d%1[]]%n", &delim, reg_sym, &delim, &ret_args->constant, &delim, &n);
    *offset = skip_delimiters(string, *offset);
    if(*offset == string->size) {
        ret_args->flags |= empty;
    }

    int n = 0, scanf_ret;
    char* reg_sym = (char*) calloc(2, sizeof(char));
    *reg_sym = 100;
    char* delim = (char*) calloc(2, sizeof(char));

    //try [
    scanf_ret = sscanf(string->begin + *offset,"%1[[]", delim);
    if(scanf_ret == 1) {
        *offset += 1;
        ret_args->flags = ret_args->flags | mem;
    }

    //try reg + const   
    printf("lol\n");
    printf("scanned string1 %s\n\n", string->begin + *offset);
    scanf_ret = sscanf(string->begin + *offset, "%1[abcd]x%1[+]%d%n", reg_sym, &delim, &ret_args->constant, &n);
    printf("scanf_ret %d  n:%d lol\n", scanf_ret, n);
    if(scanf_ret == 3 && n != 0) {
        *offset += n;
        ret_args->reg_num = *reg_sym - 'a';
        ret_args->flags |= reg | immediate_constant;
        goto MEM_CHECK;
    }

    //try reg
    scanf_ret = sscanf(string->begin + *offset, "%1[abcd]x%n", reg_sym, &n);
    printf("scanfreturn: %d %d\n\n", scanf_ret, n);
    printf("scanned string %s\n\n", string->begin + *offset);
    printf("scanned reg ans syms: %s   %d\n\n", reg_sym, n);
    if(scanf_ret == 1 && n !=0) {
        *offset += n;
        ret_args->reg_num = *reg_sym - 'a';
        ret_args->flags |= reg;
        goto MEM_CHECK;
    }

    //try const
    scanf_ret = sscanf(string->begin + *offset, "%d%n", &ret_args->constant, &n);
    printf("scanfreturn: %d %d\n\n", scanf_ret, n);
    printf("scanned string in const %s\n\n", string->begin + *offset);
    if(scanf_ret == 1 && n != 0) {
        *offset += n;
        ret_args->flags |= immediate_constant;
        goto MEM_CHECK;
    }

MEM_CHECK:

    // check ] on end
    if(ret_args->flags & mem) {
        scanf_ret = sscanf(string->begin + *offset,"%1[]]", delim);
        printf("delim: %s\n", delim);
        if(scanf_ret != 1) {
            free(delim);
            free(reg_sym);
            free(ret_args);
            return NULL;
        }

        *offset += 1;
        ret_args->flags |= mem;
    }
    
    // parse mark:
    printf("parse_mark %d\n\n", ret_args->flags);
    if (!ret_args->flags) {
        size_t mark_offset = get_lexem_offset(string, *offset);
        printf("parse_mark in %d mark off\n\n", mark_offset);
        
        for(size_t sym_num = *offset; sym_num < mark_offset; ++sym_num) {
            
            if(!(
                    ('a' <= string->begin[sym_num] && string->begin[sym_num] <= 'z' ) ||
                    ('A' <= string->begin[sym_num] && string->begin[sym_num] <= 'Z' ) ||
                    ('0' <= string->begin[sym_num] && string->begin[sym_num] <= '9' )
                )) { 
                    printf("parse_mark gavno '%c' \n\n",  string->begin[sym_num]);
                    
                    free(delim);
                    free(reg_sym);
                    free(ret_args);
                    return NULL;
                }

        }

        printf("MARK: %s\n", string->begin + *offset);

        ret_args->flags |= mark;
        ret_args->mark_name = (MyString*) calloc(1, sizeof(*ret_args->mark_name));
        ret_args->mark_name->begin = string->begin + *offset;
        ret_args->mark_name->size = mark_offset - *offset;

        printf("MARK: %d\n", hashFunc(ret_args->mark_name->begin, ret_args->mark_name->size, 0));

        *offset = mark_offset;

    }

    return ret_args;

}


size_t skip_delimiters(MyString* string, size_t offset) {
    while ( is_delimiter(string->begin[offset]) && (string->begin[offset] != '\0') &&  offset < string->size) ++offset;
    
    return offset;
}

size_t get_lexem_offset(MyString* string, size_t offset) {
    printf("%d offset in get_lexem_offset\n\n", offset);
    while ( !is_delimiter(string->begin[offset]) && string->begin[offset] != '\0' && offset < string->size) ++offset;
    
    return offset;
}

