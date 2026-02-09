#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc == 1) { //Missing command line output and exit
        printf("Expected Exit Code: 1\nUsage: %s KEY_IN_HEX\n", argv[0]);
    } else { 
        printf("Expected Exit Code: 0\n");
    }
    return 0;
}