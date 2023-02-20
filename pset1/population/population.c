#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start = 0, end = 0, years = 0;

    //Catches a user input, the initial size of population.
    do
    {
        start = get_int("Start population size: ");
    }
    while (start < 9);

    //Captures a user input, the final population size.
    do
    {
        end = get_int("End population size: ");
    }
    while (end < start);

    //Loop to account the number of years required for the population to reach the final population size.
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    printf("Years: %d\n", years);

    return 0;
}