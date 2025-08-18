#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createList()
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
    return head;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node *head)
{
    if (!head)
        return;
    int swapped;
    struct Node *ptr1, *lptr = NULL;
    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

struct Node *mergeSortedLists(struct Node *l1, struct Node *l2)
{
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1)
        tail->next = l1;
    if (l2)
        tail->next = l2;
    return dummy.next;
}

int main()
{
    printf("Create first linked list:\n");
    struct Node *head1 = createList();

    printf("Create second linked list:\n");
    struct Node *head2 = createList();

    sortList(head1);
    sortList(head2);

    printf("First sorted linked list: ");
    printList(head1);

    printf("Second sorted linked list: ");
    printList(head2);

    struct Node *mergedHead = mergeSortedLists(head1, head2);

    printf("Merged sorted linked list: ");
    printList(mergedHead);

    return 0;
}