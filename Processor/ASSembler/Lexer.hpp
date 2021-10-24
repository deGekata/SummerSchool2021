#include "../Shared/Shared.hpp"

void init_commands_hashes();

void printf_commands_hashes();

bool is_control_transfer(int command_id);

int64_t get_command_id(MyString* string, size_t* offset);

command_args* fill_command_arg(MyString* string, size_t* offset);

inline bool is_delimiter(char elem);

size_t skip_delimiters(MyString* string, size_t offset);

size_t get_lexem_offset(MyString* string, size_t offset);

/*
/brief Parsing lexems
*/
// Text* parseLexems(FILE* input, char comment_symbol);
