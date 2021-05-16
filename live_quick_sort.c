#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int n=100000;
int* a=NULL;
void qs(int a[n],int low,int high);
int partition(int a[n],int low,int high);
unsigned long long int count=0;


clock_t start,end;

int main()
{
  
  for(int z=1;z<20;z++)
  {
    a = calloc(n, sizeof(int));
  /*printf("enter the no. of elements");
 scanf("%d",&n);
 printf("enter the elements");*/
    for(int i=0;i<n;i++)
    {
	    a[i]=rand();
    }
  //scanf("%d",&a[i]);
 //invoke the quick sort
    start=clock();
    qs(a,0,n-1);
    end=clock();
    printf("\n");
    printf("%llu N",n);
    printf("\n");
  
    printf("%llu count",count);
    printf("\n");
    printf("%Lf time",((double)(end-start))/CLOCKS_PER_SEC);
 printf("sorted set is:\n");
 for(int i=0;i<n;i++){
 printf("%d ",a[i]);}
    n=n+50000;
  }
}

void qs(int a[n],int low,int high)
{ int j;
  if(low<high)
    {
     j=partition(a,low,high);
     qs(a,low,j-1);
     qs(a,j+1,high);
    }
}
int partition(int a[n],int low,int high)
{
  int pivot=a[low];
  int i=low+1;
  int j=high;int temp;
  while(i<=j)//i & j don't cross over
   {
	   count++;
    while(i<=high && a[i]<=pivot)
	{
		i++;
		count++;
	}
    while(j>low && a[j]>=pivot) 
	{
		j--;
		count++;
	}
    if(i<j)
     {
       temp=a[i];
       a[i]=a[j];
       a[j]=temp;
      }
  //printf("%d %d test",i,j);
  //getchar();
    }
//printf("%d j=",j);
 //getchar();
   if(j!=low)
    {
     a[low]=a[j];
     a[j]=pivot;
     }
   return j;
 }
  
    
    
     
  