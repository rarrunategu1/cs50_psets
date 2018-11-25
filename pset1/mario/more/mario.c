#include <cs50.h>
#include <stdio.h>

//reusability purposes
#define BLOCK "#"
#define SPACE " "

int main(void)
{
    //validation checks that the user's height input is a non-negative number that is no greater than 23
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    //for loop iterates through height input
    int i;
    for (i = 0; i < height; i++)
    {

        //for loop prints spaces on the left side of first stair case
        for (int j = height + 1; j > i + 2; j--)
        {
            printf(SPACE);
        }
        //for loop prints #'s forming the first stair case
        for (int k = 0; k < i + 1; k++)
        {
            printf(BLOCK);
        }
        //for loop prints double space between the staircases
        for (int l = 0; l < 2; l++)
        {
            printf(SPACE);
        }
        //for loop creates the 2nd staircase with the #'s
        for (int m = 0; m < i + 1; m++)
        {
            printf(BLOCK);
        }

        printf("\n");
    }
}
