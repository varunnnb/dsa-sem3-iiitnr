#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact
{
    char name[50];
    long long phone;
    struct Contact *left, *right;
};

struct Contact *createNode(char name[], long long phone)
{
    struct Contact *newNode = (struct Contact *)malloc(sizeof(struct Contact));
    strcpy(newNode->name, name);
    newNode->phone = phone;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Contact *insert(struct Contact *root, char name[], long long phone)
{
    if (root == NULL)
        return createNode(name, phone);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);
    else
        root->right = insert(root->right, name, phone);

    return root;
}

void inorder(struct Contact *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s -> %lld\n", root->name, root->phone);
        inorder(root->right);
    }
}

int main()
{
    struct Contact *root = NULL;

    root = insert(root, "John", 9876543210);
    root = insert(root, "Alice", 9012345678);
    root = insert(root, "Bob", 9123456780);
    root = insert(root, "Eve", 9988776655);
    root = insert(root, "Charlie", 9090909090);

    printf("Contacts in alphabetical order:\n");
    inorder(root);

    return 0;
}
