#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // calculate the average and round
            float avg = (float) (image[row][col].rgbtBlue + image[row][col].rgbtGreen + image[row][col].rgbtRed) / 3.0;
            int value = round(avg);

            // update values
            image[row][col].rgbtRed = value;
            image[row][col].rgbtGreen = value;
            image[row][col].rgbtBlue = value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    /*
    sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    */
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            // calculate the values and round
            int values[3];
            values[0] = round(.393 * image[row][col].rgbtRed + .769 * image[row][col].rgbtGreen + .189 * image[row][col].rgbtBlue);
            values[1] = round(.349 * image[row][col].rgbtRed + .686 * image[row][col].rgbtGreen + .168 * image[row][col].rgbtBlue);
            values[2] = round(.272 * image[row][col].rgbtRed + .534 * image[row][col].rgbtGreen + .131 * image[row][col].rgbtBlue);

            // conditionals
            for (int i = 0; i < 3; i++) {
                if (values[i] > 255) {
                    values[i] = 255;
                }
            }

            // update values
            image[row][col].rgbtRed = values[0];
            image[row][col].rgbtGreen = values[1];
            image[row][col].rgbtBlue = values[2];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int num_cols = floor((float) width / 2.0);
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < num_cols; col++) {
            RGBTRIPLE temp = image[row][col];
            image[row][col] = image[row][width - col - 1];
            image[row][width - col - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
