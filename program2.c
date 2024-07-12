/*
Design and implement a program to sort a given set of n integers demonstrating merge sort method
and compute its time complexitty. Run the program for varied values of n>5000 and record the time
taken to sort. Plot a graph of time taken versus n. The elements can be read from the file or can be 
generated using random number generator.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 10000

void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid+1;
    int k = low;
    int resarray[MAX];
    while(i<=mid && j<=high) {
        if(arr[i] < arr[j]) {
            resarray[k++] = arr[i++];
        }
        else
            resarray[k++] = arr[j++];
    }

    while(i <= mid)
        resarray[k++] = arr[i++];
    while(j <= high)
        resarray[k++] = arr[j++];
    for(int m=low; m<=high; m++)
        arr[m] = resarray[m];
}

void sort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low+high)/2;
        sort(arr, low, mid);
        sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[MAX];
    int i;
    printf("Enter the array size: ");
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    for(i=0; i<n; i++)
        arr[i] = rand()%10000;
    printf("\n");
    clock_t start = clock();
    sort(arr, 0, n-1);
    clock_t end = clock();
    printf("Sorted array\n");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    double elapsedTime = ((double)(end-start))/CLOCKS_PER_SEC*1000;
    printf("Time taken to sort array is: %lf\n", elapsedTime);
    return 0;
}