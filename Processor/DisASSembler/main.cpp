#include "DisASSembler.hpp"

int main(int argc, char* argv[]) {
    if(argc < 3) assert(0 && "Not enough args");
    
    printf("test");
    init_command_ptr();
    FILE* input  = fopen(argv[1], "rb");
    // printf("%d", getc(input));
    FILE* output = fopen(argv[2], "w+");
    setvbuf( output, (char *)NULL, _IONBF, 0 );
    if(input == NULL || output == NULL) {
        assert(0 && "Can`t open files");
    }

    disassemble(input, output);

    fclose(input);
    fclose(output);
    

    return 0;
}