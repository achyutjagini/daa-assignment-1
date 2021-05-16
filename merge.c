/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
 
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

void merge(int arr[], int l, int m, int r)//merge arr,0,0,1
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)//l=0,r=5
                                       //l=0,r=2
                                       //l=0,r=1
{              
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;//m=0+2.5 = 2.5 becomes 2 
                                //m=0+1=1
                                //m=0+0.5=0.5=0

        printf("\n-----m value----------%d---------------\n",m);

        // Sort first and second halves


        //mergesort arr,0,2
        //mergesort arr,0,1 
        //mergesort arr,0,0-nothing go to function on next line same l,m
        printf("\n----mergesort arr,%d,%d---\n",l,m);
        mergeSort(arr, l, m);
       
        
        //mergesort arr,1,1
        printf("\n----mergesort arr,%d,%d---\n",m+1,r);
        mergeSort(arr, m + 1, r);
        
        //merge arr,0,0,1
        printf("\n----merge arr,%d,%d,%d---\n",l,m,r);
           merge(arr, l, m, r);
     
}
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);//arr_size=6
 
    printf("Given array is \n");
    printArray(arr, arr_size);//prints given array
 
      printf("\n----mergesort arr,0,%d---\n",arr_size-1);
     
      mergeSort(arr, 0, arr_size - 1);//mergesort arr,0,5
    
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
