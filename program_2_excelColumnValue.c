#include <stdio.h>
#include <string.h>
int getLength(char *input)
{
    int length = 0;
    while (*input != '\0')
    {
        length++;
        input++;
    }
    return length;
}

int solve(char *input)
{
    int length = strlen(input);
    int index = length - 1;

    int value = 0;

    value = (input[index] - 'A' + 1);
    index--;

    while (index >= 0)
    {
        value = (((*input - 'A' + 1) * 26) + value);
        index--;
    }

    return value;
}
void getOutput(char *input)
{
    printf("Value for Excel Column is: %d", solve(input));
}
void getInput(char *input)
{
    printf("Enter Excel Name: ");
    scanf("%[^\n]", input);
}
int main()
{
    char input[100] = {'\0'};
    getInput(input);

    getOutput(input);

    return 0;
}