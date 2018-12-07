#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argv, string argkey[])
{

    //if no keyword is given then an error returns
    if (argv != 2)
    {
        printf("USAGE: arguments key\n");
        return 1;
    }

    string keyWord = argkey[1];
    int keyLength = strlen(keyWord);
    string message;

    //if the keyword is not alpha prints an error
    for (int i = 0; i < keyLength; i++)
    {

        if (!isalpha(keyWord[i]))

        {
            printf("USAGE: %s Alpha Keyword Only\n", argkey[0]);
            return 1;
        }
    }

    //if there are two arguments we ask the user for a message
    if (argv == 2)
    {
        message = get_string("plaintext: ");
        printf("ciphertext: ");
    }

    for (int i = 0, index = 0, length = strlen(message); i < length; i++)
    {

        //if alpha is true will return the character based on if uppercase or lowercase
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                printf("%c", (message[i] - 'A' + toupper(keyWord[index]) - 'A') % 26 + 'A');
            }
            else if (islower(message[i]))
            {
                printf("%c", (message[i] - 'a' + tolower(keyWord[index]) - 'a') % 26 + 'a');
            }
            //allows the keyword to wrap around
            index = (index + 1) % keyLength;

        }
        //if there is a character that is not alpha then it will print the character as is
        else if (isalpha(message[i]) == 0)
        {
            printf("%c", message[i]);
        }
    }

    printf("\n");
    return 0;
}