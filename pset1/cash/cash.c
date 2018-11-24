#include <cs50.h>
#include <stdio.h>
#include <math.h>



int main(void)
{
    float change;
    //array of coins being used
    int coin [4] = {25, 10, 5, 1};
    //total coins counter
    int totalCoins = 0;
    //validation for non-negative number input
    do
        {
        change = get_float("Change owed: ");

        }
    while (change < 0);
    //converts dollars to cents
    change = change * 100;
    //takes the change and rounds it up as an inteer
    int cents = (int) round(change * 100) / 100.0;
     //for loop goes through coin array
     for (int i = 0; i < 4; i++)
    {
        //while coin in array is less than or equal to change it continues to subtract the coin from the change
        // <= will bring the change to a zero value so that all change is given with the coins
        while (coin[i] <= cents)
        {
            cents = cents - coin[i];
            totalCoins++;
        }
    }
    printf("%i\n", totalCoins);


}


