#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// Stack structure for parentheses checking
typedef struct {
    char items[MAX_EXPR_SIZE];
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

// Push character
void pushChar(CharStack *stack, char c) {
    if (stack->top < MAX_EXPR_SIZE - 1) {
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

// Check if characters are matching parentheses
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Check if character is an opening bracket
bool isOpeningBracket(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Check if character is a closing bracket
bool isClosingBracket(char c) {
    return c == ')' || c == '}' || c == ']';
}

// Main function to check parentheses matching
bool checkParentheses(char *expression) {
    CharStack stack;
    initCharStack(&stack);
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        
        if (isOpeningBracket(current)) {
            // Push opening brackets onto stack
            pushChar(&stack, current);
            printf("Pushed '%c' at position %d\n", current, i);
        }
        else if (isClosingBracket(current)) {
            // Check if stack is empty (no opening bracket to match)
            if (isCharStackEmpty(&stack)) {
                printf("Error: Unmatched closing bracket '%c' at position %d\n", current, i);
                return false;
            }
            
            char top = popChar(&stack);
            
            // Check if the popped bracket matches the current closing bracket
            if (!isMatchingPair(top, current)) {
                printf("Error: Mismatched brackets '%c' and '%c' at position %d\n", 
                       top, current, i);
                return false;
            }
            
            printf("Matched '%c' with '%c'\n", top, current);
        }
        // Ignore other characters
    }
    
    // Check if any unmatched opening brackets remain
    if (!isCharStackEmpty(&stack)) {
        printf("Error: Unmatched opening bracket(s) remain\n");
        return false;
    }
    
    return true;
}

// Enhanced function that also identifies the position of error
typedef struct {
    bool isValid;
    int errorPosition;
    char errorType;
} ValidationResult;

ValidationResult checkParenthesesEnhanced(char *expression) {
    CharStack stack;
    initCharStack(&stack);
    ValidationResult result = {true, -1, '\0'};
    
    for (int i = 0; expression[i] != '\0'; i++) {
        char current = expression[i];
        
        if (isOpeningBracket(current)) {
            pushChar(&stack, current);
        }
        else if (isClosingBracket(current)) {
            if (isCharStackEmpty(&stack)) {
                result.isValid = false;
                result.errorPosition = i;
                result.errorType = 'U'; // Unmatched closing
                return result;
            }
            
            char top = popChar(&stack);
            
            if (!isMatchingPair(top, current)) {
                result.isValid = false;
                result.errorPosition = i;
                result.errorType = 'M'; // Mismatched
                return result;
            }
        }
    }
    
    if (!isCharStackEmpty(&stack)) {
        result.isValid = false;
        result.errorPosition = strlen(expression);
        result.errorType = 'O'; // Unmatched opening
    }
    
    return result;
}

int main() {
    // Test expressions
    char *expressions[] = {
        "(a + b) * (c - d)",
        "{[()]}",
        "{[(])}",
        "((a + b) * c",
        "a + b) * c",
        "({[()]})",
        NULL
    };
    
    printf("--- Parentheses Matching Checker ---\n\n");
    
    for (int i = 0; expressions[i] != NULL; i++) {
        printf("Expression: %s\n", expressions[i]);
        printf("Result: ");
        
        if (checkParentheses(expressions[i])) {
            printf("✓ All parentheses are properly matched!\n");
        } else {
            printf("✗ Parentheses are not properly matched!\n");
        }
        
        // Enhanced check with error position
        ValidationResult enhanced = checkParenthesesEnhanced(expressions[i]);
        if (!enhanced.isValid) {
            printf("Enhanced check - ");
            switch(enhanced.errorType) {
                case 'U':
                    printf("Unmatched closing bracket at position %d\n", 
                           enhanced.errorPosition);
                    break;
                case 'M':
                    printf("Mismatched brackets at position %d\n", 
                           enhanced.errorPosition);
                    break;
                case 'O':
                    printf("Unmatched opening bracket(s) at the end\n");
                    break;
            }
        }
        
        printf("\n" + std::string(50, '-') + "\n\n");
    }
    
    return 0;
}