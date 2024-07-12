#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int arr[], int n) 
{
	int i, j, minIndex, temp;
	// Traverse through all array elements
	for (i = 0; i < n-1; i++) 
	{
		// Find the minimum element in unsorted array
		minIndex = i;
		for (j = i+1; j < n; j++) 
		{
			if (arr[j] < arr[minIndex])
			minIndex = j;
		}
// Swap the found minimum element with the first element
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}
// Function to print an array
void printArray(int arr[], int size) 
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main() 
{
	int arr[10000],n,i;
	double time_taken;
	clock_t start,end;
	printf("Enter the number of elements \n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
		arr[i] = rand()%10000;
	printArray( arr,  n);
	start = clock();
	selectionSort(arr,  n );
	end = clock();
	printArray( arr,  n);
	time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
	printf("time taken to sort elements=%lf",time_taken);
	return 0;
}