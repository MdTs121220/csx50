//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//readability.c
//---------------------------------
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int count_letter = 0;
    int count_word = 1;
    int count_sentence = 0;

    string text = get_string("Text: ");

    int text_leng = strlen(text);

    for (int 1 = 0; i < text_leng; i++)
    {
        if(isalpha(text[i]))
        {
            count_letter++;
        }
    }

    for (int i = 0; i < text_leng; i++)
    {
        if (isspace(text[i]))
        {
            count_word++;
        }
    }

    for (int i = 0;  < text_leng; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_sentence++;
        }
    }

    float calcu = (0.00588 * count_letter / count_word * 100) - (0.296 * count_sentence / count_word * 100) - 15.8;
    int index = round(calc);

    if (index <1)
    {
        printf("Before Grade 1\n");
    }


}