
#include <stdio.h>
#include <limits.h>

void storeFrequency(char *str, int *frequency)
{
    for (int index = 0; str[index] != '\0'; index++)
    {
        frequency[str[index]]++;
    }
}

int getLength(char *str)
{
    char *ptr = str;
    int length = 0;
    while (*ptr != '\0')
    {
        ptr++;
        length++;
    }
    return length;
}
int allCharactersArePresent(int *patternFreq, int *stringFreq)
{
    for (int index = 0; index < 256; index++)
    {
        if (stringFreq[index] >= patternFreq[index])
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void getOutput(int startIndex, int endIndex, char *string)
{
    if (startIndex != -1 && endIndex != -1)
    {
        for (int index = startIndex; index <= endIndex; index++)
        {
            printf("%c", string[index]);
        }
    }
    else
    {
        printf("Pattern Not Found");
    }
}

void getStringWithAllCharacters(char *string, char *pattern)
{
    int patternFreq[256] = {0};
    storeFrequency(pattern, patternFreq);

    int startIndex = -1, endIndex = -1;
    int size = getLength(string);
    int minimumLength = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        int stringFreq[256] = {0};
        for (int j = i; j < size; j++)
        {
            stringFreq[string[j]]++;
            if (allCharactersArePresent(patternFreq, stringFreq))
            {
                int currLen = j - i + 1;
                if (currLen <= minimumLength)
                {
                    minimumLength = currLen;
                    startIndex = i;
                    endIndex = j;
                }
            }
        }
    }

    getOutput(startIndex, endIndex, string);
}

void getInput(char *string, char *pattern)
{
    printf("Enter String:\n");
    scanf("%[^\n]%*c", string);
    printf("Enter Pattern:\n");
    scanf("%[^\n]", pattern);
}

int main()
{
    char string[100];
    char pattern[100];
    getInput(string, pattern);

    getStringWithAllCharacters(string, pattern);

    return 0;
}