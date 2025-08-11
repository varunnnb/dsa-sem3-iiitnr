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

    quicksort(arr, 0, n - 1);
    printf("\nsorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    return 0;
}

int partition(int arr[], int low, int high)
{
    int p = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] >= p && i < high)
        {
            i++;
        }
        while (arr[j] < p && j > low)
        {
            j--;
        }
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

int quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index - 1);
        quicksort(arr, p_index + 1, high);
    }
}