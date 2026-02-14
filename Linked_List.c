#include<stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    
};

// creating a node
struct Node* Create_Node(int data)
{
    struct Node* NewNode=(struct Node*)malloc(sizeof(struct Node));
    NewNode ->data=data;
    NewNode ->next=NULL;
    return NewNode;

}
// creating node at begining

void insert_node_first(struct Node** head,int data)
{
    struct Node* newNode=Create_Node(data);
    newNode ->next=*head;
    *head=newNode;
}

// creating node at last

void insert_node_last(struct Node ** head,int data)
 {
    struct Node * newNode = Create_Node(data);
    if(*head==NULL)
    {
       return;
    }
    
     else{
        struct Node* temp=*head;
        while(1)
        {
        if(temp ->next ==NULL)
        {
            temp ->next=newNode;
            newNode ->next=NULL;
            break;
        }
         temp=temp ->next;
        }
    }
 }

 //  insert element at btw the linked list

 void insert_between(struct Node** head,int data,int postion)
 {
    
    struct Node* newNode=Create_Node(data);
    struct Node* temp=*head;
    struct Node* nextNode;
    while(1)
    {
        temp=temp ->next;
        if(temp ->data==postion)
        {
        nextNode=temp ->next;
        temp ->next=newNode;
        newNode ->next=nextNode;
        break;
        }
    }
  
 }

 // delete any node 
 void delete_node(struct Node** head,int postion)
 {
     struct Node* temp=*head;
     while(1)
     {
        if(temp ->next ->data==postion)
        {
            struct Node* newtemp= temp ->next
        }
     }
 }
 
// printing liked list

void printing_LinkedList(struct Node* head)
{
   struct Node* temp=head;
   while(1)
   {
    
     printf("%d \n",temp->data);
     temp=temp ->next;
      if( temp -> next == NULL)
      {
        printf("%d \n",temp->data);
        break;
      }
   }
}
int main()
{
    struct Node* head=NULL;
    insert_node_first(&head,10);
    insert_node_first(&head,11);
    insert_node_first(&head,12);
    insert_node_last(&head,13);
    insert_between(&head,14,13);
    insert_node_last(&head,15);
    insert_node_last(&head,16);
    printing_LinkedList(head);
}
