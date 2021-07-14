#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // create an array
    int *list = malloc(3 * sizeof(int));

    // something went wrong
    if (list == NULL) {
        return 1;
    }
                 // logically equivalent to
    list[0] = 1; // *(list) = 1
    list[1] = 2; // *(list+1) = 2
    list[2] = 3; // *(list+2) = 3

    // decided that we wanted a 4th element in the array
    // int *tmp = malloc(4 * sizeof(int));
    int *tmp = realloc(list, 4 * sizeof(int)); // copies the old into the new; therefore, which copies the values and replaces the for loop in line 27
    // realloc still has the same issue of copying arrays
    // something went wrong
    if (tmp == NULL) {
        free(list);
        return 1;
    }

    // updating the array to add an extra element
    // for (int i = 0; i < 3; i++) {
    //     tmp[i] = list[i];
    // }

    // the extra element
    tmp[3] = 4;

    // remove the previous list
    free(list);

    // set the list to be the new array with an extra element
    list = tmp;

    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

    // since list points to tmp, it frees both
    free(list);
}
