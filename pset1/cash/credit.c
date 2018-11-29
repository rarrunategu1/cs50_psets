#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX16 5599999999999999
#define MAXV16 4999999999999999
#define MIN16 4000000000000000

#define MAX15 379999999999999
#define MIN15 370000000000000

#define MAX13 4999999999999
#define MIN13 4000000000000

int main(void)
{
    long long ccnum = get_long_long("Number: ");
    int length = 0;
    printf("%lld\n", ccnum);

    int firstNumber = 0;
    int secondNumber = 0;
    int firstTwo = 0;

    if (ccnum >= MIN16 && ccnum <= MAX16)
    {
        length = 16;
    }

    else if (ccnum >= MIN15 && ccnum <= MAX15)
    {
        length = 15;
    }

    else if (ccnum >= MIN13 && ccnum <= MAX13)
    {
        length = 13;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    if (length <= 16)
        for (; length > 0; length--)
        {
            //gets each digit in the card number
            int number = ccnum % 10;
            ccnum = ccnum / 10;

            //takes the number at length 1 and assigns the number adds then number to firstNumber
            if (length == 1)
            {
                firstNumber +=  number;
            }
            //takes the number at length 2 and assigns the number adds then number to secondNumber
            if (length == 2)
            {
                secondNumber += number;
            }
        }

    firstTwo = firstNumber + secondNumber;

    //checks if the card is a master or visa based on first digits
    if (firstNumber == 4)
    {
        printf("VISA\n");
    }
    else if (firstNumber == 5 && firstTwo >= 6 && firstTwo <= 10)
    {
        printf("MASTERCARD\n");
    }
    else if (firstNumber == 3 && (firstTwo == 7 || firstTwo == 10))
    {
        printf("AMEX\n");
    }


    int timesTwo = 0;
    int noTimes = 0;
    int final = 0;

    for (; length > 0; length--)
    {
        int digit = ccnum % 10;
        ccnum = ccnum / 10;

        //grabs every even number length digit starting at end of card - Lughns algorithm
        if (length % 2 == 0)
        {
            int temp = digit * 2;
            timesTwo += temp % 10 + temp / 10;
        }
        else
        {
            noTimes += digit;
        }


    }
    //printf("timesTwo: %i\tnoTimes: %i\n", timesTwo, noTimes);
    final = noTimes + timesTwo;

    //if last digit of the final answer is 0 then the card is valid
    if (final % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }


}