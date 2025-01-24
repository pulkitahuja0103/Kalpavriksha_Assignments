// leetcode Question Number-49
/*
Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void storeFreq(char *str, int *freq)
{
    while (*str != '\0')
    {
        int index = *str - 'a';
        freq[index]++;
        str++;
    }
}

int isAnagram(int *freq1, int *freq2)
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return 0;
        }
    }
    return 1;
}

void getInput(int *numberOfString)
{
    printf("Enter Number of Strings\n");
    scanf("%d", &(*numberOfString));
}

char **initialize2DArray(int numberOfString)
{
    char **arr = (char **)malloc(numberOfString * sizeof(char *));
    for (int i = 0; i < numberOfString; i++)
    {
        arr[i] = (char *)malloc(50 * sizeof(char));
    }

    return arr;
}

int **initializeFreqArray(int numberOfString)
{
    int **freq = (int **)calloc(numberOfString, sizeof(int *));
    for (int i = 0; i < numberOfString; i++)
    {
        freq[i] = (int *)calloc(26, sizeof(int));
    }
    return freq;
}

void getInputStrings(int numberOfString, char **arr)
{
    printf("enter string\n");
    for (int i = 0; i < numberOfString; i++)
    {
        getchar();
        scanf("%[^\n]", arr[i]);
    }
}

int compareStrings(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0')
    {
        return 1;
    }
    return 0;
}

void groupAnagramStrings(int numberOfString, char **arr, int **freq)
{
    for (int i = 0; i < numberOfString; i++)
    {
        storeFreq(arr[i], freq[i]);
    }

    for (int i = 0; i < numberOfString; i++)
    {
        if (compareStrings(arr[i], "$"))
        {
            continue;
        }

        printf("[%s", arr[i]);
        arr[i] = "$";

        for (int j = i + 1; j < numberOfString; j++)
        {
            if (isAnagram(freq[i], freq[j]))
            {
                printf(",%s", arr[j]);
                arr[j] = "$";
            }
        }
        printf("]");
    }
}
int main()
{
    int numberOfString;
    getInput(&numberOfString);

    char **arr = initialize2DArray(numberOfString);
    int **freq = initializeFreqArray(numberOfString);
    getInputStrings(numberOfString, arr);

    groupAnagramStrings(numberOfString, arr, freq);
    return 0;
}