#include <stdio.h>

int a, b, u, i, j, ne = 1, n, v;
int visited[10], min, mincost = 0, cost[10][10];

int main() {
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the graph data in matrix form (use 0 for no connection)\n");

    // Input graph cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("(%d, %d): ", i + 1, j + 1);  // Adjusted for 1-based display
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999;  // Using 999 to represent infinity
            }
        }
    }

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;  // Initialize all vertices as not visited
    }

    visited[0] = 1;  // Start with the first vertex
    printf("The edges of the spanning tree are:\n");

    // Main loop to find the minimum spanning tree
    while (ne < n) {
        min = 999;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (!visited[v]) {
            printf("%d: edge(%d, %d) = %d\n", ne++, a + 1, b + 1, min);
            mincost += min;
            visited[v] = 1;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost is %d\n", mincost);
    return 0;
}
