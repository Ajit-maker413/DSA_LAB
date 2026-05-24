#include <stdio.h>
#include <stdlib.h>

// Structure to represent a non-zero element
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure for sparse matrix
typedef struct {
    int rows;
    int cols;
    int num_elements;
    Element *elements;
} SparseMatrix;

// Function to create sparse matrix from normal matrix
SparseMatrix* createSparseMatrix(int **matrix, int rows, int cols) {
    int count = 0;
    
    // Count non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    
    // Allocate sparse matrix
    SparseMatrix *sparse = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sparse->rows = rows;
    sparse->cols = cols;
    sparse->num_elements = count;
    sparse->elements = (Element*)malloc(count * sizeof(Element));
    
    // Store non-zero elements
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse->elements[index].row = i;
                sparse->elements[index].col = j;
                sparse->elements[index].value = matrix[i][j];
                index++;
            }
        }
    }
    
    return sparse;
}

// Display sparse matrix
void displaySparseMatrix(SparseMatrix *sparse) {
    printf("\nSparse Matrix Representation (Row, Column, Value):\n");
    printf("Rows: %d, Columns: %d, Non-zero elements: %d\n", 
           sparse->rows, sparse->cols, sparse->num_elements);
    printf("Row\tColumn\tValue\n");
    
    for (int i = 0; i < sparse->num_elements; i++) {
        printf("%d\t%d\t%d\n", 
               sparse->elements[i].row, 
               sparse->elements[i].col, 
               sparse->elements[i].value);
    }
}

int main() {
    // Example matrix
    int **matrix = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        matrix[i] = (int*)malloc(5 * sizeof(int));
    }
    
    // Initialize matrix with zeros and some non-zero values
    int temp[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
    
    // Create and display sparse matrix
    SparseMatrix *sparse = createSparseMatrix(matrix, 4, 5);
    displaySparseMatrix(sparse);
    
    // Free memory
    for (int i = 0; i < 4; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(sparse->elements);
    free(sparse);
    
    return 0;
}