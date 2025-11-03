#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    float cgpa;
    struct Student *left, *right;
};

struct Student *createNode(int id, float cgpa)
{
    struct Student *newNode = (struct Student *)malloc(sizeof(struct Student));
    newNode->id = id;
    newNode->cgpa = cgpa;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Student *insert(struct Student *root, int id, float cgpa)
{
    if (root == NULL)
        return createNode(id, cgpa);

    if (id < root->id)
        root->left = insert(root->left, id, cgpa);
    else if (id > root->id)
        root->right = insert(root->right, id, cgpa);

    return root;
}

struct Student *findMin(struct Student *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

struct Student *deleteNode(struct Student *root, int id)
{
    if (root == NULL)
        return root;

    if (id < root->id)
        root->left = deleteNode(root->left, id);
    else if (id > root->id)
        root->right = deleteNode(root->right, id);
    else
    {
        if (root->left == NULL)
        {
            struct Student *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Student *temp = root->left;
            free(root);
            return temp;
        }

        struct Student *temp = findMin(root->right);
        root->id = temp->id;
        root->cgpa = temp->cgpa;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

void inorder(struct Student *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -> %.1f\n", root->id, root->cgpa);
        inorder(root->right);
    }
}

int main()
{
    struct Student *root = NULL;

    root = insert(root, 50, 8.2);
    root = insert(root, 30, 7.5);
    root = insert(root, 70, 9.1);
    root = insert(root, 20, 6.8);
    root = insert(root, 40, 7.9);
    root = insert(root, 60, 8.4);
    root = insert(root, 80, 9.3);

    root = deleteNode(root, 20);
    root = deleteNode(root, 70);

    printf("Student Records in Ascending Order:\n");
    inorder(root);

    return 0;
}
