#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 512

int main(int argc, char *argv[]) {
    if(argc == 1) { //Missing command line output and exit
        printf("Expected Exit Code: 1\nUsage: %s KEY_IN_HEX\n", argv[0]);
    } else { 
        long key;
        char inp[MAX_SIZE];
        ssize_t bytesR;
        char c;
        key = strtol(argv[1], NULL, 16); //Get key number value from command line
        bytesR = read(0, inp, MAX_SIZE);
        printf("Expected Exit Code: 0\n");
            for(int i = 0; i < bytesR-1; i++) {
                c = inp[i];
                c ^= key; //XOR the character with the key
                c &= 0xFF;
                printf("%X", c);
            }
            printf("\n");
    }
    return 0;
}