#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;  
}
void insert_at_first(struct Node **head,int data)
{
    struct Node* newNode=createNode(data);
    newNode ->next=*head;
    *head=newNode;
}


void insert_at_last(struct Node **head,int data)
{
    struct Node* newNode=createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct Node* temp;
    while(temp ->next != NULL)
    {
      temp=temp ->next;
    }
}
/*void insert_at_random(int postion,struct Node **head,int data)
{
    struct Node* newNode=createNode(data);
    while(1)
    {
        if(temp ->data !=postion)
        {
            temp=temp ->next;
        }
        if(temp ->data ==postion)
        {

        }
    }   
}*/
void reverseList(struct Node ** head)
{

    
}
void printLinkedList(struct Node*head)
{
    struct Node* temp= head;
    while(1)
    {
        printf("%d \n",temp ->data);
        temp=temp ->next;
        if(temp ->next == NULL)
        {
           printf("%d \n",temp ->data); 
        }
        
    }

}

int main()
{
    struct Node* head=NULL;
    insert_at_first(&head,10);
    insert_at_first(&head,11);
    insert_at_first(&head,12);
    insert_at_first(&head,13);
    printLinkedList(head);

    
}