<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void longest(struct Node *head)
{
    if (head == NULL)
    {
        printf("list empty.\n");
        return;
    }

    struct Node *curr = head;
    struct Node *start = head;
    struct Node *bestStart = head;

    int length = 1, bestLength = 1;

    while (curr->next != NULL)
    {
        if (curr->next->data > curr->data)
        {
            length++;
        }
        else
        {
            if (length > bestLength)
            {
                bestLength = length;
                bestStart = start;
            }
            start = curr->next;
            length = 1;
        }
        curr = curr->next;
    }

    if (length > bestLength)
    {
        bestLength = length;
        bestStart = start;
    }

    printf("longest seq: ");
    curr = bestStart;
    for (int i = 0; i < bestLength; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\nLength = %d\n", bestLength);
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        append(&head, value);
    }

    longest(head);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void longest(struct Node *head)
{
    if (head == NULL)
    {
        printf("list empty.\n");
        return;
    }

    struct Node *curr = head;
    struct Node *start = head;
    struct Node *bestStart = head;

    int length = 1, bestLength = 1;

    while (curr->next != NULL)
    {
        if (curr->next->data > curr->data)
        {
            length++;
        }
        else
        {
            if (length > bestLength)
            {
                bestLength = length;
                bestStart = start;
            }
            start = curr->next;
            length = 1;
        }
        curr = curr->next;
    }

    if (length > bestLength)
    {
        bestLength = length;
        bestStart = start;
    }

    printf("longest seq: ");
    curr = bestStart;
    for (int i = 0; i < bestLength; i++)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\nLength = %d\n", bestLength);
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        append(&head, value);
    }

    longest(head);

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
