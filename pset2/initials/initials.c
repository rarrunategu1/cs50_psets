#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("");
    printf("%s\n", name);

    for (int i = 0; i < strlen(name); i++)
    {
        //get each character in input
        //printf("%c\n", name[i]);

        //gets first character of the name and capitalizes it
        if (i == 0)
        {
            printf("%c", toupper(name[i]));
        }
        //gets every letter after a space and capitalizes it
        else if (name[i] == 32)
        {
            i++;
            printf("%c", toupper(name[i]));
        }
    }
    printf("\n");
}