<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

#define max 100

struct Queue
{
    int data[max];
    int front, rear;
};

void enqueue(struct Queue *x, int a)
{
    if (x->rear < max - 1)
        x->data[++(x->rear)] = a;
}

int dequeue(struct Queue *x)
{
    if (x->front <= x->rear)
        return x->data[(x->front)++];
    return -1;
}

int isEmpty(struct Queue *x)
{
    return (x->front > x->rear);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    struct Queue x;
    x.front = 0;
    x.rear = -1;

    int temp = n;
    if (temp == 0)
    {
        enqueue(&x, 0);
    }
    else
    {
        while (temp > 0)
        {
            enqueue(&x, temp % 2);
            temp /= 2;
        }
    }

    printf("The binary representation of %d is: ", n);
    for (int i = x.rear; i >= x.front; i--)
    {
        printf("%d", x.data[i]);
    }
    printf("\n");

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

#define max 100

struct Queue
{
    int data[max];
    int front, rear;
};

void enqueue(struct Queue *x, int a)
{
    if (x->rear < max - 1)
        x->data[++(x->rear)] = a;
}

int dequeue(struct Queue *x)
{
    if (x->front <= x->rear)
        return x->data[(x->front)++];
    return -1;
}

int isEmpty(struct Queue *x)
{
    return (x->front > x->rear);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    struct Queue x;
    x.front = 0;
    x.rear = -1;

    int temp = n;
    if (temp == 0)
    {
        enqueue(&x, 0);
    }
    else
    {
        while (temp > 0)
        {
            enqueue(&x, temp % 2);
            temp /= 2;
        }
    }

    printf("The binary representation of %d is: ", n);
    for (int i = x.rear; i >= x.front; i--)
    {
        printf("%d", x.data[i]);
    }
    printf("\n");

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
