<<<<<<< HEAD
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

TreeNode *buildTreeUtil(char *preorder[], char *inorder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    root->left = buildTreeUtil(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

TreeNode *buildTree(char *preorder[], char *inorder[], int n)
{
    int preIndex = 0;
    return buildTreeUtil(preorder, inorder, 0, n - 1, &preIndex);
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
    char *preorder[] = {"root", "docs", "assignments", "photos", "music"};
    char *inorder[] = {"assignments", "docs", "root", "photos", "music"};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode *root = buildTree(preorder, inorder, n);

    printLevelOrder(root);

    return 0;
}
=======
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

TreeNode *buildTreeUtil(char *preorder[], char *inorder[], int inStart, int inEnd, int *preIndex)
{
    if (inStart > inEnd)
        return NULL;

    TreeNode *root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return root;

    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    root->left = buildTreeUtil(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return root;
}

TreeNode *buildTree(char *preorder[], char *inorder[], int n)
{
    int preIndex = 0;
    return buildTreeUtil(preorder, inorder, 0, n - 1, &preIndex);
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
    char *preorder[] = {"root", "docs", "assignments", "photos", "music"};
    char *inorder[] = {"assignments", "docs", "root", "photos", "music"};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    TreeNode *root = buildTree(preorder, inorder, n);

    printLevelOrder(root);

    return 0;
}
>>>>>>> 4c34cbbf97de81bf10cb98bbf1452083e678c8a0
