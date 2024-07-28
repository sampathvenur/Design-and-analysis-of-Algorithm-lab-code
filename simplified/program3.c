#include <stdio.h>

int main() {
    int n, max_qty, m, i, j;
    float sum = 0, max_ratio;
    int weights[20], values[20];

    // Input number of items and their weights and values
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and values of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    // Input maximum volume of knapsack
    printf("Enter maximum volume of knapsack: ");
    scanf("%d", &max_qty);
    m = max_qty;

    while (m > 0) {
        max_ratio = 0;
        j = -1;

        // Find item with highest value-to-weight ratio
        for (i = 0; i < n; i++) {
            if (weights[i] > 0 && (float)values[i] / weights[i] > max_ratio) {
                max_ratio = (float)values[i] / weights[i];
                j = i;
            }
        }

        if (j == -1) break; // No more items to consider

        // Add item to knapsack
        if (weights[j] > m) {
            printf("Quantity of item %d added is %d\n", j + 1, m);
            sum += m * max_ratio;
            break;
        } else {
            printf("Quantity of item %d added is %d\n", j + 1, weights[j]);
            m -= weights[j];
            sum += values[j];
            weights[j] = 0; // Mark item as used
        }
    }

    // Output total profit
    printf("The total profit is %.2f\n", sum);
    return 0;
}
