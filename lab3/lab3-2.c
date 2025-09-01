#include <stdio.h>

void merge_sorted_arrays(int left[], int n, int right[], int m, int res[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (left[i] <= right[j])
            res[k++] = left[i++];
        else
            res[k++] = right[j++];
    }
    while (i < n)
        res[k++] = left[i++];
    while (j < m)
        res[k++] = right[j++];
}

void merge_sort(int arr[], int l)
{
    if (l <= 1)
        return;
    int mid = l / 2;
    int left[mid], right[l - mid];
    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < l; i++)
        right[i - mid] = arr[i];
    merge_sort(left, mid);
    merge_sort(right, l - mid);
    merge_sorted_arrays(left, mid, right, l - mid, arr);
}

int main()
{
    printf("No of elements in array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("The elements of the array are:\n");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    merge_sort(arr, n);
    printf("\nsorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);
    return 0;
}
