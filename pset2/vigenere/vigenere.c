#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argk, string argkey[])
{
    string keyword = argkey[1];
    int index = 0;
    int letter = 0;

    for (int i = 0; i < strlen(keyword); i++)
    {
        index = i;
        letter = keyword[i];

        if (isalpha(keyword[i]))
        {
            continue;
        }
        else
        {
            printf("USAGE: %s k\n", argkey[0]);
            return 1;
        }
    }
    //printf("position: %i\t letter: %c\n", index, letter);
    if (argk == 2)
    {
        //gets user plaintext input
        string message = get_string("plaintext: ");
        //printf("%s\n", message);
        printf("ciphertext: ");

        for (int i = 0, j = 0, length = strlen(message); i < length; i++, j++)
        {

            //if alpha is true will return the character based on if uppercase or lowercase
            if (isalpha(message[j]))
            {

                    if (isupper(message[j]))
                    {
                        printf("%c", (message[j] - 'A') + 'A');
                    }
                    else if (islower(message[j]))
                    {
                        printf("%c", (message[j] - 'a') + 'a');
                    }

                    //printf("plaintext: %c\t cypherletter: %c\t position: %i\n",  message[j], letter, index);

                }

            //if there is a character that is not alpha returning 0 then it will print the character as is
            else if (isalpha(message[j]) == 0)
            {
                //printf("%c", message[j]);
            }
}

    }
    else
    {
        //prints error message if an argument if there are more or less than 2 arguments
        printf("USAGE: %s k\n", argkey[0]);
        return 1;
    }
    printf("\n");
    return 0;
 }


