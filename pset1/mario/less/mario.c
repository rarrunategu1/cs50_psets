#include <cs50.h>
#include <stdio.h>

#define BLOCK "#"
#define SPACE "."

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);


    int i;
    for (i = 0; i < height; i++)
    {

        for(int k = 0; k<i; k++)
        {
            printf(SPACE);
        }
        for(int j = 0; j<i+2; j++)
        {
            printf(BLOCK);
        }

        printf("\n");

    }

}