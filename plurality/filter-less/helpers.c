#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int h, int w, RGBTRIPLE image[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int h, int w, RGBTRIPLE image[h][w])
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int h, int w, RGBTRIPLE image[h][w])
{
    for (int i = 0; i < h; i++)
    {
        if (w % 2 == 0)
        {
            for (int j = 0; j < w / 2; j++)
            {
                RGBTRIPLE tmp[h][w];
                tmp[i][j] = image[i][j];
                image[i][j] = image[i][w - (j + 1)];
                image[i][w - (j + 1)] = tmp[i][j];
            }
        }

        else if (w % 2 != 0)
        {
            for (int j = 0; j < (w - 1) / 2; j++)
            {
                RGBTRIPLE tmp[h][w];
                tmp[i][j] = image[i][j];
                image[i][j] = image[i][w - (j + 1)];
                image[i][w - (j + 1)] = tmp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int h, int w, RGBTRIPLE image[h][w])
{
    RGBTRIPLE tmp[h][w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            float addBlue = 0;
            float addGreen = 0;
            float addRed = 0;
            float counter = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > h - 1)
                    {
                        continue;
                    }

                    if (j + c < 0 || j + c > w - 1)
                    {
                        continue;
                    }

                    addBlue += image[i + r][j + c].rgbtBlue;
                    addGreen += image[i + r][j + c].rgbtGreen;
                    addRed += image[i + r][j + c].rgbtRed;
                    counter++;
                }
            }

            tmp[i][j].rgbtBlue = round(addBlue / counter);
            tmp[i][j].rgbtGreen = round(addGreen / counter);
            tmp[i][j].rgbtRed = round(addRed / counter);
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }

    }

    return;
}