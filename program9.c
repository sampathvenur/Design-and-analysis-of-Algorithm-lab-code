// Design and implement for a given chess board having N×N cells, place N queens on the board in such a way that no queen attacks any other queen. If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N Queens. If there is more than one solution of placing the queens, print all of them. If it is not possible to place all N queens in the desired way, then print "Not possible".

#include<stdio.h>
#include<stdlib.h>
int count=0,x[5];
void n_queen(int,int);
int place(int,int);
int main()
{
	int n;
	printf("Enter the number of queens\n");
	scanf("%d",&n);
	n_queen(1,n);
	if(count==0)
		printf("No solutions are found\n");
	else
		printf("Number of solutions found are %d \n",count);
	return 0;
}
int place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
		if((x[j]==i)||((abs(x[j]-i))==(abs(j-k))))
			return 0;
	return 1;
}
void n_queen(int k,int n)
{
	int i,j,p;
	for(i=1;i<=n;i++){
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				count++;
				printf("solution %d\n",count);
				for(j=1;j<=n;j++)
				{
					for(p=1;p<=n;p++)
						if(x[j]==p)
							printf("$\t");
						else
							printf("0\t");
						printf("\n");
				}
				printf("\n");
			}
			else
				n_queen(k+1,n);
		}
	}
}