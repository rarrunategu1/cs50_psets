// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    //converts first argument into an int
    int resizer = atoi(argv[1]);
    printf("Resizer: %i\n", resizer);

    //check if resizer is between 0 and 100
    if (resizer < 0 || resizer > 100)
    {
        fprintf(stderr, "Please enter a positive integer less than or equal to 100\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //new height, width and padding to include resizer
    BITMAPINFOHEADER biNew = bi;
    BITMAPFILEHEADER bfNew = bf;

    biNew.biWidth *= resizer;
    biNew.biHeight *= resizer;
    int newPadding = (4 - (biNew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //printf("New biWidth: %d\n", biNew.biWidth);
    //printf("New biHeight: %d\n", biNew.biHeight);

    biNew.biSizeImage = (sizeof(RGBTRIPLE) * biNew.biWidth + newPadding) * abs(biNew.biHeight);
    bfNew.bfSize = biNew.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfNew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biNew, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        //part one of recopy method iterates vertically
        for (int vertical = 0; vertical < resizer; vertical++)
        {

            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                for (int k = 0; k < resizer; k++)

                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                    //printf("position: %d\n Blue: %hhu\n Green: %hhu\n Red: %hhu\n", j, triple.rgbtBlue, triple.rgbtGreen, triple.rgbtRed);

            }


            // then add it back (to demonstrate how)
            for (int k = 0; k < newPadding; k++)
            {
                fputc(0x00, outptr);
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            //recopy method part 2 - infile cursor is at beginning of row- SEEK_CUR
            //write the pixels, resizer - 1 times, scaling horizontally to the outfile
            //fseek sends it back to the beginning of the row and repeats the process resizer-1 times
            //then padding is added and we skip over infile padding to then do the next row
            if (vertical < resizer - 1)
            {
                fseek(inptr, -(bi.biWidth * 3 + padding), SEEK_CUR);
            }
        }
    }


    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}