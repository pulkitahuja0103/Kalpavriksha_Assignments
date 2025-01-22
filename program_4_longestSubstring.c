#include <stdio.h>
#include <stdlib.h>

void printLongestSubstring(char *arr, int startIndex, int endIndex)
{
    printf("Longest Sub String is: ");
    for (int i = startIndex; i <= endIndex; i++)
    {
        printf("%c", arr[i]);
    }
}
int getStringLength(char *arr)
{
    int length = 0;
    while (*arr != '\0')
    {
        length++;
        arr++;
    }
    return length;
}
void findLongestSubstringIndex(char *arr)
{

    int startIndex = 0;
    int endIndex = 0;

    int maxLen = 0;
    int n = getStringLength(arr);
    for (int i = 0; i < n; i++)
    {
        char freq[256] = {0};
        for (int j = i; j < n; j++)
        {
            if (freq[arr[j]] == 1)
            {
                break;
            }
            freq[arr[j]]++;
            int currLen = j - i + 1;
            if (currLen >= maxLen)
            {
                startIndex = i;
                endIndex = j;
                maxLen = currLen;
            }
        }
    }
    if (maxLen == 0)
    {
        exit(0);
    }
    printLongestSubstring(arr, startIndex, endIndex);
}
void getInput(char *arr)
{
    printf("Enter String: ");
    scanf("%[^\n]", arr);
}
int main()
{
    char arr[100];
    getInput(arr);

    findLongestSubstringIndex(arr);
    return 0;
}