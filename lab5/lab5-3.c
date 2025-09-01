#include <stdio.h>

int main()
{
    int map[10];
    for (int i = 0; i < 10; i++)
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

        int k = a % 10;
        int start = k;
        while (map[k] != -1)
        {
            k = (k + 1) % 10;
            if (k == start)
            {
                printf("Hash table is full, cannot insert %d\n", a);
                goto end;
            }
        }

        map[k] = a;
    }

end:
    printf("\nHash table:\n");
    for (int i = 0; i < 10; i++)
        printf("index %d: %d\n", i, map[i]);

    printf("\nProgram ended.\n");
    return 0;
}
