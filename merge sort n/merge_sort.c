#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

unsigned long long int count=0;

int* L=NULL;
int* R=NULL;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    L = calloc(n1, sizeof(int));
    R = calloc(n2, sizeof(int));
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
   
    i = 0; 
    j = 0; 
    k = l; 
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
 
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

unsigned long long int mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
    return count;
}


/* Driver code */
