#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;

};
//for the preorder tree traversal 
void PreOrder(struct BinaryTreeNode* root)
{
    if(root)
    {
        printf("%d",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
// for the postorder traversal
// void postOrder(struct BinaryTreeNode* root)
// {
//     if(root)
//     {
//         printf("%d ->",root->data);
        
//     }
// }
//create a New Node 
struct BinaryTreeNode* createNode(value)
{
    struct BinaryTreeNode* newNode= malloc(sizeof (struct BinaryTreeNode));
    newNode ->data=value;
    newNode -> left= NULL;
    newNode-> right =NULL;

    return newNode;

}

//Insert on the left of the node 
struct BinaryTreeNode* insertLeft (struct BinaryTreeNode* root,int value)
{
    root->left=createNode(value);
    return root->left;


}
//insert on the right of the node 
struct BinaryTreeNode* insertRight(struct BinaryTreeNode* root,int value )
{
    root->right=createNode(value);
    return root->right;
}
int main()
{
    struct BinaryTreeNode* root =createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);

    printf("PreOrder Traversal \n");
    PreOrder(root);
}