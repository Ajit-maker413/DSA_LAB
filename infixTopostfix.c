#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int prec(char value)
{
    if(value =='^')
    {
    return 3;
    }
    if(value =='*' || value =='/')
    {
        return 2;
    }
    if(value =='+' || value =='-')
    {
        return 1;
    }
     return -1;

}

int  rigthPrecedence(char c)
{
    if(c=='^')
   return '^';
}

void InfixToPostfix(char *arr)
{
    int len=strlen(arr);
    char result[12];
    char stack[11];
    int j=0;
    int top=-1;
   for(int i=0;i<len;i++)
   {
    char c=arr[i];
    if(isalnum(c))
    {
        result[j++]=c;

    }
    else
    {
       if(c=='(')
      {
         stack[++top]=c;
      }
       if(c==')')
       {
        while(top !=-1 && stack[top] != ')')
        {
            result[j++]=stack[top--];
        }
        result[j++]=c;
       }

       // means opearotr

       else
       {

        while(top != -1 && stack[top] != '('  && prec(stack[top])>=prec(c)  && !rigthPrecedence(c))
        {
            result[j++]=stack[top--];
        }
          
         stack[++top]=c; 
       }      
     }
      while(top != -1)
       {
        result[j++]=stack[--top];
       }
       result[j]='\0';
       printf("%s",result);
   }

    
    

}
int main()
{
    char arr[]={1+2-3*5*4^2};
  
    InfixToPostfix(arr);
}