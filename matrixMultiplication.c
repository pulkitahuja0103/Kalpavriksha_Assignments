#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row1;
    int column1;
    printf("Enter row and column\n");
    scanf("%d %d", &row1, &column1);
    int** matrix1 = (int**)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
    {
        matrix1[i] = (int *)malloc(column1 * sizeof(int));
    }
    printf("Enter Values\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < column1; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int row2;
    int column2;
    printf("Enter row2 and column2\n");
    scanf("%d %d", &row2, &column2);
    int** matrix2 = (int**)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
    {
        matrix2[i] = (int *)malloc(column2 * sizeof(int));
    }
    printf("Enter Values\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < column2; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (column1 != row2)
    {
        printf("Not Possible");
    }
    else
    {
        int row3 = row1;
        int column3 = column2;
        int** matrix3 = (int**)malloc(row3 * sizeof(int *));
        for (int i = 0; i < row3; i++)
        {
            matrix3[i] = (int *)malloc(column3 * sizeof(int));
        }

        int ans[100];
        int index = 0;
        for (int outerRow = 0; outerRow < row1; outerRow++)
        {
            for (int i = 0; i < column2; i++)
            {
                int sum = 0;
                for (int outerCol = 0; outerCol < column1; outerCol++)
                {
                    int val1 = matrix1[outerRow][outerCol];
                    int val2 = matrix2[outerCol][i];
                    sum += (val1 * val2);
                }
                ans[index++] = sum;
            }
        }
        int k = 0;
        for (int i = 0; i < row3; i++)
        {
            for (int j = 0; j < column3; j++)
            {
                matrix3[i][j] = ans[k++];
            }
        }
        for (int i = 0; i < row3; i++)
        {
            for (int j = 0; j < column3; j++)
            {
                printf("%d ", matrix3[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}