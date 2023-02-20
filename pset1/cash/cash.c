#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollar = 0.0;
    int validateDollar = 0;
    int coins = 0;

    //Validates the user's monetary input.
    do
    {

        dollar = get_float("\nEntry the value: ");

        //Loop exit condition.
        if (dollar > 0.0)
        {
            validateDollar = -1;
        }

    }
    while (validateDollar != -1);

    //Converts the amount to cents.
    int cents = round(dollar * 100);

    //Loop condition for cents greater than or equal to 25.
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    //Loop condition for cents greater than or equal to 10.
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    //Loop condition for cents greater than or equal to 5.
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    //Loop condition for cents greater than or equal to 1.
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    //Number of coins needed to return cents.
    printf("%i\n", coins);

    return 0;
}