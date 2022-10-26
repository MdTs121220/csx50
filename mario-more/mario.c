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

    
}