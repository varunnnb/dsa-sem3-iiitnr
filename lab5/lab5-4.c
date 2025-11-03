<<<<<<< HEAD
#include <stdio.h>

int main()
{
    int map[11];
    for (int i = 0; i < 11; i++)
    {
        map[i] = -1;
    }

    while (1)
    {
        int a;
        printf("Enter element to insert (-1 to stop): ");
        scanf("%d", &a);

        if (a == -1)
            break;

        int k = a % 11;
        int start = k;
        int i = 1;

        while (map[k] != -1)
        {
            k = (start + i * i) % 11;
            if (k == start)
            {
                printf("Hash table is full, cannot insert %d\n", a);
                goto end;
            }
            i++;
        }

        map[k] = a;
    }

end:
    printf("\nHash table:\n");
    for (int i = 0; i < 11; i++)
    {
        if (map[i] != -1)
            printf("index %d: %d\n", i, map[i]);
        else
            printf("index %d: Empty\n", i);
    }

    printf("\nProgram ended.\n");
    return 0;
}
=======
#include <stdio.h>

int main()
{
    int map[11];
    for (int i = 0; i < 11; i++)
    {
        map[i] = -1;
    }

    while (1)
    {
        int a;
        printf("Enter element to insert (-1 to stop): ");
        scanf("%d", &a);

        if (a == -1)
            break;

        int k = a % 11;
        int start = k;
        int i = 1;

        while (map[k] != -1)
        {
            k = (start + i * i) % 11;
            if (k == start)
            {
                printf("Hash table is full, cannot insert %d\n", a);
                goto end;
            }
            i++;
        }

        map[k] = a;
    }

end:
    printf("\nHash table:\n");
    for (int i = 0; i < 11; i++)
    {
        if (map[i] != -1)
            printf("index %d: %d\n", i, map[i]);
        else
            printf("index %d: Empty\n", i);
    }

    printf("\nProgram ended.\n");
    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
