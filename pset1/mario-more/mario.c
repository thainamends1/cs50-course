#include <stdio.h>
#include <cs50.h>

/*
Notes:
i = lline, which represents the height of the pyramid;
j = column, which represents the pyramid on the left;
k = column, which represents the pyramid on the right.
*/

void printSpaces(int number);
void printHashes(int number);

int main()
{
    int height, i = 0, j = 0, k = 0;

    //Captures a user-defined height from the range 1 to 8 only.
    do
    {
        height = get_int("Height: ");
    }
    while ((height <= 0) || (height > 8));

    //Loop condition defined by height.
    for (i = 0; i < height; i++)
    {
        printSpaces((height - i) - 1);

        if (j <= i || k <= i)
        {
            printHashes(j + 1);
            j++;

            printf("  ");

            printHashes(k + 1);
            k++;
        }

        //Newline defined by height.
        printf("\n");
    }

    return 0;
}

//Function to print spaces.
void printSpaces(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf(" ");
    }
}

//Function to print hashes.
void printHashes(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("#");
    }
}