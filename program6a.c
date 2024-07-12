// Design and implement a Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm.

#include <stdio.h>
#include<omp.h>
#include<time.h>
int min(int,int);
void floyd(int [][10],int);
int main()
{
	int a[10][10],n,i,j;
	clock_t start,end;
	printf("\nEnter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the cost matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	start=clock();
	floyd(a,n);
	end=clock();
	printf("Shortest path matrix is \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d\t",a[i][j]);
			printf("\n");
	}
	printf("Time taken is %lf\n",(double)(end-start));
	return 0;
}
int min(int a,int b)
{
	return (a<b?a:b);
}
void floyd(int w[10][10],int n)
{
	int i,j,k;
	#pragma omp parallel for private(i,j,k) shared(w)
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
}

/*output: 
Enter the number of vertices
4
Enter the cost matrix
0 2 3 6
2 0 7 999
3 7 0 1
6 999 1 0
Shortest path matrix is
0       2       3       4
2       0       5       6
3       5       0       1
4       6       1       0
Time taken is 4.000000*/