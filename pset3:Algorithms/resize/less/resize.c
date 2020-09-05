#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
     int n= atoi(argv[1]);
     if (n < 1 || n > 100)
    {
        printf("The argv \"n\" is out of range\n");
        return 5;
    }

    char *infile = argv[2];
    char *outfile = argv[3];

    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    BITMAPFILEHEADER bf;                                                                    // read infile's BITMAPFILEHEADER
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;                                                                    // read infile's BITMAPINFOHEADER
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)                                       // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    BITMAPINFOHEADER nw_bi=bi;
    BITMAPFILEHEADER nw_bf=bf;

     nw_bi.biWidth=(bi.biWidth*n);
    nw_bi.biHeight=(bi.biHeight*n);
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;   // determine old padding for scanlines
    int nw_padding= (4 - (nw_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;    // determining new padding
    nw_bi.biSizeImage= ((sizeof(RGBTRIPLE)* nw_bi.biWidth)*abs(nw_bi.biHeight) + nw_padding* abs(nw_bi.biHeight));  // new bisize update
    nw_bf.bfSize=nw_bi.biSizeImage+ sizeof(BITMAPFILEHEADER)+ sizeof(BITMAPINFOHEADER);    // new bfsize


    fwrite(&nw_bf, sizeof(BITMAPFILEHEADER), 1, outptr);  // write outfile's BITMAPFILEHEADER
    fwrite(&nw_bi, sizeof(BITMAPINFOHEADER), 1, outptr);  // write outfile's BITMAPINFOHEADER

    // RGBTRIPLE *arr= (RGBTRIPLE*)malloc(n*bi.biWidth*sizeof(RGBTRIPLE));
    // int allo_size= n*bi.biWidth*sizeof(RGBTRIPLE);
    // printf("Allocated size of malloc: %d\n", allo_size);

    
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)   // iterate over infile's scanlines
    {
      for (int ntimes = 0; ntimes < n; ntimes++)
      {
        // set pointer to beginning of line
        fseek(inptr, 54 + (bi.biWidth * 3 + padding) * i, SEEK_SET);
        for (int j = 0; j < bi.biWidth; j++)     // iterate over pixels in scanline
            {

                RGBTRIPLE triple;
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);   // read RGB triple from infile
                                printf("Reading now %d %d %u %u %u\n",i, j,triple.rgbtRed, triple.rgbtGreen, triple.rgbtBlue);

                for (int hor=0;hor<n;hor++)  //Horizontal looping
                {
                    fwrite(&triple,sizeof(RGBTRIPLE),1,outptr);
                }
            }

            fseek(inptr, padding, SEEK_CUR);
            for (int k = 0; k < nw_padding; k++)
                    {
                        fputc(0x00, outptr);
                    }
      }
    }


    fclose(inptr);  // close infile
    fclose(outptr);   // close outfile
    return 0;
}