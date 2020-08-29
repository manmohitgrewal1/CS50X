#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }
    //Assigning command line argument to a pointer
    char *infile = argv[1];
    // Opening file and assigning the return to a pointer
    FILE *mcard = fopen(infile, "r");
    //Declaring a array with size 512
    BYTE buffer[512];
    //Declaring output file
    FILE *img;
    // Declaring array for storing file names
    char filename[20];
    //counter variable for numbering filename
    int i = 0;
    bool first_time = true;
    bool conti_run = false;
    bool new_flag = false;
    // While loop that will suspend when file ends
    while (fread(buffer, 512, 1, mcard)==1)
    {
        //reading the file

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0  && first_time)
        {
            first_time = false;
            sprintf(filename, "%03i.jpg", i);
            i++;
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            conti_run = true;
            continue;
        }
        if (conti_run)
        {
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", i);
                i++;
                img = fopen(filename, "w");
                new_flag = true;
            }
            if (new_flag)
            {
                fwrite(buffer, 512, 1, img);
                continue;
            }
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(mcard);
    // Success
    return 0;
}
