#include <stdio.h>
#include <cs50.h>

#define MAX16 5599999999999999
#define MIN16 4000000000000000

#define MAX15 379999999999999
#define MIN15 370000000000000

#define MAX13 49999999999999
#define MIN13 40000000000000

int main(void)
{
    long long ccnum = get_long_long("Number: ");
    int length = 0;
    printf("%lld\n", ccnum);

    if (ccnum >= MIN16 && ccnum <= MAX16)
    {
        printf("card may be Visa or Mastercard\n");
        length = 16;

    }
    else if(ccnum >= MIN15 && ccnum <= MAX15)
    {
        printf("card may be an AMEX\n");
        length = 15;

    }
    else if(ccnum >= MIN13 && ccnum <= MAX13)
    {
        printf("card may be a Visa\n");
        length = 13;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }





    int timesTwo = 0;
    int noTimes = 0;
    int final = 0;
    int firstnumber = 0;
    int secondnumber = 0;

    for(; length > 0; length--)
    {
        int digit = ccnum % 10;
        //printf("length: %i\tDigit: %i\n", length, digit);
        ccnum = ccnum / 10;

        if (length == 1 && digit == 4)
        {
            printf("VISA\n");
        }

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