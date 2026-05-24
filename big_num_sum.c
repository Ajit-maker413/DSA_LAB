#include <stdio.h>
#include <string.h>

#define MAX 10000 // Maximum digits for large numbers

void addLargeNumbers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, i, sum;

    // Reverse the strings to make addition easier
    char revNum1[MAX], revNum2[MAX];
    for (i = 0; i < len1; i++) {
        revNum1[i] = num1[len1 - i - 1];
    }
    revNum1[len1] = '\0';

    for (i = 0; i < len2; i++) {
        revNum2[i] = num2[len2 - i - 1];
    }
    revNum2[len2] = '\0';

    // Perform the addition
    int maxLen = len1 > len2 ? len1 : len2;
    for (i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? revNum1[i] - '0' : 0;
        int digit2 = (i < len2) ? revNum2[i] - '0' : 0;

        sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0'; // Store the current digit
        carry = sum / 10;             // Calculate the carry
    }

    // If there's a carry left, add it to the result
    if (carry) {
        result[i++] = carry + '0';
    }

    result[i] = '\0';

    // Reverse the result to get the final number
    int resultLen = strlen(result);
    for (i = 0; i < resultLen / 2; i++) {
        char temp = result[i];
        result[i] = result[resultLen - i - 1];
        result[resultLen - i - 1] = temp;
    }
}

int main() {
    char num1[MAX], num2[MAX], result[MAX + 1];

    printf("Enter the first large integer: ");
    scanf("%s", num1);

    printf("Enter the second large integer: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2, result);

    printf("The sum of the two large integers is: %s\n", result);

    return 0;
}