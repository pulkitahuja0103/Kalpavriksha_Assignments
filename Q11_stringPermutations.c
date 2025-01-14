#include <stdio.h>
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
void swap(char *input1, char *input2)
{
    char ch = *input1;
    *input1 = *input2;
    *input2 = ch;
}
void permutations(int currentIndex, int size, char input[100])
{
    if (currentIndex == size)
    {
        printf("%s\n", input);
        return;
    }
    for (int indx = currentIndex; indx < size; indx++)
    {
        swap(input + currentIndex, input + indx);
        permutations(currentIndex + 1, size, input);
        swap(input + currentIndex, input + indx);
    }
}
void getInput(char *input)
{
    printf("Enter String:\n");
    scanf("%[^\n]", input);
}
void getOutput(char *input)
{
    printf("permutation Strings are:\n");
    permutations(0, getLength(input), input);
}
int main()
{
    char input[100];
    getInput(input);

    getOutput(input);
    return 0;
}