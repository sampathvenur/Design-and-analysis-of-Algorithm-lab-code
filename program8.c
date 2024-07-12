// Design an application for drilling an optimal printed circuit board. To drill two holes of different diameters consecutively, the head of the machine has to move to a toolbox and change the drilling equipment. This is quite time consuming. Thus, it is clear that one has to choose some diameter, drill all holes of the same diameter, change the drill, drill the holes of the next diameter, etc. Thus, this drilling problem has to minimize the travel time for the machine head. Find the optimal time to drill the circuit board.

#include<stdio.h>
int a[10][10],visited[10],n,cost=0;
int least(int c);
void mincost(int city)
{
	int i,ncity;
	visited[city]=1;
	printf("%d-->",city);
	ncity=least(city);
	if(ncity==999)
	{
		ncity=1;
		printf("%d",ncity);
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=1;i<=n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
		if(a[c][i]<min)
		{
			min=a[i][1]+a[c][i];
			kmin=a[c][i];
			nc=i;
		}
	}
	if(min!=999)
	cost+=kmin;
	return nc;
}
void main()
{
	int i,j;
	printf("enter no. of cities:\n");
	scanf("%d",&n);
	printf("enter the cost matrix\n");
	for(i=1;i<=n;i++)
	{
		printf("enter elements of row:%d\n",i );
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		visited[i]=0;
	}
	printf("the cost list is \n\n");
	for(i=1;i<=n;i++)
	{
		printf("\n\n");
		for(j=1;j<=n;j++)
			printf("\t%d",a[i][j]);
	}
	printf("\n\n the path is :\n\n");
	mincost(1);
	printf("\n\n minimum cost:");
	printf("%d",cost);
}