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

    int sorted = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sorted = 0;
            break;
        }
    }

    if (sorted == 0)
    {

        for (int i = 0; i < n; i++)
        {
            int min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            int t = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = t;
        }

        printf("The sorted array is:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
    }

    else
    {
        printf("array is already sorted.\n");
    }

    printf("enter element to search:");
    int a;
    scanf("%d", &a);

    int low = 0;
    int high = n - 1;
    int found = 0;
    int steps = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        steps++;
        if (arr[mid] == a)
        {
            found = 1;
            break;
        }
        else if (arr[mid] < a)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found)
    {
        printf("element found.\n", low);
    }
    else
    {
        printf("element not found.\n", a);
    }

    printf("steps taken: %d\n", steps);
    return 0;
}