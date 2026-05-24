#include<stdio.h>
#include<stdlib.h>
#define max 100

struct Node* queue[max];
int front=-1;
int rear=-1;

void enque(struct Node* data)
{
    if(rear == max-1)
    {
        printf("orverflow\n");
        return;
    }
    if(front ==-1)
    {
        front=0;
    }
    queue[++rear]=data;
}

struct Node* deque ()
{
    if(front ==-1 || front>rear)
    {
        printf("underflow\n");
        return NULL;
    }
   
    return queue[front++];
}
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};


// stack
struct Node* stack[max];
int top =-1;

// for push

void push(struct Node* element)
{
    if(top == max-1)
    {
        printf("Overflow\n");
    }
    else{
        stack[++top]=element;
    }
}


// pop

struct Node* pop()
{
    if(top == -1)
    {
        printf("underflow\n");
        return NULL;
    }
   return stack[top--];
}

// create node
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode ->data=data;
    newNode ->left=NULL;
    newNode->right=NULL;
    return newNode;
}

// inserting elment

struct Node* insertElemnet(struct Node* root,int data)
{
    if(root == NULL)
    {
       struct Node* newNode=createNode(data);
       root=newNode;
       return root;
    }
    if(rand() % 2 == 0)
    {
      if(root ->left == NULL)
      {
        root ->left=createNode(data);
      }
      else{
        insertElemnet( root->left,data);
      }
    }
    else{
      if(root ->right == NULL)
      {
        root ->right=createNode(data);
      }
      else{
        insertElemnet( root->right,data);
      }

    }
    return root;
    
}

// inorder
void inorder(struct Node* root)
{ 
    if(root == NULL)
      return;

      inorder(root ->left);
      printf("%d",root ->data);
      inorder(root ->right);

}

// level 
void levelOrder(struct Node* root)
{
    if(root == NULL)
        return;

    enque(root);

    while(front <= rear)
    {
        struct Node* temp = deque();
        printf("%d ", temp->data);

        if(temp->left)
            enque(temp->left);

        if(temp->right)
            enque(temp->right);
    }
}
int main()
{
    struct Node* root = NULL;
    int arr[] = {10,20,30,40,50,60};

    for(int i=0; i<6; i++)
        root = insertElemnet(root ,arr[i]);

    printf("Recursive: ");
    inorder(root);
    printf("\nLevel Order: ");
    levelOrder(root);

    return 0;
}