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

    int comp = 0;
    int shift = 0;
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comp++;
            if (arr[j] > k)
            {
                arr[j + 1] = arr[j];
                j--;
                shift++;
            }
            else
            {
                break;
            }
        }
        shift++;
        arr[j + 1] = k;
    }

    printf("sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n%d comparisons %d shifts", comp, shift);

    return 0;
}