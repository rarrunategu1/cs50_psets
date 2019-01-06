#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

    uint8_t buffer[FAT_BLOCK_SIZE];
    bool jpeg_found = false;
    FILE* img = NULL;
    char recoveredJpegs[50];
    int fileCount = 0;

    //reads blocks from the images
    while (fread(&buffer, 1, FAT_BLOCK_SIZE, raw_file))
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(!jpeg_found)
            {
                jpeg_found = true;

                //saves the files one at a time
                sprintf(recoveredJpegs, "%03i.jpg", fileCount++);
                //opens file to with writin permissions
                img = fopen(recoveredJpegs,"w");
                if (img == NULL)
                 {
                    fprintf(stderr, "Could not open %s for reading.\n", forensicPic);
                    return 3;
                }
                fwrite (&buffer, 1, 512, img);
        }
        else
        {
            fclose(img);

            sprintf(recoveredJpegs, "%03i.jpg", fileCount++);
            //opens file to with writin permissions
            img = fopen(recoveredJpegs,"w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not open %s for reading.\n", forensicPic);
                return 3;

            }
            fwrite (&buffer, 1, 512, img);
         }

    }
    // else
    // {
    //     if(jpeg_found)
    //     {
    //         fwrite(&buffer, 1, 512, img);
    //     }
    // }
}
    // close infile
    fclose(raw_file);

    // close outfile
    fclose(img);

    // success
    return 0;

}