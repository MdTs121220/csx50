//---------------------------------
//-- From our beloved Land of Papua we write this code
//--
//--
//---------------------------------
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size:: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size:: ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int n = start_size;
    int calculator = 0;

    if (start_size == end_size) // if else returns 0 if end and start size is 0
    {
        printf("Years: 0");
    }

    do  //looping again
    {
        n = round(n + (n / 3) - (n / 4));
        year += 1;

    }
    while (n < end_size);

    // TODO: Print number of years
    printf("Years: %i\n",  year);
}
//end of program