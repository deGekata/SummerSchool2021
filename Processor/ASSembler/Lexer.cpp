#include "Lexer.hpp"

int64_t commands_hashes[CMD_MAX];

#define DEF_CMD(cmd, NUM, ARGS_CUNT, code) \
    commands_hashes[NUM] = hashFunc_(#cmd, strlen(#cmd), 0);\
    printf("%ld\n\n", hashFunc_(#cmd, strlen(#cmd), 0));

void init_commands_hashes() {
    #include "../CMD_DEF.hpp"
}
#undef DEF_CMD

void printf_commands_hashes() {
    for(int i = 0; i < CMD_MAX; ++i) {
        printf("%ld\n\n", commands_hashes[i]);
    }
}


int64_t hashFunc_(const char * str, size_t len, int64_t init) {
    unsigned long long int hash = init;
    for (size_t it = 0; it < len; str++, it++) {
        hash += (unsigned char)(*str);
        hash += (hash << 20);
        hash ^= (hash >> 12);
    }

    hash += (hash << 6);
    hash ^= (hash >> 22);
    hash += (hash << 29);

    return hash;
}


inline bool is_delimiter(char elem) {
    return (elem == ' ') || (elem == '\0');
}


// Text* parseLexems(FILE* inp, char comment_symbol) {
//     Text* text = readFromFile(inp, '\n', comment_symbol);
//     return text;
// }

#define DEF_CMD(cmd, NUM, ARGS_CUNT, code)  \
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

    

    int64_t hash = hashFunc_(string->begin + begin, *offset - begin, 0);

    #include "../CMD_DEF.hpp"
    { //else 
    }

    if(*offset > 0) {
        return CMD_MARK;
    }

    return -2;
}
#undef DEF_CMD


command_args* fill_command_arg(MyString* string, size_t* offset) {
    command_args* ret_args = (command_args*) calloc(1, sizeof(*ret_args));

//scanf_ret = sscanf(string->begin + *offset, "%1[[]%1[abcd]x%1[+]%d%1[]]%n", &delim, reg_sym, &delim, &ret_args->constant, &delim, &n);
    
    int n = 0;
    int scanf_ret;
    char* reg_sym = (char*) calloc(2, sizeof(char));
    *reg_sym = 100;
    char* delim = (char*) calloc(2, sizeof(char));

    //try [
    scanf_ret = sscanf(string->begin + *offset,"%1[[]", delim);
    if(scanf_ret == 1) {
        ret_args->flags = ret_args->flags | mem;
        *offset += 1;
    }

    //try reg + const   
    printf("lol");
    printf("scanned string1 %s\n\n", string->begin + *offset);
    scanf_ret = sscanf(string->begin + *offset, "%1[abcd]x%1[+]%d%n", reg_sym, &delim, &ret_args->constant, &n);
    printf("lol");
    if(scanf_ret == 3) {
        *offset += n;
        ret_args->reg_num = *reg_sym - 'a';
        ret_args->flags |= reg | immediate_constant;
        goto MEM_CHECK;
    }

    //try reg
    scanf_ret = sscanf(string->begin + *offset, "%1[abcd]x %n", reg_sym, &n);
    printf("scanfreturn: %d\n\n", scanf_ret);
    printf("scanned string %s\n\n", string->begin + *offset);
    printf("scanned reg ans syms: %s   %d\n\n", reg_sym, n);
    if(scanf_ret == 1) {
        *offset += n;
        ret_args->reg_num = *reg_sym - 'a';
        ret_args->flags |= reg;
        goto MEM_CHECK;
    }

    //try const
    scanf_ret = sscanf(string->begin + *offset, "%d %n", &ret_args->constant, &n);
    if(scanf_ret == 1) {
        *offset += n;
        ret_args->flags |= immediate_constant;
        goto MEM_CHECK;
    }

MEM_CHECK:
    // printf("%hu flags %hu", ret_args->flags, ret_args->flags & mem);
    if(ret_args->flags & mem) {
        scanf_ret = sscanf(string->begin + *offset,"%1[]]", delim);
        printf("delim: %s\n", delim);
        if(scanf_ret != 1) {
            free(ret_args);
            return NULL;
        }
        *offset += n;
        ret_args->flags |= mem;
    }
    return ret_args;

}


size_t skip_delimiters(MyString* string, size_t offset) {
    while ( is_delimiter(string->begin[offset]) &&  offset < string->size) ++offset;
    
    return offset;
}

size_t get_lexem_offset(MyString* string, size_t offset) {
    while ( !is_delimiter(string->begin[offset]) && offset < string->size) ++offset;
    
    return offset;
}

