#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// constants
#define UPPERCASE_LETTER_START 65
#define LOWERCASE_LETTER_START 97
#define LETTERS_COUNT

// Prototyping
bool vaild_key(string cipher);
string encrypt(string plaintext, string cipher);

int main(int argc, string argv[]) {

    // check that there is only 2 arguments given
    if (argc != 2) {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    string cipher = argv[1];

    // check that the cipher contains 26 unique alphabetical charactesr
    if (strlen(cipher) != LETTERS_COUNT || !(vaild_key(cipher))) {
        printf("Key must contain 26 unique alphabetical characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    // print encrypted string
    printf("ciphertext: %s\n", encrypt(plaintext, cipher));

    return 0;
}


bool vaild_key(string cipher) {
    // Check if its a valid key
    for (int i = 0; cipher[i] != '\0'; i++) {
        // check if each character is alphanumeric
        if (!(isalpha(cipher[i]))) {
            return false;
        }
        // check if any characters are repeated
        for (int j = i + 1; j < strlen(cipher); j++) {
            // change to the same case in order to compare the characters
            if (tolower(cipher[i]) == tolower(cipher[j])) {
                return false;
            }
        }
    }
    return true;
}


string encrypt(string plaintext, string cipher) {

    string encryptedtext = plaintext;
    int len = strlen(plaintext);

    for (int i = 0; i < len; i++) {
        // if the character is alphabetical, it is ignored in the encryption
        if (isalpha(plaintext[i])) {
            // upper case character
            if (plaintext[i] <= 90) {
                int index = plaintext[i] - UPPERCASE_LETTERS_START;
                encryptedtext[i] = toupper(cipher[index]);
            // lower case character
            } else {
                int index = plaintext[i] - LOWERCASE_LETTERS_START;
                encryptedtext[i] = tolower(cipher[index]);
            }

        }
    }

    return encryptedtext;
}