#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *cll(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = i;
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
    return head;
}

int joseph(int n, int k)
{
    struct Node *head = cll(n);
    struct Node *prev = NULL, *curr = head;

    while (curr->next != curr)
    {
        for (int i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    int win = curr->data;
    free(curr);
    return win;
}

int main()
{
    printf("n:");
    int n;
    scanf("%d", &n);
    printf("k:");
    int k;
    scanf("%d", &k);
    int win = joseph(n, k);
    printf("winner: %d\n", win);
    return 0;
}