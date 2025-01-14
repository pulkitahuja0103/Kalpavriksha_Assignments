#include <stdio.h>
#include <stdlib.h>

int isAlphabet(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    return 0;
}
void getLongestWordLength(char *input)
{
    int maximumLength = 0;
    int storeStartIndex = 0;

    int index = 0;
    while (input[index] != '\0')
    {
        int currentMaximumWordLength = 0;
        int currentIndex = index;

        while (isAlphabet(input[index]))
        {
            currentMaximumWordLength++;
            index++;
        }
        if (currentMaximumWordLength >= maximumLength)
        {
            storeStartIndex = currentIndex;
            maximumLength = currentMaximumWordLength;
        }
        index++;
    }

    printf("Longest Word Length is:%d \nAnd the word is:%s", maximumLength, input + storeStartIndex);
}
void getInput(char *input)
{
    printf("Enter Sentence:\n");
    scanf("%[^\n]", input);
}
int main()
{
    char input[200];
    getInput(input);

    getLongestWordLength(input);

    return 0;
}