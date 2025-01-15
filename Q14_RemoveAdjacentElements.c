#include <stdio.h>

void removeAdjacentElements(char *arr)
{
    int flag = 0;

    char answer[100];
    int answerIndex = 0;

    int index = 0;
    while (arr[index] != '\0')
    {
        if (arr[index + 1] == '\0' || arr[index] != arr[index + 1])
        {
            answer[answerIndex++] = arr[index];
            index++;
        }
        else
        {
            flag = 1;
            index = index + 2;
        }
    }

    answer[answerIndex] = '\0';
    if (flag)
    {
        removeAdjacentElements(answer);
    }
    else
    {
        printf("%s", arr);
    }
}

void getInput(char *arr)
{
    printf("Enter String:\n");
    scanf("%[^\n]", arr);
}
int main()
{
    char arr[100];
    getInput(arr);

    removeAdjacentElements(arr);

    return 0;
}
