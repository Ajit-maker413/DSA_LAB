#include<stdio.h>
void transpose(char arr[3][3])
{
     for(int i=0;i<3;i++)
    {
     for(int j=0;j<3;j++)
     {
        char temp=arr[i][j];
        arr[i][j]=arr[j][i];
        arr[j][i]=temp;
     } 
    }

   for(int i=0;i<3;i++)
    {
     for(int j=0;j<3;j++)
     {
        printf(" %c",arr[i][j]);
     } 
      printf(" \n");
    }

}
int main()
{
    char arr[3][3];
    for(int i=0;i<3;i++)
    {
     for(int j=0;j<3;j++)
     {
        scanf("%c",&arr[i][j]);
     } 
    }
    transpose(arr);
}