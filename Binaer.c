#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* craeteNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
// insert
struct Node* insert(struct Node* root,int data)
{
    if(root==NULL)
    {
        return craeteNode(data);
    }
    if(data<root->data)
    {
        root ->left=insert(root->left,data);
    }
    else
    {
        root ->right=insert(root->right,data);
    }
  return root;

}

// min 
struct Node* Min(struct Node* root)
{
    while(root->left !=  NULL)
    {
       root=root->left; 
    }
    return root;
}

// delete
struct Node* deleteNode(struct Node* root,int data)
{
    if(root== NULL)
    {
        return NULL;
    }
    if(data<root->data)
    {
        root->left=deleteNode(root->left,data);
    }
   else if(data>root->data)
    {
        root->right=deleteNode(root->right,data);
    }
    else
    {
    if(root->left== NULL && root ->right == NULL)
    {
        free(root);
        return NULL;
        
    }
     else if(root->left==NULL)
    {
       struct Node* temp=root->right;
       free(root);
       return temp; 
    }
     else if(root->right==NULL)
    {
       struct Node* temp=root->left;
       free(root);
       return temp; 
    }

    else
    {
        struct Node* temp=Min(root->right);
        root ->data=temp->data;
        root->right=deleteNode(root->right,temp->data);

    }
    }
    return root;
    
}


// max_path
int  maxSum =INT_MIN;

int slove(struct Node* root)
{
    
    if(root == NULL)
    {
        return 0;
    }

    int l=slove(root->left);
    int r= slove(root->right);

    int neeche_mil_gya=l+r+root->data;

    int koi_ek=max(l,r)+root ->data;

    int root_only=root->data;
    maxSum = max(maxSum, max(neeche_mil_gya, max(koi_ek, root_only)));
    return max(koi_ek,root_only);
}

// range based

void range(struct Node* root,int low ,int high)
{
    if(root == NULL)
    {
        return ;
    }

    if(root ->data >high)
    {
        range(root->left,low,high);
    }
  else if(root ->data <low)
    {
        range(root->right,low,high);
    }
    else{
        range(root->left,low,high);
        printf("%d",root->data);
        range(root->right,low,high);
    }
}



// sucessor and predesoor 

struct Node* getPredSucc(struct Node* root,int key)
{
    if(root == NULL) return NULL;
    struct Node* curr=root;
    struct Node* pre =NULL;
    struct Node* succ=NULL;

    while(curr != NULL)
    {.
        if(key <curr->data)
        {
            succ=
        }
    }

}
struct Node* lefttMost(struct Node* root)
{
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root;
}
struct Node* rightMost(struct Node* root)
{
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root;
}


struct Node* presucc(struct Node* root,int key)
{
   if(root == NULL)
      return NULL;
if(root ->data >key)
{
  root ->left=presucc(root->left,key);
}
else if(root ->data <key)
{
 root ->right=presucc(root->right,key); 
}
else{
     return root;
}
}

typedef struct Pair{
     struct Node *p1 , p2;
}Pair;
Pair*   solve(struct Node* root)
{
    struct Node * temp1=Max(root->left);
    struct Node* temp2 =Min(root->left);
    Pair* p = (Pair*) malloc(sizeof(Pair));

    p->p1 = temp1;
    p->p2 = temp2;
    return p;
}