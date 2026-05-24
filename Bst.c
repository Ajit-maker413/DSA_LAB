#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right; 
};

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

// ✔ FIXED INSERT
struct Node* insertElement(struct Node* root,int data)
{
    if (root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insertElement(root->left,data);
    else if(data > root->data)
        root->right = insertElement(root->right,data);

    return root;
}

// inorder
void inorder(struct Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// ✔ FIXED POSTORDER
void postorder(struct Node* root)
{
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

// ✔ FIND MIN
struct Node* Min(struct Node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

// ✔ FIXED DELETE
struct Node* deleteNode(struct Node* root,int data)
{
    if(root == NULL) return NULL;

    if(data < root->data)
        root->left = deleteNode(root->left,data);

    else if(data > root->data)
        root->right = deleteNode(root->right,data);

    else
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // 1 child
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // 2 children
        else
        {
            struct Node* temp = Min(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    struct Node* root=NULL;
    int arr[]={10,20,30,40,50,60};

    for(int i=0;i<6;i++)
        root=insertElement(root,arr[i]);

    printf("Inorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    // delete example
    root = deleteNode(root,30);

    printf("\nAfter Delete: ");
    inorder(root);

    return 0;
}