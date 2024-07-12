// Design and implement a Program to find the transitive closure using Warshal's algorithm.

#include<stdio.h>
void warshall(int a[10][10],int);
int main()
{
	int i,j,n,a[10][10];
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{	
			printf("(%d,%d):",i,j);
			scanf("%d",&a[i][j]);
		}
		warshall(a,n);
		printf("All pair distance matrix\n");
		for(i=1;i<=n;i++)
		{	
			for(j=1;j<=n;j++)
				printf("%d\t",a[i][j]);
				printf("\n");
		}
		return 0;
}
void warshall(int a[10][10],int n)
{
	int i,j,k;for(k=1;k<=n;k++)
	for(j=1;j<=n;j++)
		for(i=1;i<=n;i++)
			a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
}
/*output: 
Enter the number of vertices
4
Enter the adjacency matrix
(1,1):0
(1,2):1
(1,3):0
(1,4):0
(2,1):0
(2,2):0
(2,3):0
(2,4):1
(3,1):0
(3,2):0
(3,3):0
(3,4):0
(4,1):1
(4,2):0
(4,3):1
(4,4):0
All pair distance matrix
1       1       1       1
1       1       1       1
0       0       0       0
1       1       1       1 */