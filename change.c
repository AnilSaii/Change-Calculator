#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// A function for checking wheather the given string is a number or not
bool checkForDigit(char * argv);

int main(int argc, char * argv[])
{
    // Error checking
    if (argc != 3 || !checkForDigit(argv[1]) || !checkForDigit(argv[2]))
    {
        printf("Usage: ./change amount expenses\n");
        return 1;
    }

    // Convert strings to integers
    int amount = atoi(argv[1]);
    int expenses = atoi(argv[2]);
    if (amount < expenses)
    {
        printf("Amount can't be less than expenses\n");
        return 1;
    }
    
    // Calculate the change
    int change = amount - expenses;
    
    // An array to keep track of currency
    int currency[10] = {0};
    
    
    // An array of indian currency values
    int currencyValue[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    // Calculate the change
    while (change != 0)
    {
        if (change >= 2000)
        {
            currency[0]++;
            change = change - 2000;
        }

        if (change >= 500 && change < 2000)
        {
            currency[1]++;
            change = change - 500;
        }

        if (change >= 200 && change < 500)
        {
            currency[2]++;
            change = change - 200;
        }

        if (change >= 100 && change < 200)
        {
            currency[3]++;
            change = change - 100;
        }

        if (change >= 50 && change < 100)
        {
            currency[4]++;
            change = change - 50;
        }

        if (change >= 20 && change < 50)
        {
            currency[5]++;
            change = change - 20;
        }

        if (change >= 10 && change < 20)
        {
            currency[6]++;
            change = change - 10;
        }

        if (change >= 5 && change < 10)
        {
            currency[7]++;
            change = change - 5;
        }

        if (change >= 2 && change < 5)
        {
            currency[8]++;
            change = change - 2;
        }

        if (change >= 1 && change < 2)
        {
            currency[9]++;
            change = change - 1;
        }
    }
    
    // Console out
    for (int i = 0; i < 10; i++)
    {
        if (currency[i] != 0)
        {
            printf("%d 's : %d\n", currencyValue[i], currency[i]);
        }
    }
    printf("That sum's upto %d\n", amount - expenses);
    if (amount - expenses == 0)
    {
        printf("No need of change\n");
    }
    return 0;
}




bool checkForDigit(char * argv)
{
    int length = strlen(argv);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(argv[i]))
            return false;
    }
    return true;
}