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
        uint16_t key; //Encrypt key
        char inp[MAX_SIZE]; //Character for input
        unsigned char c; //Character to hold the encrypted value
        key = strtol(argv[1], NULL, 16); //Get key number value from command line in hex
        ssize_t bytesR = read(0, inp, MAX_SIZE); //Receive input from user
        printf("Expected Exit Code: 0\n");
            for(ssize_t i = 0; i < bytesR-1; i++) {
                c = (unsigned char)inp[i] ^ (unsigned char)key; //XOR input and key and store in c
                c &= 0xFF; //Limit to 2 bytes in hex
                if(inp[i] == ' ') { //Check if input is empty
                    printf("\n");
                } else {
                    printf("%X", c); //Output c in hex
                    key = (key << 1) | (key >> 15); //Rotate key left 1
                    key *= 257; //Multiply key by 257
                    if((i+1)%40 == 0 && i != 0) printf("\n"); //Print newline after 40 chars
                }
            }
            printf("\n");
    }
    return 0;
}