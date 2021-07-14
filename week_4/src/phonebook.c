#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // open a file called phonebook.csv in append mode
    FILE *file = fopen("phonebook.csv", "a");
    
    // something went wrong
    if (file == NULL) {
        return 1;
    }
    
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    
    // write to file
    fprintf(file, "%s,%s\n", name, number);
    // close file
    fclose(file);
}
