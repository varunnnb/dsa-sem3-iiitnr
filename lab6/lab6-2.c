<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    if (top < 99)
    {
        stack[++top] = c;
    }
    else
    {
        printf("overflow\n");
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        return '\0';
    }
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int checkBalanced(char expr[])
{
    for (int i = 0; i < strlen(expr); i++)
    {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            char popped = pop();
            if (!isMatching(popped, c))
            {
                return 0;
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char expr[100];

    printf("enter expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    if (checkBalanced(expr))
    {
        printf("balanced\n");
    }
    else
    {
        printf("not balanced\n");
    }

    return 0;
}
=======
#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    if (top < 99)
    {
        stack[++top] = c;
    }
    else
    {
        printf("overflow\n");
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        return '\0';
    }
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int checkBalanced(char expr[])
{
    for (int i = 0; i < strlen(expr); i++)
    {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            char popped = pop();
            if (!isMatching(popped, c))
            {
                return 0;
            }
        }
    }

    if (top == -1)
        return 1;
    else
        return 0;
}

int main()
{
    char expr[100];

    printf("enter expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    if (checkBalanced(expr))
    {
        printf("balanced\n");
    }
    else
    {
        printf("not balanced\n");
    }

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
