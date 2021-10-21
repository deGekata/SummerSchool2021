#include "ASSembler.hpp"

MyString* compile_program(FILE* input_file, FILE* out_file) {
    Text* text = parseLexems(input_file, '#');
    MyString* program = decode_lexems(text);
    if (program->size == -1) {
        assert(0 && "ASSembling error");
    }
    write_programm_on_disk(program, out_file);
}

MyString* decode_lexems(Text* text) {
    int offset = 0, lexem_len = 0, global_offset = 0;
    CommandParams params = {};
    MyString* program = {};
    program->begin = (char*) calloc(text->text_len, sizeof(char));
    for(int line_ind = 0; line_ind < text->lines_cnt; ++line_ind) {
        
        offset = skip_delimiters(program, offset);
        if(offset == text->strings[line_ind].size) {
            offset = 0;
            lexem_len = 0;
            continue;
        }

        lexem_len = get_lexem_offset(&text->strings[line_ind], offset) - offset;
        
        fill_command_params(&params, &text->strings[line_ind], offset, lexem_len);
        offset += lexem_len + 1;
        if (params.command_id == -1) {
            free(program->begin);
            program->size = -1;
            return program;
        }
        
        program->begin[global_offset] = (char)params.command_id;

        for(int param_ind = 0; param_ind < params.command_args_cnt; ++param_ind) {
            lexem_len = get_lexem_offset(&text->strings[line_ind], offset);
            if(lexem_len == 0) {
                assert(0 && "Not enough args for current command");
            }
            if (is_arg_valid(&text->strings[line_ind], offset, offset + lexem_len)) {
                write_param(&text->strings[line_ind], offset, offset + lexem_len, global_offset);
                offset += lexem_len + 1;
                offset = skip_delimiters(&text->strings[line_ind], offset);
            }
        }

        if(offset != text->strings[line_ind].size) {
                assert(0 && "Too many args");
        }

    }
    return program;
    

}

inline void write_programm_on_disk(MyString* program, FILE* out_file) {
    fwrite(program->begin, sizeof(char), program->size, out_file);
    return;
}


void fill_command_params(CommandParams* params, MyString* str, size_t begin, size_t end);

bool is_arg_valid(MyString* str, size_t command_type, size_t begin, size_t end) {
    switch (command_type)
    {
    case 0:
        return true;
        break;
    
    default:
        break;
    }
}

void write_command(MyString* str, size_t begin, size_t end, size_t buff_offset);


void write_param(MyString* str, size_t begin, size_t end, size_t buff_offset);