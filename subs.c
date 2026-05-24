#include<stdio.h>
#include<string.h>
#define max 200

void subLargeNumber(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int borrow = 0;
    int i, j;

    // Assume num1 >= num2 (for simplicity in exam)

    i = len1 - 1;
    j = len2 - 1;
    int k = 0;

    while(i >= 0 || j >= 0)
    {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        digit1 = digit1 - borrow;

        if(digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result[k++] = (digit1 - digit2) + '0';

        i--;
        j--;
    }

    result[k] = '\0';

    // Reverse result
    for(int p = 0; p < k/2; p++)
    {
        char temp = result[p];
        result[p] = result[k - p - 1];
        result[k - p - 1] = temp;
    }

    // Remove leading zeros
    int start = 0;
    while(result[start] == '0' && result[start+1] != '\0')
        start++;

    printf("Subtraction Result: %s\n", result + start);
}

int main()
{
    char num1[max], num2[max], result[max];

    printf("Enter first large number: ");
    scanf("%s", num1);

    printf("Enter second large number: ");
    scanf("%s", num2);

    subLargeNumber(num1, num2, result);

    return 0;
}
