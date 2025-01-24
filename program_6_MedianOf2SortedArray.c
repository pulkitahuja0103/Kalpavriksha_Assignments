// leetcode Question Number-4
/*
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
*/
#include <stdio.h>
#include <stdlib.h>
double calculateMedian(int *arr1, int *arr2, int size1, int size2)
{
    int index1 = 0;
    int index2 = 0;

    int length = size1 + size2;
    int answer[length];
    int answerIndex = 0;
    while (index1 < size1 && index2 < size2)
    {
        if (arr1[index1] < arr2[index2])
        {
            answer[answerIndex++] = arr1[index1++];
        }
        else
        {
            answer[answerIndex++] = arr2[index2++];
        }
    }
    while (index1 < size1)
    {
        answer[answerIndex++] = arr1[index1++];
    }
    while (index2 < size2)
    {
        answer[answerIndex++] = arr2[index2++];
    }

    double median;
    if (length % 2 != 0)
    {
        median = answer[(length / 2)] / 1.0;
    }
    else
    {
        int val1 = answer[(length / 2)];
        int val2 = answer[(length / 2) - 1];

        median = (val1 + val2) / 2.0;
    }

    return median;
}
int *createArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    printf("Enter elements in array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element:", i + 1);
        scanf("%d", &arr[i]);
    }

    return arr;
}
void getSize(int *a, int *b)
{
    printf("Enter size for array 1:");
    scanf("%d", &(*a));
    printf("Enter size for array 2:");
    scanf("%d", &(*b));
}

void getOutput(double median)
{
    printf("Median after merging arrays %f", median);
}
int main()
{

    int size1, size2;
    getSize(&size1, &size2);
    int *arr1 = createArray(size1);
    int *arr2 = createArray(size2);

    double median = calculateMedian(arr1, arr2, size1, size2);

    getOutput(median);
    return 0;
}