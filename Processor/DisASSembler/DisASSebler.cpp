#include "DisASSembler.hpp"

#define DEF_CMD(cmd, NUM, ARGS_CUNT, ARGS_TYPE, code) \
    command_str_ptrs[NUM] = #cmd;                      \
    command_str_len[NUM] = strlen(#cmd);                \
    printf("%s\n", command_str_ptrs[NUM]);

void init_command_ptr() {
    #include "../Shared/CMD_DEF.hpp"
}

void disassemble(FILE* input, FILE* output) {
    int file_size = getFileSize(input);
    printf("%d\n", __LINE__);
    printf("%d", file_size);
    MyString* program_asm, *program_label_counters;
    printf("%d\n", __LINE__);
    create_buff(&program_asm, file_size);
    create_buff(&program_label_counters, (file_size - 2) * 4);
    program_label_counters->size = program_asm->size;
    printf("%d\n", __LINE__);
    fread(program_asm->begin, sizeof(char), file_size, input);
    printf("%d\n", __LINE__);
    program_asm->begin += 2;
    program_asm->size -= 2;
    printf("%d\n", __LINE__);
    int cmd_cnt = fill_additional_data(program_asm, program_label_counters);
    printf("%d\n", __LINE__);
    write_program_on_disk(program_asm, program_label_counters, output);
    
    return;
}

int fill_additional_data(MyString* program, MyString* program_label_counters) {
    int cmd_cnt = 0, ip = 0, label_id = 0;

    while(ip < program->size) {
        int command_len = get_command_len(program, ip);
        printf("  len :%d\n", command_len);

        if(is_control_transfer(program->begin[ip])) {
            label_id +=  (((int*)program_label_counters->begin)[ *(int*)(program->begin + ip + 1) ] == 0);

            ((int*)program_label_counters->begin)[ *(int*)(program->begin + ip + 1) ] += 
                    (((int*)program_label_counters->begin)[ *(int*)(program->begin + ip + 1) ] == 0) * label_id;
            
            printf("wtf %d\n", (((int*)program_label_counters->begin)[ *(int*)(program->begin + ip + 1) ] == 0));
        }

        ++cmd_cnt;
        ip += command_len;
    }

    // for(int i = 0; i < program_label_counters->size; ++i) {
    //     printf("cell num: %d  val:%d\n", i, ((int*)program_label_counters->begin)[i]);

    // }

    return cmd_cnt;
}

void write_program_on_disk(MyString* program, MyString* program_label_counters, FILE* output) {
    int cmd_cnt = 0, ip = 0, command_ip = 0;;
    char str_buff[24];

    while(ip < program->size) {

        command_ip = ip;
        memset(str_buff, 0x20202020, sizeof(str_buff));

        if ( ((int*)program_label_counters->begin)[ ip ] != 0 ) {
            printf("is_label\n");
            sprintf(str_buff, "%d:\n", ((int*)program_label_counters->begin)[ ip ]);
            fputs(str_buff, output);
        }

        fputs(command_str_ptrs[uint8_t(program->begin[ip] & ~(reg | immediate_constant | mem))], output);
        // fwrite(
        //        command_str_ptrs[uint8_t(program->begin[ip] & ~(reg | immediate_constant | mem))], 
        //        sizeof(char),
        //        command_str_len[program->begin[ip] & ~(reg | immediate_constant | mem)],
        //        output
        //       );

        printf("comm ip:%d %hhu  name: %s\n", ip, char(program->begin[ip] & ~(reg | immediate_constant | mem)), command_str_ptrs[uint8_t(program->begin[ip] & ~(reg | immediate_constant | mem))]);
      
        
        if (is_control_transfer(program->begin[command_ip] & ~(mem | reg | immediate_constant))) {
            sprintf(str_buff, " %d\n", ((int*)program_label_counters->begin)[ *(int*)(program->begin + ip + 1) ]);
            fputs(str_buff, output);
            ip += sizeof(char) + sizeof(int);
            continue;
        }
        printf("%d\n", __LINE__);

        ++ip;

        int str_offset = 0;
        str_buff[str_offset++] = ' ';

        if ((program->begin[command_ip] & mem) != 0) {
            str_buff[str_offset++] = '[';
        }
        printf("%d\n", __LINE__);

        if ((program->begin[command_ip] & reg) != 0) {
            str_buff[str_offset++] = 'a' +  program->begin[ip++];
            str_buff[str_offset++] = 'x';
        }
        printf("%d\n", __LINE__);

        if ((program->begin[command_ip] & (reg | immediate_constant)) == (reg | immediate_constant)) {
            sprintf(str_buff + str_offset, " + ", *(int*)(program->begin + ip));
            str_offset += 3;
        }

        if ((program->begin[command_ip] & immediate_constant) != 0) {
            sprintf(str_buff + str_offset, "%d", *(int*)(program->begin + ip));
            str_offset += strlen(str_buff + str_offset);
            str_buff[str_offset] = ' ';
            ip += sizeof(int);
        }
        printf("%d\n", __LINE__);

        if ((program->begin[command_ip] & mem) != 0) {
            str_buff[str_offset++] = ']';
        }
        str_buff[str_offset] = '\n';
        printf("%d\n", __LINE__);

        fwrite(
               str_buff, 
               sizeof(char),
               str_offset + 1,
               output
              );

    }

    return;
}

int get_command_len(MyString* string, int cur_ip) {
    char command =*(char*)(string->begin + cur_ip);
    printf("cmd: %d  ", command);
    int cmd_len = 1;

    cmd_len += ((command & reg)                != 0) * sizeof(char);
    cmd_len += ((command & immediate_constant) != 0) * sizeof(int);
    cmd_len += is_control_transfer(command)          * sizeof(int);

    return cmd_len;
}

void create_buff(MyString** string, int size) {
    *string = (MyString*) calloc(1, sizeof(MyString));
    (*string)->size = size;
    (*string)->begin = (char*) calloc(size, sizeof(char));
    return;
}