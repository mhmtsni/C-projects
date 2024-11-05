#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int main(int argc, string argv[])
{
    if(argc != 2) 
    {
        printf("Please enter right amount of arguemnts");
        return 1;
    }
    int count[26] = {0};
    char upper_key[27];
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        upper_key[i] = toupper(argv[1][i]);
    }
    upper_key[strlen(argv[1])] = '\0';
    printf("%lu", strlen(upper_key));
    if (strlen(upper_key) != 26)
    {
        printf("Your key must consist of 26 letters");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(upper_key); i < n; i++)
        {

            if (!isalpha(upper_key[i]))
            {
                printf("Key contains invalid characters.\n");
                return 1;
            }
            count[toupper(upper_key[i]) - 'A']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i] != 1)
            {
                printf("Key shouldn't contain duplicate characters\n");
                return 1;
            }
        }
    }

    if (strlen(upper_key) == 26)
    {
        string text = get_string("plain text: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                printf("%c", upper_key[text[i] - 65]);
            }
            else if (text[i] >= 'a' && text[i] <= 'z')
            {
                printf("%c", (upper_key[text[i] - 97]) + 32);
            }
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Only enter one argument");
    }
}
