#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argk, string argv[])
{
    int key = 0;
    int alphaIndex = 0;

    if (argk == 2)
    {
        //turns key input to an integer from a string
        key = atoi(argv[1]);


    //gets user plaintext input
    string message = get_string("plaintext: ");
    //printf("%s\n", message);
    printf("cyphertext: ");

    for(int i = 0; i < strlen(message); i++)
    {
        //printf("%c\n", message[i]);

        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                printf("%c", (((message[i] - 'A') + key) % 26) + 'A');
            }
            else if (islower(message[i]))
            {
                printf("%c", (((message[i] - 'a') + key) % 26) + 'a');
            }
        }
        else if(isalpha(message[i]) == 0)
            {
                printf("%c", message[i]);
            }
        }
    }
else
{
    printf("USAGE: arguments key \n");
    return 1;
}
    printf("\n");
    return 0;
}


