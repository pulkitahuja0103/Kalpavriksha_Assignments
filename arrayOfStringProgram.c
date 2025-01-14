#include <stdio.h>
#include <stdlib.h>
int rows = 0;
int columns = 0;

int getStringLength(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void getRowAndCol()
{
    printf("Enter Rows and Columns:\n");
    scanf("%d %d", &rows, &columns);
}

void createArray(char ***matrix)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        matrix[rowIndex] = (char **)malloc(columns * sizeof(char *));
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            matrix[rowIndex][columnIndex] = (char *)malloc(50 * sizeof(char));
        }
    }
}

void getInputInArray(char ***matrix)
{
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            scanf("%s", matrix[rowIndex][columnIndex]);
        }
    }
}

void displayArray(char ***matrix)
{
    printf("The 2D array of names is:\n");
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            printf("%s ", matrix[rowIndex][columnIndex]);
        }
        printf("\n");
    }
}

int checkIsVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return 1;
    }
    return 0;
}

int startingWithVowelAndLongestWord(char ***matrix, int *longestWordRowIndex, int *longestWordColumnIndex)
{
    int maximumLength = 0;
    int startWithVowels = 0;
    for (int rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < columns; columnIndex++)
        {
                if ((checkIsVowel(matrix[rowIndex][columnIndex][0])))
                {
                    startWithVowels++;
                }
                int length = getStringLength(matrix[rowIndex][columnIndex]);
                if (length > maximumLength)
                {
                    maximumLength = length;
                    *longestWordRowIndex = rowIndex;
                    *longestWordColumnIndex = columnIndex;
                }  
        }
    }
    return startWithVowels;
}

void getOutput(char ***matrix,int longestWordRowIndex,int longestWordColumnIndex)
{
    int count = startingWithvowelAndLongestWord(matrix, &longestWordRowIndex, &longestWordColumnIndex);
    printf("Number of names starting with a vowel:%d\n", count);
    if (longestWordRowIndex == -1 && longestWordColumnIndex == -1)
    {
        printf("No Valid Longest String is found");
    }
    else
    {
        printf("The longest name:%s\n", matrix[longestWordRowIndex][longestWordColumnIndex]);
    }
}
int main()
{

    getRowAndCol();
    char ***matrix = (char ***)malloc(rows * sizeof(char **));

    createArray(matrix);

    getInputInArray(matrix);

    displayArray(matrix);

    int longestWordRowIndex = -1, longestWordColumnIndex = -1;

    getOutput(matrix,longestWordRowIndex,longestWordColumnIndex);

    return 0;
}