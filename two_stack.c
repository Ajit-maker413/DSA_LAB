#include<stdio.h>
#define max_size 100

void push(int data, int stack[], int *top)
{
    if(*top == max_size - 1)
    {
        printf("Overflow !!\n");
        return;
    }

    (*top)++;
    stack[*top] = data;
}

int pop(int stack[], int *top)
{
    if(*top == -1)
    {
        printf("Underflow !!\n");
        return -1;
    }

    int value = stack[*top];
    (*top)--;

    return value;
}

int main()
{
    int stack[max_size];
    int top = -1;

    push(10, stack, &top);
    push(20, stack, &top);
    push(30, stack, &top);

    printf("Deleted element: %d\n", pop(stack, &top));

    return 0;
}
