
#include <cs50.h>
#include <stdio.h>

//used for building the ladder
#define BLOCK "#"
#define SPACE " "

int main(void)
{
    //validation checks to check if user input for height is between 0 and 23 or it keeps asking
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    //first for loop iterates through height input to print as many lines as the input
    int i;
    for (i = 0; i < height; i++)
    {
        //2nd for loop: j = height plus 1 to take in entire height printed and prints one less space as long as j is less than i+2 which would equl entire height of the ladder printed
        for (int j = height + 1; j > i + 2; j--)
        {
            printf(SPACE);
        //3rd for loop: k = 0 to build the ladder with the hashes.  adds one has as long as k is less than i plus two(height of ladder printed)
        }
        for (int k = 0; k < i + 2; k++)
        {
            printf(BLOCK);
        }

        printf("\n");

    }

}