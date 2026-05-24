#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#define max 100
int stack[max];
int top =-1;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
void push(int stack[], int *top,int element)
{
    if(*top==max)
    {
        printf("overflow\n");

    }
    else{
        *top=*top+1;
        stack[*top]=element;
    }
}
int pop(int stack[],int *top)
{
    int element ;
    if(*top==-1)
    {
        printf("underflow\n");
        return 0;
    }
    else{
         element=*top;
        *top=*top-1;
    }
    return element;
}
int top_element(int stack[],int *top)
{
    if(*top == -1)
    {
        printf("underflow\n");
    }
    else{
        return stack[*top];
    }
    return 0;
}
void print_stack(int stack[],int *top)
{
    if(*top==-1)
    {
        printf("underflow\n");
    }
    else
    {
        int temp=*top;
        while (temp>-1)
        {
         printf("Element at index %d is %d :\n",temp,stack[temp]) ;
         temp=temp-1;  
        }
        
    }

}
struct Node*  createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode ->data=data;
    newNode ->left=NULL;
    newNode ->right=NULL;
    return newNode;
}
struct Node* insert_Element(struct Node* root ,int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    if(rand()% 2 ==0)
    {
        if(root ->left == NULL )
        {
           root ->left= createNode(data);
        }
        else
        {
          insert_Element(root->left,data);
        }
    }
    else
    {
       if(root ->right == NULL)
       {
        root ->right= createNode(data);
       
       }
       else
       {
         insert_Element(root ->right,data);
       }
    }
    return root;
}

void inorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf(" %d",root ->data);
    inorder(root->right);
}

void postorder(struct Node* root)
{
    if(root == NULL)
    {
        return;
    }
    printf(" %d",root ->data);
    postorder(root->left);
    
    postorder(root->right);
}
void inorder_it(struct Node* root)
{
    
    while (1)
    {
        while(root)
        {
            push(stack,&top,root ->data);
            root=root->left;
        }

        if(top == -1)
        {
            break;
        }
        printf("%d",pop(stack,&top));
        root=root ->right;
    }
    
}


int main()
{
    struct Node* root=NULL;
    int arr[]={10,20,30,40,50,60};
    for(int i=0 ;i< 6;i++)
    {
        printf("%d \n",rand());


        root=insert_Element(root ,arr[i]);
       
    }
    inorder(root);
    printf("\n");
    inorder_it(root);
}