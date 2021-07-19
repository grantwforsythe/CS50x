// TOOD : check if the card is vaild using Luhn's Algorithm

#include <cs50.h> // get_long()
#include <stdio.h> // printf()
#include <stdlib.h> // convert string to int
#include <string.h> // strlen()

typedef char *string;

// Prototyping
bool checksum(string cardnumber);

// Constants
const int AMEX_LEN = 15;
const int MC_LEN = 16;
const int VISA_LEN_13 = 13;
const int VISA_LEN_16 = 16;

int main(void) {

    long cardnumber_long = get_long("Number: ");
    char cardnumber[16];
    sprintf(cardnumber,"%ld", cardnumber_long); // convert long to string
    bool valid = checksum(cardnumber);

    // convert char to int
    // typecasting wasn't working for some reason
    int first_num = cardnumber[0] - '0';
    int second_num = cardnumber[1] - '0';

    // if checksum isn't False, than it has to be True
    if (!(valid)) {
        printf("INVALID\n");
    } else if (first_num == 4) {
        printf("VISA\n");
    } else if (first_num == 5 && (second_num > 1 && second_num < 5)) {
        printf("MASTERCARD\n");
    } else if (first_num == 3 && second_num == 4) {
        printf("AMEX\n");
    } else {
        return 1;
    }

    return 0;

}

bool checksum(string cardnumber){
    /*
    Apply Luhn's Algorithm:
    1. multiply every other digit by 2, starting with second-to-last digit
    2. add those products' digits together
    3. add the sum to the sum of the digits that weren't multiplied by 2
    4. if the total's last digit is 0, then the number is valid
    */
    int card_len = strlen(cardnumber);
    int sum = 0;

    if (card_len != AMEX_LEN && card_len != MC_LEN && card_len != VISA_LEN_13 && card_len != VISA_LEN_16) {
        return false;
    }

    for (int i = 0; i < card_len; i ++) {
        if ( i % 2 == 0) {
           sum += cardnumber[card_len - i];
        } else {
            sum += (cardnumber[card_len - i] - '0') * 2;
        }
    }

    if (sum % 10 == 0) {
        return true;
    } else {
        return false;
    }
}
