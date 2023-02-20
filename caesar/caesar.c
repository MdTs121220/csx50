//---------------------------------
//From our beloved Land of Papua we write this code
//
//
//caesar.c
//---------------------------------
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)   //to check if is not equal to 2
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int arg_length = strlen(argv[1]);    //to get the length of string
    for (int i = 0; i < arg_length; i++)  //iterate
    {
        if (!isdigit(argv[1][i]))  //to check if char in argv[1] is not digit
        {
            printf("Usage: ./caesar key");  //print if not
            return 1;
        }
    }

    int key = atoi(argv[1]); //convert string to integer

    string plaintext = get_string("plaintext: ");  //get plaintext to encipher  from prompt user input

    printf("ciphertext: ");     //print the encipher

    int plaintext_length = strlen(plaintext);  //to check the length of plaintext

    for (int i = 0; i < plaintext_length; i++)  //iterate
    {
        if (isupper(plaintext[i]))   // if character is Upper case encipher
        {
            printf("%c", (((plaintext[i] - 65) + key) % 26) + 65);   // calculation encipher the text
        }
        else if (islower(plaintext[i]))  //if character is lower case
        {
            printf("%c", (((plaintext[i] - 97) + key) % 26) + 97);  //calculation encipher the text
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");  //new line
}