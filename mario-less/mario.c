#include <cs50.h>
#include <stdio.h>

int main(void)
{
     int height;


    do
    {
    height = get_int("Height: \n");  //Input height first
    }

     // The user can only input a Height between 1 and 8
    while
    ((height < 1) || (height > 8));

    // for loop to create the height of the row
    for (int row = 0; row < height; row++)
    {
        // for loop create the width of the piramid
        for (int column = 0; column < height; column++)
        {
            // if row plus column is greater than or equal than height -1 space print the hashes
            if (row + column >= height - 1)
                printf("#");

            // adding spaces
            else
            printf(" ");
        }
        printf("\n");
    }
}