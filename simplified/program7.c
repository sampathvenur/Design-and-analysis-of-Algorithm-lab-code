// The owner of a gourmet coffee shop wishes to mix a 10-pound bag of coffee using various types of coffee beans in such a way to produce the coffee blend at the maximum cost. The weights of the objects in the problem correspond to the quantity in pounds available of each type of coffee bean. The value of each quantity of coffee  beans is the total cost of that quantity in rupees. Apply the Knapsack algorithm to maximize the profit.

#include <stdio.h>
int v[20][20], w[20], p[20], n, max;

int max_value(int a, int b) { return (a > b) ? a : b; }

void knapsack() {
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= max; j++)
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max_value(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
    printf("Max profit: %d\nSubset: {", v[n][max]);
    for (i = n, j = max; i > 0; i--)
        if (v[i][j] != v[i - 1][j]) {
            printf("item%d:1 ", i);
            j -= w[i];
        } else
            printf("item%d:0 ", i);
    printf("}\n");
}

int main() {
    int i;
    printf("Enter number of items: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter weight and profit of item %d: ", i);
        scanf("%d %d", &w[i], &p[i]);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &max);
    knapsack();
    return 0;
}

/*
Output:
Enter number of items: 4
Enter weight and profit of item 1: 4 40
Enter weight and profit of item 2: 7 42
Enter weight and profit of item 3: 5 25
Enter weight and profit of item 4: 3 12
Enter knapsack capacity: 10
Table:
0	0	0	0	0	0	0	0	0	0	0
0	0	0	0	40	40	40	40	40	40	40
0	0	0	0	40	40	40	42	42	42	42
0	0	0	0	40	40	40	42	42	65	65
0	0	0	12	40	40	40	52	52	65	65
Max profit: 65
Subset: {item4:0 item3:1 item2:0 item1:1 }
*/