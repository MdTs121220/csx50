//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//mario-more.c
//---------------------------------
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");  //Input height first
    }

    while ((height < 1) || (height > 8));  // boolean logic use OR

    // for loop
    for (int row = 0; row < height; row++)

    {

        for (int column = 0; column < height; column++) // piramid create
        {
            if (row + column >= height - 1)
            {
                printf("#");
            }

            else
            {
                printf(" "); //space
            }
        }
        printf("\n");
    }
}