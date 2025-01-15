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
void reverseArray(char *input, int startIndex, int endIndex)
{
    while (startIndex <= endIndex)
    {
        char ch = input[startIndex];
        input[startIndex] = input[endIndex];
        input[endIndex] = ch;
        startIndex++;
        endIndex--;
    }
}

char convertIntegerToCharacter(int number)
{
    return number + '0';
}

int compressTheString(char *input, char *answer)
{
    int lengthOfActualString = getLength(input);

    int answerIndex = 0;

    int currentLength = 1;
    while (*input != '\0')
    {
        answer[answerIndex++] = *input;
        while (*input == *(input + 1))
        {
            currentLength++;
            input++;
        }

        int number = currentLength;
        int startIndex = answerIndex;
        while (number != 0)
        {
            int reminder = number % 10;
            number = number / 10;
            answer[answerIndex++] = convertIntegerToCharacter(reminder);
        }
        int endIndex = answerIndex - 1;

        if (currentLength > 9)
        {
            reverseArray(answer, startIndex, endIndex);
        }

        currentLength = 1;

        input++;
    }
    answer[answerIndex] = '\0';

    int lengthOfCompressedString = getLength(answer);

    printf("Answer is:\n");
    if (lengthOfCompressedString >= lengthOfActualString)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void sortString(char *input)
{
    for (int index1 = 0; index1 < getLength(input); index1++)
    {
        for (int index2 = 0; index2 < getLength(input); index2++)
        {
            if (input[index2] > input[index1])
            {
                char ch = input[index2];
                input[index2] = input[index1];
                input[index1] = ch;
            }
        }
    }
}

void getInput(char *input)
{
    printf("Enter the string:\n");
    scanf("%[^\n]", input);
}
void getOutput(char *input, char *answer)
{
    if (compressTheString(input, answer))
    {
        printf("%s", answer);
    }
    else
    {
        printf("%s", input);
    }
}
int main()
{
    char input[1000];
    getInput(input);

    char answer[1000];

    sortString(input);

    getOutput(input, answer);

    return 0;
}