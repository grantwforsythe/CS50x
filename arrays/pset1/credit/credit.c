// TODO : let user input a credit card number
// TODO : if the input doesn't follow the structure of a credit card, then prompt the user again
// TOOD : check if the card is vaild using Luhn's Algorithm
// TODO : if its valid, determine the type of credit card (AMEX, MASTERCARD, VISA). if it isn't, than its INVALID

#include <cs50.h>
#include <stdio.h>

// Prototyping
bool checksum(long cardnumber);

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
    long cardnumber = get_long("Number: ");

    return 0;
}

bool checksum(long cardnumber){
    /*
    Luhn's Algorithm:
    1. multiply every other digit by 2, starting with second-to-last digit
    2. add those products' digits together
    3. add the sum to the sum of the digits that weren't multiplied by 2
    4. if the total's last digit is 0, then the number is valid
    */
    return true;
}