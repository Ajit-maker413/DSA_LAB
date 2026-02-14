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
  int b[100];
  int sum=0;
  for(int i=0;i<100;i++)
   {
    b[i]=0;
   }

   for(int i=0;i<100;i++)
   {
   
      if(!method1(i))
      {
         b[i]++;
          sum=sum+b[i];
      }


    else{
        printf(" Floor Found !! \n");
        printf(" FOund at floor number : %d\n",i);
        printf(" Number of trail : %d \n:",sum);
        break;
    }
    
    
   }

}