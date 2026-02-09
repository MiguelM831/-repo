#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_SIZE 512

int main(int argc, char *argv[]) {
    if(argc == 1) { //Missing command line output and exit
        printf("Expected Exit Code: 1\nUsage: %s KEY_IN_HEX\n", argv[0]);
    } else { 
        uint16_t key;
        char inp[MAX_SIZE];
        unsigned char c;
        key = strtol(argv[1], NULL, 16); //Get key number value from command line
        ssize_t bytesR = read(0, inp, MAX_SIZE);
        printf("Expected Exit Code: 0\n%zd\n", bytesR);
            for(ssize_t i = 0; i < bytesR-1; i++) {
                c = (unsigned char)inp[i] ^ (unsigned char)key;
                c &= 0xFF;
                printf("%X", c);
                key = (key << 1) | (key >> 15);
                if((c & 0x80) == 0) {
                    key *= 257;
                }else {
                    key += 1;
                    key *= 257;
                }
            }
            printf("\n");
    }
    return 0;
}