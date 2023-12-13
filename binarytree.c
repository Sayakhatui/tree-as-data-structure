#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

// for the preorder tree traversal
void PreOrder(struct BinaryTreeNode *root)
{
    if (root)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// create a New Node
struct BinaryTreeNode *createNode(int value)
{
    struct BinaryTreeNode *newNode = malloc(sizeof(struct BinaryTreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
struct BinaryTreeNode *insertLeft(struct BinaryTreeNode *root, int value)
{
    if (root->left == NULL)
    {
        root->left = createNode(value);
        return root->left;
    }
    else
    {
        printf("Enter number to be inserted to left child: ");
        scanf("%d", &value);
        return insertLeft(root->left, value);
    }
}

// Insert on the right of the node
struct BinaryTreeNode *insertRight(struct BinaryTreeNode *root, int value)
{
    if (root->right == NULL)
    {
        root->right = createNode(value);
        return root->right;
    }
    else
    {
        printf("Enter number to be inserted to the right child: ");
        scanf("%d", &value);
        return insertRight(root->right, value);
    }
}

int main()
{
    struct BinaryTreeNode *root = createNode(1);

    int c, value;

    while (1)
    {
        printf("\n1. Add node to the left child\n2. Add node to the right child\n3. Print in preorder\n4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter number to be inserted to the left child: ");
            scanf("%d", &value);
            insertLeft(root, value);
            break;
        case 2:
            printf("Enter number to be inserted to the right child: ");
            scanf("%d", &value);
            insertRight(root, value);
            break;
        case 3:
            printf("PreOrder Traversal\n");
            PreOrder(root);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice. Try again!\n");
            break;
        }
    }

    return 0;
}
