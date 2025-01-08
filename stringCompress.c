#include <stdio.h>
int getLength(char input[100])
{
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }
    return length;
}
int main()
{
    char input[100];
    scanf("%[^\n]", input);
    int size = getLength(input);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[i] > input[j])
            {
                char ch = input[i];
                input[i] = input[j];
                input[j] = ch;
            }
        }
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        int count = 1;
        while (input[i] == input[i + 1])
        {
            count++;
            i++;
        }
        printf("%c%d", input[i], count);
    }
    return 0;
}