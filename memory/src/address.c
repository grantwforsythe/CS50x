// #include <cs50.h>
#include <stdio.h>

// typedef struct char *string;

int main(void) {
    int n = 50;
    int *p  = &n;
    // * goes to a particular address
    // & returns an address
    printf("%i\n", *p);

    char *message = "Hello, world!";

    for (int i = 0; message[i] != '\0'; i++) {
        printf("%c : %p\n", message[i], &message[i]);
    }

    printf("%p\n", &message);
}