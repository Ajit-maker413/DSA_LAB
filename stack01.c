#include<stdio.h>
#define max 100
int stack[max];
int top =-1;
void insert_element(int stack[], int *top,int element)
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

int main()
{
     insert_element(stack,&top,10);
     insert_element(stack,&top,11);
     insert_element(stack,&top,12);
     insert_element(stack,&top,13);
     insert_element(stack,&top,14);
    //.................
     printf(" top element is : %d \n",top_element(stack,&top));


     // print stack
     print_stack(stack,&top);
     // pop  .............

     pop(stack,&top);
     pop(stack,&top);
    printf(" top element is : %d \n",top_element(stack,&top)) ;

    // ...........
    print_stack(stack,&top);
}
