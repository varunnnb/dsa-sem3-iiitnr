#include <stdio.h>
int main()
{
    printf("No of elements in array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    printf("selection sort:\n");

    for (int i = 0; i < n; i++)
    {
        int max_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max_index])
            {
                max_index = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = t;
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
        printf("\n");
    }

    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    return 0;
}