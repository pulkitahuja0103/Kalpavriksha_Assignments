#include <stdio.h>

int getLength(char *str)
{
    int length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
void appendString(char *rotateString)
{
    int length = getLength(rotateString);
    int appendIndex = length;

    for (int index = 0; index < length; index++)
    {
        rotateString[appendIndex++] = rotateString[index];
    }
    rotateString[appendIndex] = '\0';
}
int checkRotation(char *string, char *rotateString)
{
    int length = getLength(rotateString);
    appendString(rotateString);

    int index = 0;
    while (*rotateString != '\0')
    {
        if (*rotateString == string[index])
        {
            while (string[index] != '\0')
            {
                if (*rotateString != string[index])
                {
                    break;
                }
                index++;
                rotateString++;
            }
            if (string[index] == '\0')
            {
                return 1;
            }
            index = 0;
        }
        rotateString++;
    }

    return 0;
}
void getInput(char *string, char *rotateString)
{

    printf("Enter String:\n");
    scanf("%[^\n]", string);
    getchar();
    printf("Enter String:\n");
    scanf("%[^\n]", rotateString);
}
void getOutput(char *string, char *rotateString)
{
    if (checkRotation(string, rotateString))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}
int main()
{
    char string[100];
    char rotateString[100];

    getInput(string, rotateString);

    getOutput(string, rotateString);

    return 0;
}