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

        for (int spaces = row + 1; spaces < height; spaces++)
        {
            printf(" ");
        }

        // 2nd Nested, prints the actual pyramid
        for (int hashes = height + row + 1; hashes > height; hashes--)
        {
            printf("#");
        }
        printf("\n");
    }
}