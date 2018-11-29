#include <stdio.h>
#include <cs50.h>

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
        for (; length > 0; length--)
        {
            int number = ccnum % 10;
            //printf("length: %i\tDigit: %i\n", length, number);
            ccnum = ccnum / 10;

            if (length == 1)
            {
                firstNumber +=  number;
            }
            if (length == 2)
            {
                secondNumber += number;
            }
        }
        firstTwo = firstNumber + secondNumber;

        if (firstNumber == 4)
        {
            printf("VISA\n");
        }

        else if (firstNumber == 5 && firstTwo >= 6 && firstTwo <= 10)
        {
            printf("MASTERCARD");
        }

    }

    else if (ccnum >= MIN15 && ccnum <= MAX15)
    {
        length = 15;
        for (; length > 0; length--)
        {
            int number = ccnum % 10;
            //printf("length: %i\tDigit: %i\n", length, number);
            ccnum = ccnum / 10;

            if (length == 1)
            {
                firstNumber +=  number;
            }
            if (length == 2)
            {
                secondNumber += number;
            }
        }
        firstTwo = firstNumber + secondNumber;
        if (firstNumber == 3 && (firstTwo == 7 || firstTwo == 10))
        {
            printf("AMEX\n");
        }
    }

    else if (ccnum >= MIN13 && ccnum <= MAX13)
    {
        length = 13;
        for (; length > 0; length--)
        {
            int number = ccnum % 10;
            //printf("length: %i\tDigit: %i\n", length, number);
            ccnum = ccnum / 10;

            if (length == 1)
            {
                firstNumber +=  number;
            }

        }



        if (firstNumber == 4)
        {

            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }

    int timesTwo = 0;
    int noTimes = 0;
    int final = 0;

    for (; length > 0; length--)
    {
        int digit = ccnum % 10;
        //printf("length: %i\tDigit: %i\n", length, digit);
        ccnum = ccnum / 10;

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


    if (final % 10 == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }


}