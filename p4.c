#include<stdio.h>
#include<stdbool.h>
int break_floor=31;
int floor=100;
bool check_floor(int floor)
{
    if(floor<check_floor)
    {
    return true;
    }
    else  
    return false;
}
int main()
{
    int b[100];
    for(int i=0;i<100;i++)
   {
    b[i]=0;
   }
   
   int s=1,end =floor;
   int mid=(s+end)/2;
    int count=0;
   while((end-s)>1)
    {
        count++;
        if(!check_floor(floor))
        {
        if(mid>break_floor)
        {
            end=mid-1;
            b[mid]++;
        }
        else if(mid<break_floor)
        {
            s=mid+1;
            b[mid]++;
        }
         else if(mid==break_floor)
        {
            b[mid]++;
            printf(" Total number of trial :%d \n",count);
            printf("Floor number is : %d \n",mid);
            
        }
     }
    }
   
   
   
}
