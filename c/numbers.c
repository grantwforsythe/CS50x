#include <cs50.h>
#include <stdio.h>

int main(void) {
    // you can just pass in a set of values rather than defining the arrays size
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    for (int i = 0; i < 7; i++) {
        if (numbers[i] == 0) {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}