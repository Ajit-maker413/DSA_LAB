#include<stdio.h>
#include<string.h>

#define MAX 200

void multiply(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int temp[MAX] = {0};   // store intermediate result

    // Multiply like manual method
    for(int i = len1 - 1; i >= 0; i--)
    {
        for(int j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + temp[i + j + 1];

            temp[i + j + 1] = sum % 10;
            temp[i + j] += sum / 10;
        }
    }

    // Convert to string (skip leading zeros)
    int i = 0, k = 0;

    while(i < len1 + len2 && temp[i] == 0)
        i++;

    if(i == len1 + len2)
    {
        result[k++] = '0';
    }
    else
    {
        while(i < len1 + len2)
            result[k++] = temp[i++] + '0';
    }

    result[k] = '\0';
}

int main()
{
    char num1[MAX], num2[MAX], result[MAX];

    printf("Enter first large number: ");
    scanf("%s", num1);

    printf("Enter second large number: ");
    scanf("%s", num2);

    multiply(num1, num2, result);

    printf("Multiplication Result: %s\n", result);

    return 0;
}
