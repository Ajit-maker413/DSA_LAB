#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure for characters
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

// Initialize stack
void initCharStack(CharStack *stack) {
    stack->top = -1;
}

// Check if stack is empty
bool isCharStackEmpty(CharStack *stack) {
    return stack->top == -1;
}

// Check if stack is full
bool isCharStackFull(CharStack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push character
void pushChar(CharStack *stack, char c) {
    if (!isCharStackFull(stack)) {
        stack->items[++stack->top] = c;
    }
}

// Pop character
char popChar(CharStack *stack) {
    if (!isCharStackEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0';
}

// Peek top character
char peekChar(CharStack *stack) {
    if (!isCharStackEmpty(stack)) {
        return stack->items[stack->top];
    }
    return '\0';
}

// Function to return precedence of operators
int precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack stack;
    initCharStack(&stack);
    
    int i = 0; // Index for infix expression
    int j = 0; // Index for postfix expression
    
    while (infix[i] != '\0') {
        char token = infix[i];
        
        // If token is an operand (letter or digit), add to postfix
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // If token is '(', push to stack
        else if (token == '(') {
            pushChar(&stack, token);
        }
        // If token is ')', pop and add to postfix until '(' is found
        else if (token == ')') {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
            }
            if (!isCharStackEmpty(&stack) && peekChar(&stack) == '(') {
                popChar(&stack); // Remove '('
            }
        }
        // If token is an operator
        else if (isOperator(token)) {
            while (!isCharStackEmpty(&stack) && 
                   precedence(peekChar(&stack)) >= precedence(token) &&
                   peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
            }
            pushChar(&stack, token);
        }
        
        i++;
    }
    
    // Pop remaining operators from stack
    while (!isCharStackEmpty(&stack)) {
        postfix[j++] = popChar(&stack);
    }
    
    postfix[j] = '\0'; // Null terminate the postfix expression
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix) {
    int stack[MAX_SIZE];
    int top = -1;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];
        
        if (isdigit(token)) {
            // If token is a digit, push its integer value
            stack[++top] = token - '0';
        } else {
            // If token is an operator, pop two operands and perform operation
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            
            switch(token) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
    }
    
    return stack[top];
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("=== Infix to Postfix Conversion ===\n");
    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline
    
    infixToPostfix(infix, postfix);
    
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    
    // Example with digits for evaluation
    printf("\n--- Evaluation Example ---\n");
    char expr[] = "23+5*"; // Equivalent to (2+3)*5
    printf("Postfix Expression: %s\n", expr);
    printf("Result: %d\n", evaluatePostfix(expr));
    
    return 0;
}