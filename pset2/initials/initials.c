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
        //gets each character of the input
        //printf("%c\n", name[i]);
        if (i == 0)
        {
          printf("first letter: %c\n", toupper(name[i]));
        }

    }

}