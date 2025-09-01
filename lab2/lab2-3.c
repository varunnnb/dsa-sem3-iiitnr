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

    int a;
    printf("enter element to search:");
    scanf("%d", &a);

    int comp = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            printf("element found at index %d\n", i);
            break;
        }
        else if (i == n - 1)
        {
            printf("element not found\n");
        }

        comp++;
    }

    printf("comparisons=%d\n", comp);
    return 0;
}