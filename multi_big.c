#include<stdio.h>
#include<string.h>
#define max 100
void multiLargeNumber(char num1[],char num2[],char result[])
{
    int len1=strlen(num1);
    int len2=strlen(num2);
    int i,c=0;

    char revNum1[max],revNum2[max];
    for(int i=0;i<len1;i++){
        revNum1[i]=num1[len1-i-1];
    }
    revNum1[len1]='\0';
    for(int i=0;i<len2;i++){
        revNum2[i]=num2[len2-i-1];
    }
    revNum2[len2]='\0';
       for(int i = 0; i < max; i++)
        result[i] = '0';
    

  int maxLen=len1+len2;
    int multi,rem,carry=0;
    int dis=0;
      for(int k=0;k<len1;k++)
      {
        int digit1=revNum1[k]-'0';
        carry=0;
         for(int j=0;j<len2;j++)
         {

            int digit2=revNum2[j] - '0';
             multi=digit1*digit2+carry;
             if(multi>10)
             {
            
                carry=multi/10;
                multi=multi%10;
      
                result[k+j+dis]=result[k+j+dis]+multi;

             }
             else{
                result[k+j+dis]=result[k+j+dis]+multi;
             }
             
         }
         if( carry>0)
             {
                result[k+len2+dis]= result[k+dis]+carry;
             }
          dis++;
       
      }
    
  result[len1+len2]='\0';

  for(int i = 0; i < len1 + len2; i++)
    result[i] += '0';
result[len1+len2] = '\0';


  int resultLen=strlen(result);
  for(int i=0;i<resultLen/2;i++)
  {
    char temp=result[i];
    result[i]=result[resultLen-i-1];
    result[resultLen -i-1]=temp;
  }
   printf("sum of the two integer   : %s\n",result);

}
int main(){

    char num1[max],num2[max],result[max+1];
    printf(" Enter the first large integer \n");
    scanf("%s",num1);
    printf(" Enter the first large integer \n");
    scanf("%s",num2);
  multiLargeNumber(num1, num2,result);

}
