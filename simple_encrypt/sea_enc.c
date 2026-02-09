#include <stdio.h>

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("Expected Exit Code: 1\nUsage: %s", argv[0]);
        printf(" KEY_IN_HEX\n");
    } else {
        printf("Expected Exit Code: 0\n");
    }
    return 0;
}