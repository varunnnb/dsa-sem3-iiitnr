#include <stdio.h>

int main()
{
    int map[10];
    for (int i = 0; i < 10; i++)
    {
        map[i] = -1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("enter value to hash");
        int a;
        scanf("%d", &a);

        int k = a % 10;
        map[k] = a;
    }

    printf("enter element to search");
    int x;
    scanf("%d", &x);
    for (int i = 0; i < 10; i++)
    {
        if (map[i] == x)
        {
            printf("element at index %d\n", i);
            break;
        }

        if (i == 9 && map[i] != x)
        {
            printf("element not in hash\n");
        }
    }

    printf("\nhash table\n");
    for (int i = 0; i < 10; i++)
    {
        printf("index %d: %d\n", i, map[i]);
    }
}
