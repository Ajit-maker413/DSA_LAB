#include <stdio.h>
#include <stdlib.h>

// Stack structure for factorial calculation
typedef struct {
    int *items;
    int top;
    int capacity;
} FactStack;

// Initialize stack
FactStack* createStack(int capacity) {
    FactStack *stack = (FactStack*)malloc(sizeof(FactStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Push operation
void pushFact(FactStack *stack, int value) {
    stack->items[++stack->top] = value;
}

// Pop operation
int popFact(FactStack *stack) {
    return stack->items[stack->top--];
}

// Check if stack is empty
int isFactStackEmpty(FactStack *stack) {
    return stack->top == -1;
}

// Factorial using stack (simulating recursion)
int factorialUsingStack(int n) {
    if (n < 0) {
        printf("Factorial is not defined for negative numbers\n");
        return -1;
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }
    
    FactStack *stack = createStack(n);
    int result = 1;
    
    // Push all numbers from n down to 2
    for (int i = n; i > 1; i--) {
        pushFact(stack, i);
    }
    
    // Pop and multiply
    while (!isFactStackEmpty(stack)) {
        result *= popFact(stack);
    }
    
    free(stack->items);
    free(stack);
    
    return result;
}

// Recursive factorial for comparison
int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

// Iterative factorial
int factorialIterative(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num = 5;
    
    printf("Factorial of %d:\n", num);
    printf("Using stack: %d\n", factorialUsingStack(num));
    printf("Using recursion: %d\n", factorialRecursive(num));
    printf("Using iteration: %d\n", factorialIterative(num));
    
    // Test with different numbers
    printf("\n--- Factorial Table ---\n");
    for (int i = 0; i <= 10; i++) {
        printf("%d! = %d\n", i, factorialUsingStack(i));
    }
    
    return 0;
}