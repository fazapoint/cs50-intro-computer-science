#include <cs50.h>
#include <stdio.h>

void print_row(int count_col, char type);
void left_right_aligned_pyramid(int count_row);

int main(void)
{
    // user input range 1-8
    int input = 0;

    do
    {
        input = get_int("How many pyramid's level you want? (1-8): ");
    }
    while (input < 1 || input > 8);

    left_right_aligned_pyramid(input);
}


void left_right_aligned_pyramid(int count_row)
{
    for (int x = 0; x < count_row; x++)
    {

        /* #region left aligned pyramid */
        // Print spaces
        print_row((count_row - (x + 1)), ' ');

        // Print hashes
        print_row((x + 1), '#');
        /* #endregion */

        // Print 2 middle spaces
        printf("  ");

        // print hashes
        print_row((x + 1), '#');

        // New line for each row
        printf("\n");
    }
}


void print_row(int count_col, char type)
{
    if (type == ' ')
    {
        for (int x = 0; x < count_col; x++)
        {
            printf(" ");
        }
    }
    else if (type == '#')
    {
        for (int x = 0; x < count_col; x++)
        {
            printf("#");
        }
    }
    else
    {
        printf("Unknown");
    }
}
