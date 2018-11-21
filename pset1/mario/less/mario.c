#include <cs50.h>
#include <stdio.h>

#define BLOCK "#"

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);
    for (int i = 0; i < height; i++)
    {

        printf(".");
        printf(BLOCK);
        printf("\n");
    }
}