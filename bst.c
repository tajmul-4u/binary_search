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

int search(struct Node*root,int key){
    if(root == NULL)
    return 0;
    if (root->data == key)
    return 1;
    if(key < root->data)
    return search(root->left,key);
    else
    return search(root->right,key);
}

void inorder(struct Node*root){
    if(root != NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node*root = NULL;
    int values[] = {50,30,20,40,70,60,70};
    int n = sizeof(values)/sizeof(values[0]);
    for(int i = 0; i<n; i++)
    {
        root = insert(root, values[i]);
    }
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    int key = 60;
    if (search(root,key))
    printf("Key %d found in BST.\n",key);
    else
    printf("Key %d not found in BST.\n",key);
    
    return 0;
}