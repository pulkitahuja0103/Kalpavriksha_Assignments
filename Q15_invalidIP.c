#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int getNumberDigits(int num)
{

    int count = 0;
    while (num != 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}

int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

int checkValid(char *arr)
{
    if (arr[0] == '.')
    {
        return 0;
    }

    int index = 0;
    int countDot = 0;

    while (arr[index] != '\0')
    {
        if (arr[index] == '.')
        {
            countDot++;

            if (countDot > 3)
            {
                return 0;
            }

            if (arr[index] == arr[index + 1])
            {
                return 0;
            }
            index++;
        }
        else if (isDigit(arr[index]))
        {
            index++;
        }
        else
        {
            return 0;
        }
    }

    if (countDot != 3)
    {
        return 0;
    }

    return 1;
}

void getInput(char *arr)
{
    printf("Enter IP:\n");
    scanf("%[^\n]", arr);
}

void checkEntireIPAddress(char *arr)

{
    if (checkValid(arr) != 1)
    {
        printf("Invalid");
        exit(1);
    }

    int index = 0;
    while (arr[index] != '\0')
    {
        int num = 0;
        int len = 0;
        int count = 0;

        if (isDigit(arr[index]))
        {
            if ((arr[index] == '0' && arr[index + 1] == '.') || (arr[index] == '0' && arr[index + 1] == '\0'))
            {
                index++;
                continue;
            }
            while (isDigit(arr[index]))
            {
                len++;
                num = num * 10 + arr[index] - '0';
                index++;
            }

            count = getNumberDigits(num);

            if (len != count)
            {
                printf("Invalid");
                exit(0);
            }
            if (num >= 0 && num <= 255)
            {
            }
            else
            {
                printf("Invalid");
                exit(0);
            }
        }
        index++;
    }

    if (arr[index] == '\0')
    {
        printf("Valid");
    }
}

int main()
{
    char *arr = (char *)malloc(200 * sizeof(char));
    getInput(arr);

    checkEntireIPAddress(arr);
    free(arr);

    return 0;
}