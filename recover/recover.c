#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int count = 0;
    if(argc != 2)
    {
        printf("Please enter only one argument");
        return 1;
    }
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if(!file)
    {
        printf("Cannot open the file");
        return 1;
    }
    uint8_t data[512];
    FILE *img = NULL;
    char newfile[16];
    while(fread(&data, 1, 512, file) == 512)
    {
        
        if(data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff && (data[3] & 0x0f0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            
            sprintf(newfile, "%03i.jpg", count++);
            img = fopen(newfile, "w");
            if (!img)
            {
                printf("Cannot open the file");
                fclose(file);
                return 1;
            }
            
            
        }
        if (img != NULL)
            {
                fwrite(data, 1, 512, img);
            }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);
    return 0;
}