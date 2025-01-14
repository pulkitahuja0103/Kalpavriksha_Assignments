#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int checkIsDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}
void convertStringToNumber(char *input)
{
    bool isNegative = false;
    int number = 0;
    if (*input == '-')
    {
        isNegative = true;
        input++;
    }
    while (*input != '\0')
    {
        if (checkIsDigit(*input))
        {
            while (checkIsDigit(*input))
            {
                number = number * 10 + (*input - '0');
                input++;
            }
        }
        else
        {
            break;
        }
    }

    if (isNegative)
    {
        number = number * -1;
    }

    printf("Number is:%d", number);
}
void getInput(char *input)
{
    printf("Enter String to be Converted into a Number:\n");
    scanf("%[^\n]", input);
}
int main()
{

    char input[100];
    getInput(input);

    convertStringToNumber(input);
    return 0;
}