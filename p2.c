#include<stdio.h>
#include<stdbool.h>
#include<math.h>
int break_floor=31;
bool method2(int floor)
{
    int count=0;
  int key_value=sqrt(floor);
  int key=key_value;
  while(key<100)
  {
    
    count++;
    
    if(key>=break_floor)
    {
        for(int i=key-9;i<key;i++)
        {
          if(break_floor==i || break_floor==key)
          {
            printf(" Total number of trial :%d \n",count);
            printf("Floor number is : %d \n",i);
            return true ;
          }
          
        }

    }
    key=key+key_value;
  }
  return false;

}
int main()
{
   int floor=100;
   if(method2(floor))
   {
    printf("Found!!\n");
   }
   else
   {
    printf("not found\n");
   }
}
