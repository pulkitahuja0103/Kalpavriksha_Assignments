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

int checkIsRotated(char *string, char *rotateString)
{
    int length = getLength(rotateString);
    appendString(rotateString);

    int index1 = 0, index2 = 0;
    while (rotateString[index1] != '\0')
    {
        if (rotateString[index1] == string[index2])
        {
            int count = 0;
            while (rotateString[index1] == string[index2])
            {
                count++;
                if (count == length)
                {
                    return 1;
                }
                index1++;
                index2++;
            }
        }
        index2 = 0;
        index1++;
    }

    return 0;
}

void getInput(char *string, char *rotateString)
{
    printf("Enter String:");
    scanf("%[^\n]", string);
    getchar();
    printf("Enter Rotated String:");
    scanf("%[^\n]", rotateString);
}
void getOutput(char *string, char *rotateString)
{
    if (checkIsRotated(string, rotateString))
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