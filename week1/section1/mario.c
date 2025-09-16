#include <stdio.h>
#include <cs50.h>

void left_pyramid(int count_block);
void right_pyramid(int count_block);
void print_line();

int main()
{
    print_line();
    int selected_option = get_int("what type of pyramid you want? \n1.Left Pyramid \n2.Blabla Pyramid \nEnter your choice of pyramid: ");
    print_line();
    int count_block = 0;

    switch(selected_option)
    {
        case 1:
            count_block = get_int("How many block you want to make?: ");
            left_pyramid(count_block);
            break;
        case 2:
            count_block = get_int("How many block you want to make?: ");
            right_pyramid(count_block);
            break;
        default:
            print_line();
            printf("That's not an option!\n");
            print_line();
    }
}







// function to print a line
void print_line()
{
    printf("==============================================\n");
}

// function to make left pyramid
void left_pyramid(int count_block)
{
    printf("======= %i of mario block =======\n\n",count_block);

    for(int x = 0; x < count_block; x++)
    {
        for(int y = 0; y < x+1; y++)
        {
            printf("#");
        }
        printf("\n");
    }
}

// function to make right pyramid
void right_pyramid(int count_block)
{
    printf("======= %i of mario block =======\n\n",count_block);

    for(int x = 0; x < count_block ; x++)
    {
        for(int y = 0; y < count_block - (x + 1); y++)
        {
            printf(" ");
        }
        for(int z = 0; z < x+1; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
