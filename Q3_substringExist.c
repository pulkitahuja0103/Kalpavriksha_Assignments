#include <stdio.h>
#include <string.h>
void getInput(char *string, char *subString)
{
    printf("Enter String:\n");
    scanf("%[^\n]", string);
    getchar();
    printf("Enter Sub-String:\n");
    scanf("%[^\n]", subString);
}

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

int subStringIsPresent(char *string, char *subString)
{
    int lengthOfSubString = getLength(subString);
    int startIndexOfSubString = -1;
    for (int indx = 0; string[indx] != '\0'; )
    {
        int subStringIndex = 0;
        int IndexOfSubStringStart = 0;
        if (subString[subStringIndex] == string[indx])
        {
            IndexOfSubStringStart = indx;
            int count = 0;
            while (subString[subStringIndex] == string[indx] && subString[subStringIndex] != '\0' && string[indx] != '\0')
            {
                count++;
                subStringIndex++;
                indx++;
            }

            if (count == lengthOfSubString)
            {
                startIndexOfSubString = IndexOfSubStringStart;
                break;
            }else{
                continue;
            }
        }
        indx++;
    }

    return startIndexOfSubString;
}

void getOutput(int startIndexOfSubString)
{
    if (startIndexOfSubString == -1)
    {
        printf("SubString not Found");
    }
    else
    {
        printf("SubString Found at index %d", startIndexOfSubString);
    }
}
int main()
{
    char string[100];
    char subString[100];
    getInput(string, subString);

    int startIndexOfSubString = subStringIsPresent(string, subString);

    getOutput(startIndexOfSubString);

    return 0;
}