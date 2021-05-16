#include <stdio.h>
#include <stdlib.h>
#include<time.h>
clock_t start,end;
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]

unsigned long long int count=0;
unsigned long long int n=100000;

int* arr=NULL;

int* L=NULL;
int* R=NULL;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    L = calloc(n1, sizeof(int));
    R = calloc(n2, sizeof(int));
 
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
      count++;
            arr[k] = L[i];
            i++;
        }
        else {
      count++;
            arr[k] = R[j];
            j++;
        }
        k++;count++;
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
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

// /* UTILITY FUNCTIONS */
// /* Function to print an array */
// void printArray(int A[], int size)
// {
//     int i;
//     for (i = 0; i < size; i++)
//         printf("%d ", A[i]);
//     printf("\n");
// }

/* Driver code */
int main()
{
  for(int z=1;z<20;z++)
  {
    arr = calloc (n, sizeof(int));
    unsigned long long int arr_size = n;
 
         for(int i=0;i<n;i++){
  //scanf("%d",&a[i]);
 arr[i]=rand();
         }

  start=clock();
    mergeSort(arr, 0, arr_size - 1);
  end=clock();
    //printf("\n Array is sorted \n");
  /*for(int i=0;i<n;i++)
    printf("%d ",arr[i]);*/
  printf("\n");
 printf("%llu N",n);
 printf("\n");
  
 printf("%llu count",count);
 printf("\n");
 printf("%Lf time",((double)(end-start))/CLOCKS_PER_SEC);
 n=n+50000;
  
  }
  return 0;
}