#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 100000

void merge(long long int arr[], int l, int m, int r);
void mergeSort(long long int arr[], int l, int r);

int swaps = 0;

void mergeSort(long long int arr[], int l, int r)
{
    // As long as left < right
    if (l < r)
    {
        // Find middle
        int m = (l + r) / 2;

        // First half
        mergeSort(arr, l, m);
        // Second Half
        mergeSort(arr, m + 1, r);

        // Merging
        merge(arr, l, m, r); 
    }
}
 

void merge(long long int arr[], int l, int m, int r)
{
    // Length of first array
    int n1 = m - l + 1;
    // Length of second array
    int n2 = r - m;
    // Number of swaps
    swaps = 0;

    // Temp arrays
    int a1[n1], a2[n2];
   // int *a1,*a2;
  //a1=(int *)malloc(n1);
  //a2=(int *)malloc(n2);

    // Copy elements to temp arrays
    for (int i = 0; i < n1; i ++)
    {
        a1[i] = arr[l + i];
      // *(a1+i)=arr[l+i];
    }
    for (int i = 0; i < n2; i ++)
    {
        a2[i] = arr[m + i + 1];
        // *(a2+i)=arr[m+l+i];
    }

    int i = 0, j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        swaps ++;
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i ++;
        }
        else
        {
            arr[k] = a2[j];
            j ++;
        }
        k ++;
    }

    // Copying remaining elements
    while (j < n2)
    {
        arr[k] = a2[j];
        j ++;
        k ++;
    }
    while (i < n1)
    {
        arr[k] = a1[i];
        i ++;
        k ++;
    }
}

int main(void)
{
     // Time variables
    time_t start, end;

    // File Pointer
    FILE* fp;

    fp = fopen("test.csv", "w");

    for (int k = LENGTH; k < LENGTH * 10; k += LENGTH / 2)
    {
        // Generate array*/
        long long int* arr = malloc(sizeof(long long int) * k);
        
        for (int i = 0; i < k; i ++)
        {
            arr[i] = rand();
        }

        /*printf("Old array: ");
        for (int i = 0; i < k; i ++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n\n");*/

        start = time(0);

        mergeSort(arr, 0, k);

        /*printf("New array: ");
        for (int i = 0; i < k; i ++)
        {
            printf("%d ", arr[i]);
        }*/

        end = time(0);

        double diff = difftime(end, start);

        fprintf(fp, "%d, %d, %lf\n", k, swaps, diff);

        free(arr);
    }

   fclose(fp);
}



