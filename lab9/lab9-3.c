#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode *buildFullBinaryTree(int *pre, int *post, int *preIndex, int postStart, int postEnd, int n)
{
    if (*preIndex >= n || postStart > postEnd)
        return NULL;

    TreeNode *root = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (postStart == postEnd || *preIndex >= n)
        return root;

    int leftChild = pre[*preIndex];
    int i;
    for (i = postStart; i <= postEnd; i++)
    {
        if (post[i] == leftChild)
            break;
    }
    if (i > postEnd)
        return NULL;

    if (i < postEnd - 1)
    {
        root->left = buildFullBinaryTree(pre, post, preIndex, postStart, i, n);
        root->right = buildFullBinaryTree(pre, post, preIndex, i + 1, postEnd - 1, n);
    }
    else
    {
        return NULL;
    }
    return root;
}

void printLevelOrder(TreeNode *root)
{
    if (!root)
    {
        printf("[]\n");
        return;
    }
    TreeNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int idx = 0;
    int vals[100];
    while (front < rear)
    {
        TreeNode *node = queue[front++];
        vals[idx++] = node->val;
        if (node->left)
            queue[rear++] = node->left;
        if (node->right)
            queue[rear++] = node->right;
    }
    printf("[");
    for (int i = 0; i < idx; i++)
    {
        printf("%d", vals[i]);
        if (i < idx - 1)
            printf(",");
    }
    printf("]\n");
}

int main()
{
    int preorder1[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder1[] = {4, 5, 2, 6, 7, 3, 1};
    int n1 = sizeof(preorder1) / sizeof(preorder1[0]);
    int preIndex1 = 0;
    TreeNode *root1 = buildFullBinaryTree(preorder1, postorder1, &preIndex1, 0, n1 - 1, n1);
    if (root1)
        printLevelOrder(root1);
    else
        printf("\"Network topology cannot be uniquely reconstructed\"\n");

    int preorder2[] = {1, 2, 3};
    int postorder2[] = {2, 3, 1};
    int n2 = sizeof(preorder2) / sizeof(preorder2[0]);
    int preIndex2 = 0;
    TreeNode *root2 = buildFullBinaryTree(preorder2, postorder2, &preIndex2, 0, n2 - 1, n2);
    if (root2)
        printLevelOrder(root2);
    else
        printf("\"Network topology cannot be uniquely reconstructed\"\n");

    return 0;
}