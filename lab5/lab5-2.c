#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node *map[], int key)
{
    int idx = key % 7;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = map[idx];
    map[idx] = newNode;
}

int search(struct Node *map[], int key)
{
    int idx = key % 7;
    struct Node *curr = map[idx];
    while (curr)
    {
        if (curr->data == key)
            return idx;
        curr = curr->next;
    }
    return -1;
}

void display(struct Node *map[])
{
    printf("\nhash table with chaining:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("index %d:", i);
        struct Node *curr = map[i];
        while (curr)
        {
            printf(" %d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Node *map[7];
    for (int i = 0; i < 7; i++)
        map[i] = NULL;

    for (int i = 0; i < 10; i++)
    {
        int key;
        printf("enter element to hash: ");
        scanf("%d", &key);
        insert(map, key);
    }

    display(map);

    int x;
    printf("Enter element to search: ");
    scanf("%d", &x);
    int idx = search(map, x);
    if (idx != -1)
        printf("Element %d found at index %d\n", x, idx);
    else
        printf("Element %d not found in hash table\n", x);

    for (int i = 0; i < 7; i++)
    {
        struct Node *curr = map[i];
        while (curr)
        {
            struct Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    return 0;
}
