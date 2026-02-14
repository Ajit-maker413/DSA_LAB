#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[10];
    char arr2[10];
    gets(arr1);
    gets(arr2);
    strrev(arr1);
    strrev(arr2);
    printf("%s \n",arr1);
    printf("%s \n",arr2);
    int n=strlen(arr1); 
    int m=strlen(arr2);
    int length;
    if (n>m)
    {
        length=m;
    }
    else{
        length=n;
    }
     int sum=0;
     int carry;
     int result[m+n+1];
    for(int i=0;i<length;i++)
    {
        sum= sum+arr1[i]-'0'+arr2[i]-'0';
        if(sum>10)
        {
            carry=sum-10;
            sum=sum-carry;
            result[i]=sum;
        }
         sum=0;
         carry=0;
    }
    for(int i=0;i<length)
}