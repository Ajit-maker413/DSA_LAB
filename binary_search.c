#include<stdio.h>
#include<stdbool.h>
int break_floor=30;
bool method1(int floor)
{
   if(floor<break_floor)
   {
   return false;
   }
   else
   return true;

}
int main()
{
    int start=1,end=100;
   
    int b[100];
    for(int i=0;i<100;i++)
    {
        b[i]=0;
    }
    int i=0;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        b[mid]=1;
        if(method1(mid))
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
  int sum=0;
    printf(" Foor break at : %d\n",mid);
    for(int i=0;i<100;i++)
    {
        printf(" %d",b[i]);
        sum=sum+b[i];
    }
     printf(" no. of trial %d\n",sum);

}