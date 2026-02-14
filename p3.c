#include<stdio.h>
#include<stdbool.h>
int break_floor=31;
bool method3(int floor, int b[100])
{
    int s=1,end =floor;
    int count=0;
    while(s<=end)
    {
        count++;
        int mid=(s+end)/2;
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
            return true ;
        }
    }
    return false;
}
int main()
{
    int b[100];
    for(int i=0;i<100;i++)
   {
    b[i]=0;
   }
   int floor=100;
   if(method3(floor,b))
   {
    printf("Found!!\n");
   }
   else
   {
    printf("not found\n");
   }
   printf("array printed \n");
    for(int i=0;i<100;i++)
   {
     printf("%d ,",b[i]);
   }
}
