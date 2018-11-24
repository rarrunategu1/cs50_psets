#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    // float coin [4] = {0.25, 0.10, 0.05, 0.01};
    // int totalCoins = 0;
    do
        {
        change = get_float("Change owed: ");

        }
    while(change < 0);
    change = change * 100;


    printf("%f\n", change);


    //printf("%.2f\n", change * 100);

}
