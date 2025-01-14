#include <stdio.h>
#include <stdlib.h>
int getLengthOfString(char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
void storeFrequencyOfStringCharacters(char *input, int *frequency)
{
    while (*input != '\0')
    {
        int index = *input - 'a';
        frequency[index]++;
        input++;
    }
}
int checkIfFrequencyAreSame(int *frequency1, int *frequency2)
{
    for (int index = 0; index < 26; index++)
    {
        if (frequency1[index] != frequency2[index])
        {
            return 0;
        }
    }
    return 1;
}
void checkForAnagramsStrings(char *input1, char *input2)
{
    int frequency1[26] = {0};
    int frequency2[26] = {0};

    storeFrequencyOfStringCharacters(input1, frequency1);
    storeFrequencyOfStringCharacters(input2, frequency2);

    if (checkIfFrequencyAreSame(frequency1, frequency2))
    {
        printf("Strings are anagrams");
    }
    else
    {
        printf("Strings are Not anagrams");
    }
}

void getInput(char *string1, char *string2)
{
    printf("Enter String1:\n");
    scanf("%[^\n]", string1);
    getchar();
    printf("Enter String2:\n");
    scanf("%[^\n]", string2);
}
void getOutput(char *string1, char *string2)
{
    int length1 = getLengthOfString(string1);
    int length2 = getLengthOfString(string2);

    if (length1 != length2)
    {
        printf("Strings are Not anagrams");
        exit(1);
    }
    else
    {
        checkForAnagramsStrings(string1, string2);
    }
}
int main()
{
    char string1[100];
    char string2[100];
    getInput(string1, string2);

    getOutput(string1, string2);

    return 0;
}