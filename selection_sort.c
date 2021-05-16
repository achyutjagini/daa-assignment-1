#include<stdio.h>
#include<stdlib.h>
#include<time.h>
unsigned long long int n=100000;
//int a[n];
int* a=NULL;
int main()
{
	clock_t start,end;
	double cpu_time_used;
	unsigned long long int count=0;
  a = calloc(n, sizeof(int));
 /*printf("enter the no. of elements");
 scanf("%d",&n);
 printf("enter the elements");*/
 for(int i=0;i<n;i++)
 {
	 a[i]=rand();
 }
 //scanf("%d",&a[i]);
 //sorting
 start=clock();
 for(int i=0;i<n-1;i++)
  {
    int mp=i;
  for(int j=mp+1;j<n;j++)
    if(a[j]<a[mp])
	{
	  count++;
      mp=j;
	}
   if(mp!=i)
    {
     int temp=a[mp];
         a[mp]=a[i];
         a[i]=temp;
    }
  }
  end=clock();
  
//  for(int i=0;i<n;i++)
//   printf("%d ",a[i]);
  
 printf("\n");
  
 printf("%llu",count);
 printf("\n");
 printf("%Lf",((double)(end-start))/CLOCKS_PER_SEC);
 }
    