//---------------------------------
//Markus Dwiyanto Tobi Sogen
//CS50 for teachers
//Indonesia
//Filter-less.c
//---------------------------------
#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through each pixel kolom dan baris
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red = image[i][j].rgbtRed;
            int Green = image[i][j].rgbtGreen;
            int Blue = image[i][j].rgbtBlue;
            average = round(((float)Red + (float)Green + (float)Blue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

//konvert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the height (kolom)
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaBlue, sepiaGreen;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //iterate through the width (baris)
        {
            //try assign variable array
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            //calculate for sepia
            sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            //calculate for sepiaGreen
            sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            //calculate for sepiaBlue
            sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue); //Calculate for sepiaBlue
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through the height and half of width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            //create temporary variable
            int temPred = image[i][j].rgbtRed;
            int temPgreen = image[i][j].rgbtGreen;
            int temPblue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtRed = temPred;
            image[i][width - j - 1].rgbtGreen = temPgreen;
            image[i][width - j - 1].rgbtBlue = temPblue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a temporary image blur
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;

            //Get the next pixel
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1)) //check next pixel
                    {
                        continue;
                    }

                    total_Red += image[currentX][currentY].rgbtRed;
                    total_Green += image[currentX][currentY].rgbtGreen;
                    total_Blue += image[currentX][currentY].rgbtBlue;
                    counter++;
                }

                //do the average pf pixel
                temp[i][j].rgbtRed = round(total_Red / counter);
                temp[i][j].rgbtGreen = round(total_Green / counter);
                temp[i][j].rgbtBlue = round(total_Blue / counter);
            }
        }
    }

    //copy the blurr image to image ori
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}