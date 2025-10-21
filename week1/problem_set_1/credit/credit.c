#include <cs50.h>
#include <stdio.h>
#include <math.h>

const char* checkBank(long cardNumber);
int checkCardNumber(long cardNumber);

int main(void)
{
    long input = 0;
    do
    {
        input = get_long("Number: ");
    }
    while (input < 0);

    if (checkCardNumber(input) == 1)
    {
        printf("%s", checkBank(input));
    }
    else
    {
        printf("INVALID\n");
    }
}

const char* checkBank(long cardNumber)
{

    int count_digit = 0;
    long originalCardNumber = cardNumber;

    while (cardNumber > 0)
    {
        cardNumber /= 10;
        count_digit++;
    }

    // printf("count of digits: %i\n", count_digit);
    // printf("firstdigit: %ld\n", originalCardNumber / (long)(pow(10, 13)));

    // if 15 digit then American Express All American Express numbers start with 34 or 37
    if (count_digit == 15)
    {
        if (originalCardNumber / ((long)pow(10, 13)) == 34 || originalCardNumber / ((long)pow(10, 13)) == 37)
        {
            return "AMEX\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else if (count_digit == 13)
    {
        // if 13 or 16 digit then visa all Visa numbers start with 4
        if (originalCardNumber / ((long)pow(10, 12)) == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else
    {
        if (count_digit == 16)
        {
            // if 13 or 16 digit then visa all Visa numbers start with 4
            if (originalCardNumber / ((long)pow(10, 15)) == 4)
            {
                return "VISA\n";
            }
            // if 16 digit then MasterCard most MasterCard numbers start with 51, 52, 53, 54, or 55
            else if (originalCardNumber / ((long)pow(10, 14)) == 51 || originalCardNumber / ((long)pow(10, 14)) == 52 || originalCardNumber / ((long)pow(10, 14)) == 53 || originalCardNumber / ((long)pow(10, 14)) == 54 || originalCardNumber / ((long)pow(10, 14)) == 55)
            {
                return "MASTERCARD\n";
            }
            else
            {
                return "INVALID\n";
            }
        }
        else
        {
            return "INVALID\n";
        }
    }
}


int checkCardNumber(long cardNumber)
{
    int timesTwo = 0;
    int timesOne = 0;
    int result = 0;

    while (cardNumber > 0)
    {
        int checkSingleNumber = 0;

        // from last digit (not doubled)
        timesOne += cardNumber % 10;
        cardNumber /= 10;

        // from second digit (doubled)
        checkSingleNumber = (cardNumber % 10) * 2;

        if (checkSingleNumber >= 10) // why >= 10 because 5 * 2 = 10
        {
            // 2 digits number of max 18 (9 * 2) we can substract it by -9
            // or manually you can take lastdigit and then take firstdigit and finally sum it (modulus %10 to take lastdigit and divide /10 to lower by tenth)
            timesTwo += (checkSingleNumber - 9);
            cardNumber /= 10;
        }
        else
        {
            timesTwo += checkSingleNumber;
            cardNumber /= 10;
        }
    }

    result = timesOne + timesTwo;


    if (result % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
