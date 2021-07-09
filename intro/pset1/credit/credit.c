// TODO : let user input a credit card number
// TODO : if the input doesn't follow the structure of a credit card, then prompt the user again
// TOOD : check if the card is vaild using Luhn's Algorithm
// TODO : if its valid, determine the type of credit card (AMEX, MASTERCARD, VISA). if it isn't, than its INVALID

#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef char *string;
// Prototyping
bool checksum(string cardnumber);

const int AMEX_LEN = 15;
const int MC_LEN = 16;
const int VISA_LEN_13 = 13;
const int VISA_LEN_16 = 13;

int main(void) {
    /*
    AMEX:
     * 15-digit numbers
     * start with 34 or 37

    MasterCard:
     * 16-digit numbers
     * most start with 51-55

    Visa:
     * 13- and 16- digit numbers
     * start with 4
    */

    /* results
    bool checksum = checksum(cardnumber);

    if (first digit 34 && checksum) {
        printf("AMEX\n");
    } else if (first digit start with 51-55 && checksum) {
        printf("MASTERCARD\n");
    } else if (first digit start with 4 && checksum) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    */
    string cardnumber = get_string("Number: ");
    bool valid = checksum(cardnumber);

    // if checksum isn't False, than it has to be True
    if (!(valid)) {
        printf("INVALID\n");
    } else if (cardnumber[0] == 4) {
        printf("VISA\n");
    } else if (cardnumber[0] == 5 && (cardnumber[1] > 1 && cardnumber[1] < 5)) {
        printf("MASTERCARD\n");
    } else if (cardnumber[0] == 3 && cardnumber[1] == 4) {
        printf("AMEX\n");
    } else {
        return 1;
    } 

    return 0;
}

bool checksum(string cardnumber){
    /*
    Luhn's Algorithm:
    1. multiply every other digit by 2, starting with second-to-last digit
    2. add those products' digits together
    3. add the sum to the sum of the digits that weren't multiplied by 2
    4. if the total's last digit is 0, then the number is valid
    */
    int card_len = strlen(cardnumber);
    
    if (card_len != AMEX_LEN || card_len != MC_LEN || card_len != VISA_LEN_13 || card_len != VISA_LEN_16) {
        return false;
    }

    return true;
}