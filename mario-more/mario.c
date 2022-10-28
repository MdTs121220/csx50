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

    while
    ((height < 1) || (height > 8));  // boolean logic use OR

    // for loop
    for (int row = 0; row < height; row++)

    {

        for (int column = row + 1; column < height; column++)
        {
            printf(" "); //space
        }


        for (int pagar = height + row + 1; pagar > height; pagar--) //right
        {
            printf("#");
        }
        printf("  ");

        for (int pagar = height + row + 1; pagar > height; pagar--) //left
        {
            printf("#");
        }
        printf("\n");
    }
}