#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: ./recover forensicPic\n" );
        return 1;
    }

    char* forensicPic = argv[1];

    FILE *image = fopen(forensicPic, "r");
    if (image == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", forensicPic);
        return 2;
    }
}