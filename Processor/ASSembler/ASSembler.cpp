#include "ASSembler.hpp"

void extend_my_arr(my_arr* arr) {
    arr->capacity = arr->capacity * 2;
    arr->data = (label_struct*) realloc(arr->data, arr->capacity * sizeof(label_struct));
    return;
}

int find_label(int64_t hash) {
    for(int it = 0; it < marks.size; ++it) {
        if(marks.data[it].hash == hash) {
            return it;
        }
    }
    return -1;
}

void link_labels(MyString* program) {
    for(int jmp_num = 0; jmp_num < m_arr.size; ++jmp_num) {
        int label_pos = find_label(m_arr.data[jmp_num].hash);
        if(label_pos == -1) {
            assert(0 && "cant find label");
        }
        *(int*)(program->begin + m_arr.data[jmp_num].location) = marks.data[label_pos].location;
    }
}

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code)                                                                    \
    case (NUM):                                                                                                          \
        if (ARGS_TYPE) {                                                                                                 \
            return true;                                                                                                 \
        } return false;                                                                                                  \
        break;

bool is_args_mathing(int64_t command, uint8_t flags) {
    // printf("%hd %hd, %d checking match\n\n", uint32_t(flag), uint32_t(reference), int(((flag) & reference) != 0));
    switch (command) {
        
         #include "../CMD_DEF.hpp"
    
        default:
            return 0;
            break;
    }
}

void write_command(MyString* programm, size_t prev_ip_command, int command_id, int8_t command_flags) {
//    return;
   programm->begin[prev_ip_command] |= command_id | (command_flags & ~empty);
}

void write_args(MyString* program, size_t* ip_offset, command_args* command_arg) {
    // return;
    if (command_arg->flags & mark) {
        *(int*)(program->begin + *ip_offset) = 0;
        *ip_offset += sizeof(int); 
        return;
    }

    if(command_arg->flags & empty) return;

    if(command_arg->flags & reg) {
        printf("writing imm const :%d\n\n", command_arg->constant);
       *(program->begin + *ip_offset) = command_arg->reg_num;
        *ip_offset += sizeof(char);  
    }

    if(command_arg->flags & immediate_constant) {
        printf("writing imm const :%d  ip %d\n\n", command_arg->constant, *ip_offset);
       *(int32_t*)(program->begin + *ip_offset) = command_arg->constant;
        *ip_offset += sizeof(int);  
    }

}



void parse_write_args(MyString* program,
                      int64_t   command,
                      int8_t    args_cunt, 
                      int8_t*   command_flags,
                      MyString* string, 
                      size_t*   offset,
                      size_t*   ip_offset) {

    if(command == CMD_JMP) {
        *offset = skip_delimiters(string, *offset);
        command_args* command_arg_buff;
        command_arg_buff = fill_command_arg(string, offset);
        if(m_arr.size  == m_arr.capacity) extend_my_arr(&m_arr);
        label_struct jmp;
        jmp.location = *ip_offset + 1;
        jmp.hash = hashFunc_(command_arg_buff->mark_name->begin, command_arg_buff->mark_name->size, 0);
        m_arr.data[m_arr.size] = jmp; 
        *(int32_t*)(program->begin + *ip_offset) = 228;
        *ip_offset += sizeof(int);
        printf("jmp hash: %ld\n", jmp.hash);
        printf( "JUMP ARGS:::%s %d\n\n", command_arg_buff->mark_name, hashFunc_(command_arg_buff->mark_name->begin, command_arg_buff->mark_name->size, 0));
        return;
    }

    *command_flags = 0;

    printf("parse_write ask\n");
    

    command_args* command_arg_buff;
    for (int8_t args_num = 0; args_num < args_cunt; ++args_num) {
            *offset = skip_delimiters(string, *offset);
            printf("left str %s\n", string->begin + *offset);   //
            printf("offset before fill_command %d\n", *offset); //
            command_arg_buff = fill_command_arg(string, offset);
            printf("left str2 %s\n", string->begin + *offset);  //
            if(!command_arg_buff) return;
            *command_flags |= command_arg_buff->flags;
            printf("left str3 %s\n", string->begin + *offset);  //
            printf("%hu flags  %d\n\n", command_arg_buff->flags, command_arg_buff->constant); //
            if(is_args_mathing(command, command_arg_buff->flags)) {
                write_args(program, ip_offset, command_arg_buff);
                *offset = get_lexem_offset(string, *offset);
                printf("%d new offset\n\n", *offset); //
            } else {
                assert(0 && "args not matching\n\n\n"); //
                return;
            }
            free(command_arg_buff);
    }
    return;
}


bool compile_program(FILE* input_file, FILE* output_file) {
    m_arr.data = (label_struct*) calloc(100, sizeof(label_struct));
    m_arr.size = 0;
    m_arr.capacity = 100;
    marks.data = (label_struct*) calloc(100, sizeof(label_struct));
    marks.size = 0;
    marks.capacity = 100;
    
    char* a = (char*) calloc(1, sizeof(char));
    *a = 'a';
    Text* text = readFromFile(input_file, '\n', '#');
    fwrite(a, sizeof(char), 1, output_file);
    printf("write 0 \n");
    MyString* program = decode_lexems(text);
    fwrite(a, sizeof(char), 1, output_file);
    printf("write 1 \n");
    if (program->size == -1) {
        assert(0 && "ASSembling error");
    }
    link_labels();

    printf("program last sym %d\n", program->begin[program->size - 1]);
    write_programm_on_disk(program, output_file);
    return 1;
}


#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code)                                                                         \
    case (NUM):                                                                                                               \
        parse_write_args(program, NUM, ARGS_CUNT, &command_flags, &text->strings[line_ind], &offset, &ip_command);            \
        break;

MyString* decode_lexems(Text* text) {
    size_t offset = 0, prev_ip_command = 0, ip_command = 0, command_id = -2;
    int8_t command_flags;
    MyString* program = (MyString*) calloc(1, sizeof(*program));
    program->begin = (char*) calloc(text->text_len * 3 * sizeof(int), sizeof(char));

    for(int line_ind = 0; line_ind < text->lines_cnt; ++line_ind) {
        offset = 0;
        printf("new line %d\n\n", line_ind);
        offset = skip_delimiters(&text->strings[line_ind], offset);
        if(offset == text->strings[line_ind].size) {
            offset = 0;
            continue;
        }
        printf("before command id\n");
        command_id = get_command_id(&text->strings[line_ind], &offset);
        printf("after command id\n");

        if(command_id == -2) {
            free(program->begin);
            free(program);
            return NULL;
        }    
        printf("after -2 if command id: %d\n", command_id);

        int args_cnt;


        prev_ip_command = ip_command++;

        if(command_id == CMD_MARK) {
            if(marks.size == marks.capacity) extend_my_arr(&marks);
            label_struct label;
            label.location = ip_command;
            int lexem_begin = skip_delimiters(&text->strings[line_ind], 0);
            printf("before label hash %d %d \n", lexem_begin, offset);
            label.hash = hashFunc_(text->strings[line_ind].begin, offset - lexem_begin - 1, 0);
            marks.data[marks.size] = label; 
            printf("label hash: %ld\n", label.hash);
            
        }

        switch (command_id) {
            #include "../CMD_DEF.hpp"
            default:
                break;
        }


        printf("cur_offset %d \n\n", offset);
        printf("write command\n");
        write_command(program, prev_ip_command, command_id, command_flags);
        printf("last sym %d %d\n", int(text->strings[line_ind].begin[offset]), int(text->strings[line_ind].begin[offset] != '\0'));
        offset = skip_delimiters(&text->strings[line_ind], offset);
        printf("str size: %d  offset:%d, str:'%s'\n", text->strings[line_ind].size, offset, text->strings[line_ind]);
        if(offset != text->strings[line_ind].size) {
                assert(0 && "Too many args");
        }
    }
    printf("%d program bef ip command eq\n", text->text_len * 3 * sizeof(int));
    program->size = ip_command;
    return program;
}
#undef DEF_CMD


inline void write_programm_on_disk(MyString* program, FILE* out_file) {
    printf("writing program: '%d'", program->begin);
    for(int i = 0; i < program->size; ++i) {
        printf("%hu_ ", program->begin[i]);
    }
    printf("  %d\n", program->size);
    printf("%d fiiile", out_file);
    fwrite(program->begin, sizeof(char), program->size, out_file);
    return;
}
