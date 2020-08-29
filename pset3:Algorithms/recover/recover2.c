#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>


int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
    // ALL the declarations
    int test_array[2];
    // int i=0;
    unsigned char *arr=(unsigned char*)malloc(sizeof(unsigned char)*4);         //Declaring array to store first 4bytes of jpg
    char filename[20];                              //Declaring array to store jpg filenames
    unsigned char *image=(unsigned char*)malloc(sizeof(unsigned char)*500);    // Declaring array to store bytes if its is a jpg
    char *infile= argv[1];
    FILE *card_raw=fopen(infile,"r");
    if (card_raw == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }



    while (!feof(card_raw))
    {
        fread(arr, sizeof(char), 4,card_raw);
        if (arr[0]==0xff && arr[1]==0xd8 && arr[2]==0xff && (arr[3] & 0xf0)==0xe0 )
        {
            int static i=0;
            fseek(card_raw,-3,SEEK_CUR);
            sprintf(filename,"%03i.jpg",i);
            FILE *img=fopen(filename,"w");
            i++;
            // image[0]
            for(int k=1;image[k]!=0xff && image[k+1]!=0xd8 && image[k+2]!=0xff;k++)
            {
                
                fread(image,sizeof(char),512,card_raw);
                fwrite(image,sizeof(char),512,img);
            }

        }



}
free (arr);
free(image);
// fclose(img);
fclose(card_raw);
}
