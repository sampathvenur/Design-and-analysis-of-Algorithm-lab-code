// Design and implement a Program to solve discrete Knapsack and continuous Knapsack problems using greedy approximation method.

#include <stdio.h>
int main() 
{
	int i, j = 0, max_qty, m, n; float sum = 0, max;
	int array[2][20];
 	printf("Enter no of items: "); 
	scanf("%d",&n);
	printf("Enter the weights of each items: ");
 	for (i = 0; i < n; i++) 
 	{
		scanf("%d", &array[0][i]);
	}
	printf("Enter the values of each items: ");
 	for (i = 0; i < n; i++) 
	{
		scanf("%d", &array[1][i]);
	}
	printf("Enter maximum volume of knapsack: "); 
	scanf("%d", &max_qty);
	m = max_qty; 
	while (m > 0) 
	{ 
		max = 0;
		for (i = 0; i < n; i++) 
		{
			if (((float)array[1][i]) / ((float)array[0][i]) > max) 
			{
				max = ((float)array[1][i]) / ((float)array[0][i]); 
				j = i;
			}
		}
		if (array[0][j] > m) 
		{
			printf("Quantity of item number: %d added is %d\n", (j + 1), m); 
			sum += m * max;
			m = -1;
		} 
		else 
		{
			printf("Quantity of item number: %d added is %d\n", (j + 1), array[0][j]);
			m -= array[0][j];
			sum += (float)array[1][j]; array[1][j] = 0;
		}
	}
	printf("The total profit is %.2f\n", sum); 
	return 0;
}

/*output: 
Enter no of items: 4
Enter the weights of each items: 2 1 3 2
Enter the values of each items: 12 10 20 15
Enter maximum volume of knapsack: 5
Quantity of item number: 2 added is 1
Quantity of item number: 4 added is 2
Quantity of item number: 3 added is 2
The total profit is 38.33 */