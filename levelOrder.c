#include<stdio.h>
#include<stdlib.h>
#define max 100
int queue[max];
int front=-1;
int rear=-1;

void enque(int queue[],int data)
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

int deque (int queue[])
{
    if(rear == -1)
    {
        printf("underflow\n");
        return NULL;
    }
    int res=queue[++front];
    return front;
}

struct Node
{
    
}