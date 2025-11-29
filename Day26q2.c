#include <stdio.h>

int main() {
    int blocks[] = {1, 3, 5, 3, 1}; // number of stars in each block
    int n = sizeof(blocks) / sizeof(blocks[0]);

    for (int i = 0; i < n; i++) {      // loop through blocks
        for (int j = 0; j < blocks[i]; j++) {  // print stars in each block
            printf("*\n");
        }
        printf("\n"); // empty line after each block
    }

    return 0;
}
