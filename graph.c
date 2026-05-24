#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];  // adjacency matrix
int n;                // number of vertices

// create graph
void createGraph() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

// display graph
void displayGraph() {
    int i, j;

    printf("Adjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    createGraph();
    displayGraph();
    return 0;
}