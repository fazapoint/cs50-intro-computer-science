#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
    int x = get_int("what number?");
}
