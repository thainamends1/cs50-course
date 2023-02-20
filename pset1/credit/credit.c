#include <stdio.h>
#include <cs50.h>

long int getCreditNumber();
int getLenghtDigits(int long number);
int checksLegitimateCard(int long number);
void checksCreditCardCompany(int long number);

int main(void)
{
    long int number = getCreditNumber();
    checksCreditCardCompany(number);

    return 0;
}

//Catches and validates user input.
long int getCreditNumber()
{
    long int number;
    int validateNumber = 0;

    //Loop to get input with correct conditions.
    do
    {
        number = get_long("Number: ");

        if (number)
        {
            validateNumber = -1;
        }

    }
    while (validateNumber != -1);

    return number;
}

//Returns the number of digits.
int getLenghtDigits(int long number)
{
    int lenght = 0;

    if (number == 0)
    {
        lenght = 1;
    }
    else
    {
        //"Lenght" is autoincremented until the "number" becomes unity.
        while (number != 0)
        {
            lenght += 1;
            number /= 10;
        }
    }

    return lenght;
}

//Checks card authenticity based on Luhn's algorithm.
int checksLegitimateCard(int long number)
{
    //i = indentation variable and mod = remainder after dividing.
    int i = 0, mod = 0;

    //mod1 and sum1 are related to the part of calculations about the digits in odd position.
    int mod1 = 0, sum1 = 0;

    //sum2 is related to the calculations part about digits in even position.
    int sum2 = 0;

    //Gets the number of digits on the card, because each digit validates a position,
    //which will be traversed in the loop below.
    int digits = getLenghtDigits(number);

    while (i < digits)
    {
        //Takes the last digit of the card in mod variable. Then, deletes the last digit
        //causing the variable number to decrease by one decimal place.
        mod = number % 10;
        number = number / 10;

        //Arithmetic operations for digits that are in even position, otherwise odd position.
        if (i % 2 == 0)
        {
            sum2 += mod;
        }
        else
        {
            int dig1, dig2;

            mod1 = mod * 2;

            if (mod1 > 9)
            {
                dig1 = mod1 % 10;
                dig2 = mod1 / 10;

                mod1 = dig1 + dig2;
            }

            sum1 += mod1;
        }

        i++;
    }

    int sum = sum1 + sum2;

    return sum;
}

//Gets card and company matches.
void checksCreditCardCompany(int long number)
{
    //Used to compare the lenght of digits that each card company has.
    int digits = getLenghtDigits(number);

    //
    int validDigits = checksLegitimateCard(number);

    //
    int mod = validDigits % 10;

    if (mod == 0)
    {
        //Reduces to two digits only.
        while (number > 100)
        {
            number /= 10;
        }

        //Block of comparisons (if-else) with the conditions of each company.
        if (digits == 15 && (number / 10 == 3) && ((number % 10 == 4) || (number % 10 == 7)))
        {
            printf("AMEX\n");
        }
        else if ((digits >= 13 && digits <= 16) && (number / 10 == 4))
        {
            printf("VISA\n");
        }
        else if ((digits == 16) && ((number / 10 == 5) && (number % 10 >= 1) && (number % 10 <= 5)))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}