#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data; /* data */
   struct Node *left,*right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node*insert(struct Node*root,int value){
    if (root == NULL)
    return createNode(value);
    if(value < root->data)
    root->left = insert(root->left,value);
    else if (value > root->data)
    root->right = insert(root->right,value);
    return root;
}
