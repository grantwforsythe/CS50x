#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // calculate the average and round
            // update values
            float avg = (image[y][x].rgbtBlue + image[x][y].rgbtGreen + image[x][y].rgbtRed) / 3;
            int value = round(avg);
            image[y][x].rgbtBlue = value;
            image[y][x].rgbtGreen = value;
            image[y][x].rgbtRed = value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
