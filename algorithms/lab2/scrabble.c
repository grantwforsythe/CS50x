#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototyping
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score1 < score2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return the score for a given string
    int sum = 0;

    for (int i = 0; i < strlen(word); i++){
        // If the character isn't alphabetical, nothing is added
        if (isalpha(word[i])) {
            // Change the charcter to uppercase so its easier to work with and able to index it with ASCII
            char c = toupper(word[i]);
            /*
            Convert the char to an int

            Refer to ASCII;
                A: 65, B: 66, ..., Z: 90
                (-65) A: 0, B: 1, ..., Z: 25

            Now we are able to easily index the POINTS array

            You can compare chars and ints automatically, no need for conversion in C!
            */
            int index = c - 65;
            sum += POINTS[index];
        }
    }

    return sum;
}
