#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int digit;
    struct Node *prev, *next;
};

void append(struct Node **head, int digit)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d", temp->digit);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *addLists(struct Node *head1, struct Node *head2)
{
    struct Node *tail1 = head1, *tail2 = head2;
    while (tail1 && tail1->next)
        tail1 = tail1->next;
    while (tail2 && tail2->next)
        tail2 = tail2->next;

    struct Node *result = NULL;
    int carry = 0;
    while (tail1 || tail2 || carry)
    {
        int sum = carry;
        if (tail1)
        {
            sum += tail1->digit;
            tail1 = tail1->prev;
        }
        if (tail2)
        {
            sum += tail2->digit;
            tail2 = tail2->prev;
        }
        append(&result, sum % 10);
        carry = sum / 10;
    }

    struct Node *prev = NULL, *curr = result, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    char num1[101], num2[101];
    printf("Enter first large integer: ");
    scanf("%100s", num1);
    printf("Enter second large integer: ");
    scanf("%100s", num2);

    struct Node *head1 = NULL, *head2 = NULL;
    for (int i = 0; num1[i]; i++)
        append(&head1, num1[i] - '0');
    for (int i = 0; num2[i]; i++)
        append(&head2, num2[i] - '0');

    struct Node *result = addLists(head1, head2);

    printf("Sum: ");
    printList(result);

    struct Node *temp;
    while (head1)
    {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2)
    {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }
    while (result)
    {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}