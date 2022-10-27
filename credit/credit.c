#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long n = get_long("Entry Number: "); // Prompt Input card number

    // Calculate the length
    int i = 0;
    long l = n;
    while (l > 0)
    {
        l = l / 10;
        i++;
    }

    if (i != 13 && i != 15 && i != 16) // Check length number if valid
    {
        printf("INVALID\n");
        return 0;
    }

    // Calculate sum
    int jum1 = 0;
    int jum2 = 0;
    long x = n;
    int total = 0;
    int d1;
    int d2;
    int modu1;
    int modu2;
    do
    {
        // Remove last digit
        modu1 = x % 10;
        x = x / 10;
        jum1 = jum1 + modu1;

        // Remove second last digit
        modu2 = x % 10;
        x = x / 10;

        // 2 times second last digit and add digits to sum2
        modu2 = modu2 * 2;
        d1 = modu2 % 10;
        d2 = modu2 / 10;
        jum2 = jum2 + d1 + d2;
    }
    while (x > 0);
    total = jum1 + jum2;

    if (total % 10 != 0) // Checking
    {
        printf("INVALID\n");
        return 0;
    }
    // Starting digits
    long start = n;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // Checking starting digits for the card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}