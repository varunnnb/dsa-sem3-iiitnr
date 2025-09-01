#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
};

int main()
{
    struct Node *head = NULL, *tail = NULL;
    int value;

    printf("Enter values for the linked list (-1 to stop):\n");
    while (1)
    {
        scanf("%d", &value);
        if (value == -1)
            break;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("linked list: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    head = reverseList(head);

    printf("reversed linked list: ");
    temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}