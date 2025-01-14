#include <stdio.h>
int isCharacter(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return 1;
    }
    return 0;
}
int countWords(char *input)
{
    int count = 0;

    while (*input != '\0')
    {
        if (*input != ' ')
        {
            if (isCharacter(*input))
            {
                count++;
            }
            while (*input != '\0' && *input != ' ')
            {
                input++;
            }
        }
        if (*input != '\0')
        {
            input++;
        }
    }

    return count;
}

void getInput(char *input)
{
    printf("Enter String:\n");
    scanf("%[^\n]", input);
}

void getOutput(char *input)
{
    printf("Words are:%d", countWords(input));
}

int main()
{
    char input[200];
    getInput(input);

    getOutput(input);
    return 0;
}