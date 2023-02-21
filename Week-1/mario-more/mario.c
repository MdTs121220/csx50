//---------------------------------
//From our beloved Land of Papua we write this code
//
//
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


        for (int hashes = height + row + 1; hashes > height; hashes--) //right
        {
            printf("#");
        }
        printf("  ");

        for (int hashes = height + row + 1; hashes > height; hashes--) //left
        {
            printf("#");
        }
        printf("\n");
    }
}