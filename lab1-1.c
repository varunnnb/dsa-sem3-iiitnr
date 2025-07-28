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

    printf("\nEnter element to insert: ");
    int a;
    scanf("%d", &a);
    printf("\nEnter index: ");
    int p;
    scanf("%d", &p);
    if (p < 0 || p > n)
    {
        printf("invalid index");
    }

    else if (p == n)
    {
        n++;
        arr[n] = a;

        printf("new array:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
    }

    else
    {
        n++;
        int t1 = arr[p];
        arr[p] = a;
        for (int i = p + 1; i <= n; i++)
        {
            int t2 = arr[i];
            arr[i] = t1;
            t1 = t2;
        }
        printf("new array:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
    }

    printf("\nenter element to delete:");
    scanf("%d", &a);

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == a)
        {
            f = 1;
            if (i == n)
            {
                n--;
                break;
            }

            else
            {
                for (int j = i; j < n; j++)
                {
                    arr[j] = arr[j + 1];
                }
                n--;
            }
        }
    }
    if (f == 0)
    {
        printf("element not found\n");
    }
    else
    {
        printf("new array:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }
    }

    return 0;
}
