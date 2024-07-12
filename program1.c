/*
Design and implement a program to sort a given set of n integer elements using selection sort
method and compute its time complexity. Run the program for varied values of n>5000 and
record the time taken to sort. Plot a graph of the time taken versus n. The elements can be
read from a file or can be generated using the random number generator.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    // Traverse through all the elements
    for(i=0; i<n-2; i++) {
        // Find the minimum element in unsorted array
        minIndex = i;
        for(j=i+1; j<n; j++) {
            if(arr[j] < arr[minIndex])
            minIndex = j;
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for(i=0; i<size; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

int main() {
    int arr[10000], n, i;
    double time_taken;
    clock_t start, end;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
        arr[i] = rand()%10000;
    printf("\nElements of array\n");
    printArray(arr, n);
    start = clock();
    selectionSort(arr, n);
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC*1000;
    printf("\nElements of array after sorting: \n");
    printArray(arr, n);
    printf("\nTime taken to sort elements = %lf\n", time_taken);
    return 0;
}

/* output:
Enter the number of elements: 
6000

Elements of array
(array elements)
Time taken to sort elements = 41.000000
*/