#include<stdio.h>
#include<string.h>
#define max 100
void subLargeNumber(char num1[],char num2[],char result[])
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    
    int i,sub,c=0;

    char revNum1[max],revNum2[max];
    for(int i=0;i<len1;i++){
        revNum1[i]=num1[len1-i-1];
    }
    revNum1[len1]='\0';
    for(int i=0;i<len2;i++){
        revNum2[i]=num2[len2-i-1];
    }
    revNum2[len2]='\0';

  int maxLen=len1>len2 ? len1: len2;
   int big;
   if(len1==len2)
   {
  for(int i=0;i<len1;i++)
  {
    if(num1[i]>num2[i])
    {
        big =len1;
    }
    if(num1[i]<num2[i])
    {
        big =len2;
    }
  }
}
  if(len1>len2)
  {
    big=len1;
  }
  if(len1<len2)
  {
    big=len2;
  }
  int digit1,digit2;
  for(int i=0;i<maxLen+1;i++)
  {
    if(big==len1)
    {
       digit1=(i<len1)?revNum1[i]-'0': 0;

       digit2=(i<len2)?revNum2[i]-'0': 0;
    } 
    if(big==len2)
    {
         digit1=(i<len2)?revNum2[i]-'0': 0;
         
         digit2=(i<len1)?revNum1[i]-'0': 0;
    }
     if(c==1)
     {
        digit1=digit1-c;
     }

    if(digit1<digit2)
    {
        digit1=digit1+10;
        sub=digit1-digit2;
        c=1;
    }
    else{
        sub=digit1-digit2;
        c=0;
    }
    result[i]=sub+'0';

  }
  result[max]='\0';

  int resultLen=strlen(result);
  for(int i=0;i<resultLen/2;i++)
  {
    char temp=result[i];
    result[i]=result[resultLen-i-1];
    result[resultLen -i-1]=temp;
  }
   for(int i=0;i<strlen(result);i++)
   {
      
   }
   int length=strlen(result) ,k=0;
  for(int i=0;i<strlen(result);i++)
  {
    if(result[i]=='0')
    {
        continue;
    }
    if(result[i] !='0')
    [
        printf("Substraction of two number is : \n %s",result);
    ]
  }
   printf(" );
   for(int i=length;i<strlen(result);i++){
    printf("%s",result[i]);
   }
 

}
int main(){

    char num1[max],num2[max],result[max+1];
    printf(" Enter the first large integer \n");
    scanf("%s",num1);
    printf(" Enter the first large integer \n");
    scanf("%s",num2);
  subLargeNumber(num1, num2,result);
}