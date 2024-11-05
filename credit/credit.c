#include <cs50.h>
#include <stdio.h>
int get_int_len(long card_number);
int get_first_digit(long card_number);
int get_two_digits(long card_number);
int main(void)
{
    long card_number = get_long("Card Number: ");
    int remainder;
    int first_sum = 0;
    int second_sum = 0;
    int total_sum = 0;
    int length_of_the_card_number = get_int_len(card_number);
    int first_digit = get_first_digit(card_number);
    int two_digits = get_two_digits(card_number);

    if (card_number <= 0)
    {
        printf("INVALID\n");
    }

    for (int i = 0; i < length_of_the_card_number; i++)
    {
        remainder = card_number % 10;
        card_number = card_number / 10;
        if (i % 2 == 1)
        {
            if (remainder * 2 >= 10)
            {
                int remainder_of_remainder = (remainder * 2) % 10;
                first_sum += 1 + remainder_of_remainder;
            }
            else
            {
                first_sum += remainder * 2;
            }
        }
        else
        {
            second_sum += remainder;
        }
    }
    total_sum = first_sum + second_sum;
    if (total_sum % 10 == 0)
    {
        if (length_of_the_card_number == 15 && (two_digits == 34 || two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (length_of_the_card_number == 16)
        {
            if (two_digits <= 55 && two_digits >= 51)
            {
                printf("MASTERCARD\n");
            }
            else if (first_digit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length_of_the_card_number == 13 && first_digit == 4)
        {
            printf("VISA\n");
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

int get_int_len(long card_number)
{
    int l = 1;
    while (card_number > 9)
    {
        l++;
        card_number /= 10;
    }
    return l;
}

int get_first_digit(long card_number)
{
    while (card_number >= 10)
    {
        card_number /= 10;
    }
    return card_number;
}

int get_two_digits(long card_number)
{
    while (card_number >= 100)
    {
        card_number /= 10;
    }
    return card_number;
}
