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

void removeAllAdjacentElements(char *input)
{
    char answer[100];
    answer[0] = input[0];

    int answerIndex = 1;
    int index = 1;
    while (input[index] != '\0')
    {
        if (input[index] == answer[answerIndex - 1])
        {
            answerIndex--;
            index++;
        }
        else
        {
            answer[answerIndex++] = input[index++];
        }
    }
    answer[answerIndex] = '\0';

    if (answer[0] == '\0')
    {
        printf(" ");
    }
    else
    {
        printf("%s", answer);
    }
}

void getInput(char *input)
{
    printf("Enter String\n");
    scanf("%[^\n]", input);
}
int main()
{
    char input[100];
    getInput(input);

    removeAllAdjacentElements(input);
}