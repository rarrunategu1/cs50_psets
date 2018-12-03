#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argk, string argkey[])
{
    int key = 0;

    if (argk == 2)
    {
        //turns key input to an integer from a string
        key = atoi(argkey[1]);


        //gets user plaintext input
        string message = get_string("plaintext: ");
        //printf("%s\n", message);
        printf("cyphertext: ");

        for (int i = 0; i < strlen(message); i++)
        {
            //printf("%c\n", message[i]);

            //if alpha is true will return the character based on if uppercase or lowercase
            if (isalpha(message[i]))
            {
                if (isupper(message[i]))
                {
                    //takes character,converts it to a 0-26 alpha index, adds the key,
                    //modulus allows it to go from z to a or Z to A and we add the Ascii
                    //'A' a the end to get the ascii character back
                    printf("%c", (((message[i] - 'A') + key) % 26) + 'A');
                }
                else if (islower(message[i]))
                {
                    printf("%c", (((message[i] - 'a') + key) % 26) + 'a');
                }
            }
            //if there is a character that is not alpha returning 0 then it will print the character as is
            else if (isalpha(message[i]) == 0)
            {
                printf("%c", message[i]);
            }
        }
    }
    else
    {
        //prints error message if an argument if there are more or less than 2 arguments
        printf("USAGE: arguments key \n");
        return 1;
    }
    printf("\n");
    return 0;
}


