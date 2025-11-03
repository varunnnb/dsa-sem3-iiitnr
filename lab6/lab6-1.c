<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100][100];
int top = -1;

void push(char *str)
{
    if (top < 99)
    {
        strcpy(stack[++top], str);
    }
    else
    {
        printf("overflow\n");
    }
}

char *pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("underflow\n");
        return 0;
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

int main()
{
    char postfix[100];
    printf("enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    postfix[strcspn(postfix, "\n")] = 0;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char c = postfix[i];

        if (c == ' ' || c == '\t')
            continue;

        if (isOperand(c))
        {
            char op[2] = {toLowerCase(c), '\0'};
            push(op);
        }
        else if (isOperator(c))
        {
            char op1[100], op2[100], expr[100];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(expr, "%c%s%s", c, op1, op2);
            push(expr);
        }
    }

    printf("prefix expression: %s\n", stack[top]);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100][100];
int top = -1;

void push(char *str)
{
    if (top < 99)
    {
        strcpy(stack[++top], str);
    }
    else
    {
        printf("overflow\n");
    }
}

char *pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("underflow\n");
        return 0;
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isOperand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

char toLowerCase(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

int main()
{
    char postfix[100];
    printf("enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    postfix[strcspn(postfix, "\n")] = 0;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char c = postfix[i];

        if (c == ' ' || c == '\t')
            continue;

        if (isOperand(c))
        {
            char op[2] = {toLowerCase(c), '\0'};
            push(op);
        }
        else if (isOperator(c))
        {
            char op1[100], op2[100], expr[100];
            strcpy(op2, pop());
            strcpy(op1, pop());
            sprintf(expr, "%c%s%s", c, op1, op2);
            push(expr);
        }
    }

    printf("prefix expression: %s\n", stack[top]);

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
