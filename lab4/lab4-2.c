#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isPalindrome(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int *arr = (int *)malloc(count * sizeof(int));
    temp = head;
    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    int flag = 1;
    for (int i = 0, j = count - 1; i < j; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            flag = 0;
            break;
        }
    }
    free(arr);
    return flag;
}

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

    if (isPalindrome(head))
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}