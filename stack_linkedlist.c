#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;   // top pointer

// PUSH Operation
void push(int value)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Overflow !!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// POP Operation
int pop()
{
    if(top == NULL)
    {
        printf("Underflow !!\n");
        return -1;
    }

    struct node *temp = top;
    int value = temp->data;

    top = top->next;
    free(temp);

    return value;
}

// Display Stack
void display()
{
    struct node *temp = top;

    if(temp == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");

    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    printf("Deleted element: %d\n", pop());

    display();
    return 0;
}
