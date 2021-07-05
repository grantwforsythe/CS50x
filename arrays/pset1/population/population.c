#include <cs50.h>
#include <stdio.h>

// Protyping
int years(int start_size, int end_size);

int main(void)
{
    int start_size, end_size;

    // Prompt for start and end size
    do
    {
        // Start size can't be less than 9 and end size has to be >= start_size
        if (start_size < 9)
        {
            start_size = get_int("Start size: ");
        }
        else
        {
            end_size = get_int("End size: ");
            // If both conditions are met, exit the loop
            if (end_size >= start_size)
            {
                break;
            }
        }

    }
    while (true);

    printf("Years: %i\n", years(start_size, end_size));

    // Exited with no error
    return 0;
}


int years(int start_size, int end_size)
{
    int i, sum;

    // Calculates number of years until we reach threshold
    for (i = 0, sum = start_size; sum < end_size; i++)
    {
        // Integer division (truncation)
        sum += sum / 3 - sum / 4;
    }

    return i;
}
