/* TODO: Have an array of strings, where strings are an array of chars*/
/* TODO: Figure out how to append to an array*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_height(void);
void repeat(char c, int times);


int main(void) {

    int height = get_height();

    for (int i = 1; i <= height; i++) {
        int num_hashes = i;
        int num_spaces = height - num_hashes;

        repeat(' ', num_spaces);
        repeat('#', num_hashes);

        printf("  ");

        repeat('#', num_hashes);

        printf("\n");
    }

    return 0;
}


int get_height(void) {
    /* Get an appropriate height - between 1 and 8 */
    int height;

    do {
        height = get_int("Height: ");
    } while(height < 1 || height > 8);

    return height;
}


void repeat(char c, int times) {
    while (--times >= 0) {
        printf("%c", c);
    }
}