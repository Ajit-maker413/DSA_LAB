#include<stdio.h>
#define max_size 5

int full(int *front, int *rear)
{
    return ((*rear + 1) % max_size == *front);
}

void insertElement(int *arr, int data, int *front, int *rear)
{
    if(full(front, rear))
    {
        printf("Queue is Full !!\n");
        return;
    }

    if(*front == -1)
        *front = 0;

    *rear = (*rear + 1) % max_size;
    arr[*rear] = data;
}

int deleteElement(int *arr, int *front, int *rear)
{
    if(*front == -1)
    {
        printf("Underflow !!\n");
        return -1;
    }

    int value = arr[*front];

    if(*front == *rear)
        *front = *rear = -1;
    else
        *front = (*front + 1) % max_size;

    return value;
}

int main()
{
    int front = -1, rear = -1;
    int arr[max_size];

    insertElement(arr,5,&front,&rear);
    insertElement(arr,4,&front,&rear);
    insertElement(arr,7,&front,&rear);
    insertElement(arr,3,&front,&rear);
    insertElement(arr,8,&front,&rear);
    insertElement(arr,9,&front,&rear); // will show full

    printf("Deleted element is: %d\n",
           deleteElement(arr,&front,&rear));

    return 0;
}
