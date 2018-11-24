#include <cs50.h>
#include <stdio.h>
#include <math.h>



int main(void)
{
    float change;
    int coin [4] = {25, 10, 5, 1};
    int totalCoins = 0;
    do
        {
        change = get_float("Change owed: ");

        }
    while (change < 0);
    change = change * 100;
    int cents = (int) round(change * 100) / 100.0;
     for (int i = 0; i < 4; i++)
    {
        while (coin[i] <= cents)
        {
            cents = cents - coin[i];
            totalCoins++;
        }
    }
    printf("%i\n", totalCoins);


}


