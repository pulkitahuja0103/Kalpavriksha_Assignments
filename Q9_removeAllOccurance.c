#include <stdio.h>

void removeAllOccuranceOfCharacter(char *input, char character)
{
    char result[100];
    int index = 0;

    while (*input != '\0')
    {
        if (*input != character)
        {
            result[index++] = *input;
        }
        input++;
    }
    result[index] = '\0';
    printf("%s", result);
}
void getInput(char *input, char *character)
{
    printf("Enter String:\n");
    scanf("%[^\n]", input);

    getchar();
    printf("Enter Character:\n");
    scanf("%c", &(*character));
}
int main()
{

    char input[100];
    char character;
    getInput(input, &character);

    removeAllOccuranceOfCharacter(input, character);

        return 0;
}