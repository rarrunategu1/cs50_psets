#include <cs50.h>
#include <stdio.h>

#define BLOCK "#"
#define SPACE " "

int main(void)
{
    int height;
    do
    {
      height = get_int("Height: ");
    }
    while(height <= 0 || height >= 23);

    int i;
    for (i = 0; i < height; i++)
    {
        printf("%s\n", BLOCK);
    }
}