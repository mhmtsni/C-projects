#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculate_letters(string text);
int calculate_words(string text);
int calculate_sentences(string text);
void calculate_readibility(int letters, int words, int sentences);
int main(void)
{
    string text = get_string("Text: ");
    int letters = calculate_letters(text);
    int words = calculate_words(text);
    int sentences = calculate_sentences(text);
    calculate_readibility(letters, words, sentences);
}
int calculate_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    return letters;
}
int calculate_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}
int calculate_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }

    return sentences;
}
void calculate_readibility(int letters, int words, int sentences)
{
    float av_number_of_letters = ((float) letters / words) * 100.0;
    float av_number_of_sentences = ((float) sentences / words) * 100.0;
    float grade_level = (0.0588 * av_number_of_letters - 0.296 * av_number_of_sentences - 15.8);
    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int rounded_grade = grade_level + 0.5;
        printf("Grade %i\n", rounded_grade);
    }
}
