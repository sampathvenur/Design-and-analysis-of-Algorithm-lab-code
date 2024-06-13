/*
Design and implement a program to solve discrete knapsack and continuous knapsack problems using
greedy approximation.
*/

#include<stdio.h>
#define MAX 50
int p[MAX], w[MAX], x[MAX];
double maxprofit;
int n, m, i;

void greedyKnapsack(int n, int w[], int p[], int m) {
    double ratio[MAX];

    // Calculate the ratio of profit to weight for each item
    for(i=0; i<n; i++)
        ratio[i] = (double) p[i]/w[i];
    
    // Sort items based on the ratio in non-increasing order
    for(i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(ratio[i] < ratio[j]) {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                
                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;
                
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    int currentweight = 0;
    maxprofit = 0.0;

    // Fill the knapsack with items
    for(i=0; i<n; i++) {
        if(currentweight + w[i] <= m) {
            x[i] = 1;   // Item i is selected
            currentweight += w[i];
            maxprofit += p[i];
        }
        else {
            // Fractional part of itam i is selected
            x[i] = (m-currentweight)/(double)w[i];
            maxprofit += x[i] * p[i];
            break;
        }
    }

    printf("Optimal solution for greedy method: %.1f\n", maxprofit);
    printf("Solution vector for greedy method: ");
    for(i=0; i<n; i++)
        printf("%d\t", x[i]);
    printf("\n");
}

int main() {
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the object's weight: ");
    for(i=0; i<n; i++)
        scanf("%d", &w[i]);
    printf("Enter the object's profit: ");
    for(i=0; i<n; i++)
        scanf("%d", &p[i]);
    printf("Enter the maximum capacity: ");
    scanf("%d", &m);
    greedyKnapsack(n, w, p, m);
    return 0;
}