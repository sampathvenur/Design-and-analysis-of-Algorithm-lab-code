// Design an application for drilling an optimal printed circuit board. To drill two holes of different diameters consecutively, the head of the machine has to move to a toolbox and change the drilling equipment. This is quite time consuming. Thus, it is clear that one has to choose some diameter, drill all holes of the same diameter, change the drill, drill the holes of the next diameter, etc. Thus, this drilling problem has to minimize the travel time for the machine head. Find the optimal time to drill the circuit board.

#include <stdio.h>
int a[10][10], vis[10], n, cost = 0;

void mincost(int city) {
    int i, j, nc = 999, min = 999, kmin;
    vis[city] = 1;
    printf("%d-->", city);
    for (i = 1; i <= n; i++)
        if (a[city][i] && !vis[i] && a[city][i] < min) {
            min = a[i][1] + a[city][i];
            kmin = a[city][i];
            nc = i;
        }
    if (min != 999) cost += kmin;
    if (nc == 999) {
        cost += a[city][1];
        printf("1");
        return;
    }
    mincost(nc);
}

int main() {
    int i, j;
    printf("enter no. of cities:\n");
    scanf("%d", &n);
    printf("enter the cost matrix\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
        vis[i] = 0;
    }
    printf("the path is:\n");
    mincost(1);
    printf("\nminimum cost: %d", cost);
    return 0;
}

/*
Output:
enter no. of cities:
4
enter the cost matrix
0 16 11 16
8 0 13 16
4 7 0 9
5 12 2 0
the path is:
1-->3-->4-->2-->1
minimum cost: 40
*/