#include <stdio.h>

#include <time.h>

#define INF 999  // Define a constant for infinite distance

// Function declarations
int min(int, int);
void floydWarshall(int[][10], int);

int main() {
    int costMatrix[10][10], numVertices, i, j;
    clock_t start, end;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input cost adjacency matrix
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Measure time taken by Floyd-Warshall algorithm
    start = clock();
    floydWarshall(costMatrix, numVertices);
    end = clock();

    // Output the shortest path matrix
    printf("Shortest path matrix is:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d\t", costMatrix[i][j]);
        }
        printf("\n");
    }

    // Output the time taken
    printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b ? a : b);
}

// Function to perform Floyd-Warshall algorithm
void floydWarshall(int dist[10][10], int n) {
    int i, j, k;

    // Parallelize the outer loop with OpenMP

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
