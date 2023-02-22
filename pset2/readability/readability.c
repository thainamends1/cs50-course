#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>

int const HUNDRED = 100;

int quantLetters(string text);
int quantWords(string text);
int quantPhrases(string text);
float averageLetters(int letters, int words);
float averageSentences(int phrases, int words);
float readability(float l, float s);
void gradeLevel(float index);

int main(void)
{
    string text = get_string("Text: ");

    int letters = quantLetters(text);
    int words = quantWords(text);
    int phrases = quantPhrases(text);

    float l = averageLetters(letters, words);
    float s = averageSentences(phrases, words);

    float index = readability(l, s);

    gradeLevel(index);

    return 0;
}

//Calculates and returns the number of letters in the text.
int quantLetters(string text)
{
    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        //References to the ASCII table, from a-z and A-Z.
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count++;
        }
    }

    return count;
}

//Calculates and returns the number of words in the text.
int quantWords(string text)
{
    int count = 0;

    //Loop that increments "count" every time it encounters a space or line break in the text.
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == '\n')
        {
            count++;
        }
    }

    //The last word is not counted as there will be no space or newline after it.
    //Therefore, add +1 to it, so that it enters the count.
    if (count != 0)
    {
        return count + 1;
    }
    else
    {
        return count;
    }
}

//Calculates and returns the number of sentences (phrases) in the text.
int quantPhrases(string text)
{
    int count = 0;

    //Loop that increments "count" every time it finds characters that define a phrase.
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }

    return count;
}

//Average of letters per 100 words in the text.
float averageLetters(int letters, int words)
{
    return (letters * HUNDRED / (float)words);
}

//Average sentences per 100 words in the text.
float averageSentences(int phrases, int words)
{
    return (phrases * HUNDRED / (float)words);
}

//Coleman-Liau index.
float readability(float l, float s)
{
    return ((0.0588 * l) - (0.296 * s) - (15.8));
}

//Once calculates the index, puts the result into each grade level condition.
void gradeLevel(float index)
{
    if (index < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1.0 && index < 16.0)
    {
        //floor(number): Math.h library function to make round the number, to get a grade level approximation.
        if (index >= (floor(index) + 0.5))
        {
            printf("Grade %d\n", (int)index + 1);
        }
        else
        {
            printf("Grade %d\n", (int)index);
        }
    }
    else
    {
        printf("Grade 16+\n");
    }
}