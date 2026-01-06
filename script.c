#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];

    printf("thebiggonsv3's Password Strength Checker\n");
    printf("------------------------------------------\n");
    printf("Welcome! To get started, please enter a \npassword you would like to test.\n");

    printf("------------------------------------------\n");
    scanf("%99s", password);
    printf("------------------------------------------\n");

    int upper = 0;
    int lower = 0;
    int num = 0;
    int other = 0;

    size_t size = strlen(password);

    for (size_t i = 0; i < size; i++)
    {
        if (islower(password[i]))
        {
            lower++;
        }
        else if (isupper(password[i]))
        {
            upper++;
        }
        else if (isdigit(password[i]))
        {
            num++;
        }
        else
        {
            other++;
        }
    }

    int categoriesUsed = 0;
    if (lower > 0)
    {
        categoriesUsed++;
    }
    if (upper > 0)
    {
        categoriesUsed++;
    }
    if (num > 0)
    {
        categoriesUsed++;
    }
    if (other > 0)
    {
        categoriesUsed++;
    }

    int min = upper;
    if (lower < min)
    {
        min = lower;
    }
    if (num < min)
    {
        min = num;
    }
    if (other < min)
    {
        min = other;
    }

    int strength = 0;
    int ideal = (int)size / 4;

    if (ideal > 0 && categoriesUsed == 4)
    {
        strength = (5 * min) / ideal;
    }
    else
    {
        strength = categoriesUsed; 
    }

    if (size > 6)
    {
        strength++;
    }
    if (size > 15)
    {
        strength++;
    }

    if (strength > 5)
    {
        strength = 5;
    }

    if (strength < 3)
    {
        printf("Strength: %d/5 - Your password is weak.\n", strength);
    }
    else if (strength >= 3 && strength < 5)
    {
        printf("Strength: %d/5 - Your password is alright.\n", strength);
    }
    else
    {
        printf("Strength: %d/5 - Your password is strong.\n", strength);
    }

    printf("------------------------------------------\n");

    if (strength < 5)
    {
        printf("Suggestions to improve:\n");
        if (lower == 0)
        {
            printf("- Add lowercase letters\n");
        }
        if (upper == 0)
        {
            printf("- Add uppercase letters\n");
        }
        if (num == 0)
        {
            printf("- Add numbers\n");
        }
        if (other == 0)
        {
            printf("- Add special characters\n");
        }
        if (size <= 15)
        {
            printf("- Make it longer than 15 characters\n");
        }
    }

    return 0;
}


