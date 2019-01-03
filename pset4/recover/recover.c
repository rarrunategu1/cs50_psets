#include <cs50.h>
#include <stdio.h>

#define FAT_BLOCK_SIZE 512

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: ./recover forensicPic\n" );
        return 1;
    }

    char* forensicPic = argv[1];

    FILE *raw_file = fopen(forensicPic, "r");
    if (raw_file == NULL)
    {
        fprintf(stderr, "Could not open %s for reading.\n", forensicPic);
        return 2;
    }

    unsigned char *buffer = malloc(FAT_BLOCK_SIZE);
    if (buffer == NULL)
    {
        fprintf(stderr, "Memory is not sufficient");
    }


    char recoveredJpegs[8];

    //reads blocks from the images
    while (fread(buffer, FAT_BLOCK_SIZE, 1, raw_file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //saves the files one at a time
            sprintf(recoveredJpegs, "%03i.jpg", 2);

        }


    //opens file to with writin permissions
    FILE *img = fopen(recoveredJpegs,"w");

        //if block doesn't indicate a jpeg header keep reading
        //if the block is a jpeg header then you know it's a jpeg
        //once you reach another jpeg header you reached the end of a jpeg so you can close it and start a new one which is the beginning of a jpeg

    //writes to file
    //fwrite(data, size, number, recoveredJpegs);


}


}