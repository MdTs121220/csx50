//---------------------------------
//-- From our beloved Land of Papua we write this code
//--
//--
//Recover.c
//---------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //try argc to equal two
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    else
    {
        // try to open card raw
        char *input_file_name = argv[1];
        FILE *input_pointer = fopen(input_file_name, "r"); //input file in read mode
        if (input_pointer == NULL)
        {
            printf("Error: cannot open %s\n", input_file_name);
            return 2;
        }

        // Initialise variables byte
        BYTE buffer[512];
        int count = 0;
        FILE *img_pointer = NULL;
        char filename[8];
        // Repeat until end
        while (fread(&buffer, 512, 1, input_pointer) == 1)
        {
            // try check If start of a new JPEG (Byte start*):
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            {
                // If not, close
                if (!(count == 0))
                {
                    fclose(img_pointer);
                }

                // Initialise file
                sprintf(filename, "%03i.jpg", count);
                img_pointer = fopen(filename, "w");
                count++;
            }

            // If JPEG has been found, try write to file
            if (!(count == 0))
            {
                fwrite(&buffer, 512, 1, img_pointer);
            }
        }
        fclose(input_pointer);
        fclose(img_pointer);
        return 0;
    }
}