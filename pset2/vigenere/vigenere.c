#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argv, string argk[])
{
    if (argv == 2 && isalpha(argk[1]))
    {
        printf("argument: %s\n", argk[1]);
    }
    else
    {
        printf("USAGE: argument keyword\n");
        return 1;
    }
}
