#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argk, string argkey[])
{
    string keyWord = argkey[1];
    int keyLength = 0;
    int letter = 0;
    string message;

    //if no keyword is given then an error returns
    if (argk != 2)
    {
        printf("USAGE: arguments key \n");
        return 1;
    }

    //for loop stores the length of the keyword and checks is the keyword is alpha, if not alpha error returns
    for (int i = 0, j = strlen(keyWord); i < j; i++)
    {
        keyLength = i;
        //printf("%c", keyWord[i]);

        if (isalpha(keyWord[i]))
        {
            continue;
        }
        else
        {
            printf("USAGE: %s Alpha Keyword Only\n", argkey[0]);
            return 1;
        }
    }

    //if there are two arguments we ask the user for a message
    if (argk == 2)
    {
        message = get_string("plaintext: ");
        printf("ciphertext: ");
    }

    //make the keylength it's actual length and not the ending position
    int keyLengthTotal = keyLength + 1;

    for (int i = 0, j = 0, length = strlen(message); i < length; i++)
    {
        //if alpha is true will return the character based on if uppercase or lowercase
        if (isalpha(message[i]))
        {
            printf("%c", keyWord[j]);
            // char keyAscii = (isupper(keyWord[j % keyLengthTotal])) ? 'A' : 'a';



            // if (isupper(message[i]))

            // {
            //     printf("%c", ((message[i] - 'A') + (keyWord[j % keyLengthTotal] - keyAscii) % 26) + 'A');

            // }
            // else if(islower(message[i]))
            // {
            //     printf("%c", ((message[i] - 'a') + (keyWord[j % keyLengthTotal] - keyAscii) % 26) + 'a');
            // }

            //calculates the ascii of each key position and wraps it around when it gets to the end.
            // char keyAscii = (isupper(keyWord[j % keyLengthTotal])) ? 'A' : 'a';

            // //calculates the ascii of each message position
            // char messageAscii = (isupper(message[i])) ? 'A' : 'a';

            //gets index value every letter of the message + the keyword index value with wrap around
            // minus the ascii of each key position, then we wrap around the alphabet if need be and turn it back into ascii code
            //printf("%c", ((message[i] - messageAscii) + (keyWord[j % keyLengthTotal] - keyAscii) % 26) + messageAscii);
        }
        //if there is a character that is not alpha then it will print the character as is
        else if (isalpha(message[i]) == 0)
        {
            //printf("%c", message[i]);
        }
    }

    printf("\n");
    return 0;
}