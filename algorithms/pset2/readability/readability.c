/*
Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    L - the average number of letters per 100 words in the text
    S - the average number of sentences per 100 words in the text
*/
#include <cs50.h>
#include <math.h> // round function
#include <ctype.h> // isalpha function
#include <stdio.h>
#include <string.h>

// Prototyping
int reading_index(string text);

// Calculate the reading level of a given piece of text
int main(void) {
    // Prompt user for text
    string text = get_string("Text: ");
    // TODO: calculate reading level based on the Coleman-Liau index
    // TODO: print grade level
    int index = reading_index(text);

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else
        printf("Grade %i\n", index);
    return 0;
}

int reading_index(string text) {
    int letters = 0;
    int words = 1; // starts at one because spaces are in between two words
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++) {
     // Count number of letters
        if (isalpha(text[i])) {
            letters++;
        }
        // Count number of words
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            words++;
        }
        // Count number of sentences
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences++;
        }
    }

    float L = (float) letters / words * 100.0; // Number of letters per 100 words
    float S = (float) sentences / words * 100.0; // Number of sentences per 100 words
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}