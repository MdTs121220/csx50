//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//Cash.c
//---------------------------------
#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long n = get_long("Entry Number: "); // Prompt Input card number

    // Perhitungan panjang angka yang diinput
    int i = 0;
    long l = n;
    while (l > 0)
    {
        l = l / 10;
        i++;
    }

    if (i != 13 && i != 15 && i != 16) // Cek number valid atau gak nya
    {
        printf("INVALID\n");
        return 0;
    }

    // Penjumlahan
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
        // Buang digit terakhir
        modu1 = x % 10;
        x = x / 10;
        jum1 = jum1 + modu1;

        // Remove digit kedua dari belakang
        modu2 = x % 10;
        x = x / 10;

        // modulus dan jumlah digit-digit
        modu2 = modu2 * 2;
        d1 = modu2 % 10;
        d2 = modu2 / 10;
        jum2 = jum2 + d1 + d2;
    }
    while (x > 0);
    total = jum1 + jum2;

    if (total % 10 != 0) // cek angka digit
    {
        printf("INVALID\n");
        return 0;
    }

    long start = n; // Digit pertama dimulai
    do
    {
        start = start / 10;
    }
    while (start > 100);


    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6)) // Checking digit dan jenis kartu
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
//------------END---------------------