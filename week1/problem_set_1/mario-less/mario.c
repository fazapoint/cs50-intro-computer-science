// Mario pyramid right alligned
#include <cs50.h>
#include <stdio.h>

void print_row(int count_row, char type);

int main(void)
{
    int input = 0;
    // take user input in range 1 to 8 (if input out of range then keep asking the input)
    do
    {
        input = get_int("how many pyramid's level you want (1-8)?: ");
    }
    while (input < 1 || input > 8);

    // draw the mario pyramid
    // draw the height
    for (int x = 0; x < input; x++)
    {
        // draw the space row
        print_row((input - (x + 1)), ' ');

        // draw the # row
        print_row((x + 1), '#');

        // new line for each row
        printf("\n");
    }
}


void print_row(int count_row, char type)
{
    if (type == '#')
    {
        for (int x = 0; x < count_row; x++)
        {
            printf("#");
        }
    }
    else if (type == ' ')
    {
        for (int x = 0; x < count_row; x++)
        {
            printf(" ");
        }
    }
    else
    {
        printf("unknown");
    }
}
