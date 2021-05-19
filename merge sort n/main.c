#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

clock_t start,end;
unsigned long long int n=100000;
unsigned long long int count1=0;
int* arr=NULL;


int main()
{
        FILE *f;
        FILE *g;
        f = fopen("merge.csv", "w");
        g = fopen("merge_time.csv","w");

        for(int z=1;z<20;z++)
        {
                arr = calloc (n, sizeof(int));
                unsigned long long int arr_size = n;
 
                for(int i=0;i<n;i++)
                {
  
                        arr[i]=rand();
                }

                start=clock();
                count1 = mergeSort(arr, 0, arr_size - 1);
                end=clock();
  
                printf("\n");
                
                printf("%llu N",n);
                
                fprintf(f, "%llu,", n);

                fprintf(g, "%llu,", n);
                
                printf("\n");
  
                printf("%llu count",count1);

                fprintf(f, "%llu \n", count1);
                
                printf("\n");
                
                printf("%Lf time",((double)(end-start))/CLOCKS_PER_SEC);
                
                fprintf(g, "%Lf \n", ((double)(end-start))/CLOCKS_PER_SEC);

                n=n+50000;
                
        }

        fclose(f);
        fclose(g);
        return 0;
}