// Develop an optimal route for a scenario where a person wants to buy a ticket to a baseball game. Along the way from house to reaching the destination, the person using it is a toll road, and has to pay a certain  amount of money.

#include<stdio.h>
int n,cost[10][10],dist[10];
void readmatrix(int);
int min(int,int);
void shortest_path(int,int);
int main()
{
	int i,s;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost adjecency matrix(999 for infinite)\n");
	readmatrix(n);
	printf("Enter the source vertex\n");
	scanf("%d",&s);
	shortest_path(n,s);
	for(i=1;i<=n;i++)
		printf("The shortest path between vertex %d to %d is %d\n",s,i,dist[i]);
	return 0;
}
int min(int a,int b)
{
	return a>b?b:a;
}
void readmatrix(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			printf("(%d,%d):",i,j);
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
}
void shortest_path(int n,int s)
{
	int vis[10],c,u,i,k;
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
		dist[i]=cost[s][i];
	}
	dist[s]=0;
	vis[s]=1;
	for(k=1;k<=n;k++)
	{
		c=999;
		for(i=1;i<=n;i++)
			if(vis[i]==0)
			{
				if(dist[i]<=c)
				{
					c=dist[i];
					u=i;
				}
			}
			vis[u]=1;for(i=1;i<=n;i++)
			dist[i]=min(dist[i],dist[u]+cost[u][i]);
	}
}

/*output: 
Enter the number of vertices
5
Enter the cost adjecency matrix(999 for infinite)
(1,1):999
(1,2):1
(1,3):2
(1,4):999
(1,5):999
(2,1):1
(2,2):999
(2,3):3
(2,4):4
(2,5):999
(3,1):2
(3,2):3
(3,3):999
(3,4):5
(3,5):6
(4,1):999
(4,2):4
(4,3):5
(4,4):999
(4,5):6
(5,1):999
(5,2):999
(5,3):6
(5,4):6
(5,5):999
Enter the source vertex
1
The shortest path between vertex 1 to 1 is 0
The shortest path between vertex 1 to 2 is 1
The shortest path between vertex 1 to 3 is 2
The shortest path between vertex 1 to 4 is 5
The shortest path between vertex 1 to 5 is 8 */