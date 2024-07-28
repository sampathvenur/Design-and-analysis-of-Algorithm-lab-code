#include <stdio.h>

// Function to perform Warshall's algorithm
void warshall(int adjMatrix[10][10], int numVertices);

int main() {
    int numVertices, i, j;
    int adjMatrix[10][10];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("(%d,%d): ", i + 1, j + 1);
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Compute transitive closure using Warshall's algorithm
    warshall(adjMatrix, numVertices);

    // Output the resulting matrix
    printf("All pair reachability matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d\t", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to perform Warshall's algorithm
void warshall(int adjMatrix[10][10], int numVertices) {
    int i, j, k;

    // Perform the algorithm
    for (k = 0; k < numVertices; k++) {
        for (i = 0; i < numVertices; i++) {
            for (j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = adjMatrix[i][j] || (adjMatrix[i][k] && adjMatrix[k][j]);
            }
        }
    }
}
