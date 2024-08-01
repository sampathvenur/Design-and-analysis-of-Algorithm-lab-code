// The owner of a gourmet coffee shop wishes to mix a 10-pound bag of coffee using various types of coffee beans in such a way to produce the coffee blend at the maximum cost. The weights of the objects in the problem correspond to the quantity in pounds available of each type of coffee bean. The value of each quantity of coffee  beans is the total cost of that quantity in rupees. Apply the Knapsack algorithm to maximize the profit.

#include<stdio.h>
 int v[20][20];
 int max_value(int,int);
 int main()
{
	int i,j,p[20],w[20],n,max;
	printf("\nEnter the number of items\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the weight and profit of the item %d:",i);
		scanf("%d %d",&w[i],&p[i]);
	}
	printf("\nEnter the capacity of knapsack\n");
	scanf("%d",&max);
	for(i=0;i<=n;i++)
		v[i][0]=0;
	for(i=0;i<=max;i++)
		v[0][i]=0;
	for(i=1;i<=max;i++)
		for(j=1;j<=max;j++)
		{
			if(w[i]>j)
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max_value(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
		printf("The table is \n");
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=max;j++)
				printf("%d\t",v[i][j]);
			printf("\n");
		}
		printf("The max profit is %d",v[n][max]);
		printf("most profitable subset is :{");
		j=max;
		for(i=n;i>=1;i--)
			if(v[i][j]!=v[i-1][j])
			{
				printf("item%d:1\t",i);
				j=j-w[i];
			}
			else
				printf("item%d:0\t",i);
		printf("}\n");
		return 0;
}
int max_value(int a,int b)
{
	return (a>b?a:b);
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