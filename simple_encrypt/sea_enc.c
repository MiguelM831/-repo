#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if(argc == 1) { //Missing command line output and exit
        printf("Expected Exit Code: 1\nUsage: %s KEY_IN_HEX\n", argv[0]);
    } else { 
        long key;
        key = strtol(argv[1], NULL, 16); //Get key number value from command line
        
        printf("Expected Exit Code: 0\n%ld\n", key);
    }
    return 0;
}