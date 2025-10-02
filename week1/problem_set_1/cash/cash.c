#include <cs50.h>
#include <stdio.h>

/* pseudocode
** coins = [25,10,5,1] [quarters, dimes, nicles, pennies]
** Greedy Algorithm

1. Take user input (owed) and check if it's not negative number
2. Create a variable to store how much left owed
3. Check if owed is bigger than quarters if not go to step 5
4. Take 1 quarter and back to 3
5. Check if owed is bigger than dimes if not go to step 7
6. Take 1 dimes and back to 5
7. Check if owed is bigger than nicles if not go to step 9
8. Take 1 nicles and back to 7
9. Check if owed is bigger than pennies if not then done
10. Take 1 pennies and back to 9
*/

int check_owed(int owed);

int main(void)
{

    // 2. Create a variable to store how much left owed
    int owed = 0;
    int count_coin = 0;
    // 1. Take user input (owed) and check if it's not negative number
    do
    {
        owed = get_int("Change owed: ");
    }
    while(owed < 0);

    while(owed != 0)
    {
        owed -= check_owed(owed);
        count_coin++; // add count_coint each time any coin taken
    }

    printf("%i\n", count_coin);
}

int check_owed(int owed)
{
    int coin_change = 0;

    if (owed >= 25) // 3. Check if owed is bigger than quarters if not go to step 5
    {
        coin_change = 25; // 4. Take 1 quarter and back to 3
    }
    else if (owed >= 10) // 5. Check if owed is bigger than dimes if not go to step 7
    {
        coin_change = 10; // 6. Take 1 dimes and back to 5
    }
    else if (owed >= 5) // 7. Check if owed is bigger than nicles if not go to step 9
    {
        coin_change = 5; // 8. Take 1 nicles and back to 7
    }
    else // 9. Check if owed is bigger than pennies if not then done
    {
        coin_change = 1; // 10. Take 1 pennies and back to 9
    }
    return coin_change;
}

