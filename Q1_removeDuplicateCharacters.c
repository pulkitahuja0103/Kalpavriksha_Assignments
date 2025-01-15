#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void storeFrequency(char *sentence, int frequency[26])
{
    while (*sentence != '\0')
    {
        int index = *sentence - 'a';
        frequency[index]++;
        sentence++;
    }
}

int removeDuplicateCharacters(char *sentence, int *frequency, char *answer)
{
    int answerIndex = 0;
    while (*sentence != '\0')
    {
        int index = *sentence - 'a';
        if (frequency[index] >= 1)
        {
            frequency[index] = 0;
            answer[answerIndex++] = *sentence;
        }
        sentence++;
    }
    answer[answerIndex] = '\0';

    return answerIndex;
}

void getInput(char *sentence)
{
    printf("Enter String:\n");
    scanf("%[^\n]", sentence);
}

void getOutput(char *answer)
{
    printf("%s", answer);
}

int main()
{
    char *sentence = (char *)malloc(100 * sizeof(char));
    getInput(sentence);

    int frequency[26] = {0};
    storeFrequency(sentence, frequency);

    char answer[100];
    removeDuplicateCharacters(sentence, frequency, answer);

    getOutput(answer);

    return 0;
}