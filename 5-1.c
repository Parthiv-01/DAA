#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printRandoms(int *A, int lower, int upper, int count)
{
    int i;
    for (i = 0; i < count; i++)
    {
        int num = (rand() % (upper - lower)) + lower;
        A[i] = num;
    }
}

void printArr(int *arr, int count)
{
    printf("\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }
}

void sortArr(int *arr, int n, int range)
{
    int i, j;
    int *count = (int *)malloc((range + 1) * sizeof(int));
    for (int i = 0; i < range + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    i = 0;
    j = 0;
    while (i <= range)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int lower, upper, count;
    printf("\nEnter lower, upper value of elements & size of array : \n");
    scanf("%d %d %d", &lower, &upper, &count);
    int A[count];
    printRandoms(A, lower, upper, count);
    printf("\nArray before sorting is :");
    printArr(A, count);
    sortArr(A, count, upper);
    printf("\nArray after sorting is :");
    printArr(A, count);
    return 0;
}