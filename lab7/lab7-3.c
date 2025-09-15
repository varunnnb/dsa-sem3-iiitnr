#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff, power;
    struct Node *prev, *next;
};

void insertTerm(struct Node **head, int coeff, int power)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = newNode->prev = newNode;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *curr = *head;
    do
    {
        if (power > curr->power)
            break;
        curr = curr->next;
    } while (curr != *head);

    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    if (power > (*head)->power)
        *head = newNode;
}

void printPoly(struct Node *head)
{
    if (!head)
    {
        printf("0\n");
        return;
    }
    struct Node *curr = head;
    do
    {
        printf("%d", curr->coeff);
        if (curr->power > 0)
            printf("x^%d", curr->power);
        if (curr->next != head)
            printf(" + ");
        curr = curr->next;
    } while (curr != head);
    printf("\n");
}

struct Node *addPoly(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *p1 = head1, *p2 = head2;
    if (!p1 && !p2)
        return NULL;

    do
    {
        int c1 = p1 ? p1->coeff : 0, pow1 = p1 ? p1->power : -1;
        int c2 = p2 ? p2->coeff : 0, pow2 = p2 ? p2->power : -1;

        if (p1 && (!p2 || pow1 > pow2))
        {
            insertTerm(&result, c1, pow1);
            p1 = p1->next;
            if (p1 == head1)
                p1 = NULL;
        }
        else if (p2 && (!p1 || pow2 > pow1))
        {
            insertTerm(&result, c2, pow2);
            p2 = p2->next;
            if (p2 == head2)
                p2 = NULL;
        }
        else if (p1 && p2 && pow1 == pow2)
        {
            insertTerm(&result, c1 + c2, pow1);
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == head1)
                p1 = NULL;
            if (p2 == head2)
                p2 = NULL;
        }
    } while (p1 || p2);

    return result;
}

int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL;
    int n1, n2, coeff, power;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter coefficient and power for term %d of Polynomial 1 (e.g. 3 2 for 3x^2): ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly1, coeff, power);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter coefficient and power for term %d of Polynomial 2 (e.g. 5 3 for 5x^3): ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertTerm(&poly2, coeff, power);
    }

    printf("Polynomial 1: ");
    printPoly(poly1);
    printf("Polynomial 2: ");
    printPoly(poly2);

    struct Node *result = addPoly(poly1, poly2);
    printf("Result: ");
    printPoly(result);

    struct Node *curr, *temp;
    curr = poly1;
    if (curr)
    {
        do
        {
            temp = curr;
            curr = curr->next;
            free(temp);
        } while (curr != poly1);
    }
    curr = poly2;
    if (curr)
    {
        do
        {
            temp = curr;
            curr = curr->next;
            free(temp);
        } while (curr != poly2);
    }
    curr = result;
    if (curr)
    {
        do
        {
            temp = curr;
            curr = curr->next;
            free(temp);
        } while (curr != result);
    }

    return 0;
}