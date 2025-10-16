#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char *val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(char *val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = strdup(val);
    node->left = node->right = NULL;
    return node;
}

int findIndex(char *arr[], int start, int end, char *value)
{
    for (int i = start; i <= end; i++)
    {
        if (strcmp(arr[i], value) == 0)
            return i;
    }
    return -1;
}

TreeNode *buildTreeUtil(char *inorder[], char *postorder[], int inStart, int inEnd, int *postIndex)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    root->right = buildTreeUtil(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTreeUtil(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

TreeNode *buildTree(char *inorder[], char *postorder[], int n)
{
    int postIndex = n - 1;
    return buildTreeUtil(inorder, postorder, 0, n - 1, &postIndex);
}

typedef struct Queue
{
    TreeNode **data;
    int front, rear, size;
} Queue;

Queue *createQueue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (TreeNode **)malloc(sizeof(TreeNode *) * size);
    q->front = q->rear = 0;
    q->size = size;
    return q;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, TreeNode *node)
{
    if (q->rear < q->size)
        q->data[q->rear++] = node;
}

TreeNode *dequeue(Queue *q)
{
    if (isEmpty(q))
        return NULL;
    return q->data[q->front++];
}

void printLevelOrder(TreeNode *root)
{
    if (!root)
    {
        printf("[]\n");
        return;
    }

    Queue *q = createQueue(100);
    enqueue(q, root);

    TreeNode *levelOrder[200];
    int idx = 0;

    while (!isEmpty(q))
    {
        TreeNode *node = dequeue(q);
        levelOrder[idx++] = node;
        if (node)
        {
            enqueue(q, node->left);
            enqueue(q, node->right);
        }
    }

    int lastNonNull = idx - 1;
    while (lastNonNull >= 0 && levelOrder[lastNonNull] == NULL)
        lastNonNull--;

    printf("[");
    for (int i = 0; i <= lastNonNull; i++)
    {
        if (levelOrder[i])
            printf("\"%s\"", levelOrder[i]->val);
        else
            printf("null");
        if (i < lastNonNull)
            printf(",");
    }
    printf("]\n");
}

int main()
{
    char *inorder[] = {"Eve", "Adam", "Cain", "Abel", "Seth"};
    char *postorder[] = {"Eve", "Cain", "Abel", "Seth", "Adam"};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    TreeNode *root = buildTree(inorder, postorder, n);

    printLevelOrder(root);

    return 0;
}