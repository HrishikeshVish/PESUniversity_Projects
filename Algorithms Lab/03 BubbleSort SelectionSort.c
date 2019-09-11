#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


typedef struct arr
{
	  int id;
	 int value;
}record;

  int BubbleSort(record *r1, int n, int kpass);
  int SelectionSort(record*r1,  int n,  int kpass);

int main()
{
	 int n,kpass;
	scanf("%d",&n);
	record*r1=(record*)malloc(sizeof(record)*n);
	for( int i=0;i<n;i++)
	{
		scanf("%d %d",&(r1[i].id),&(r1[i].value));
	}
	
	scanf("%d",&kpass);
	
	struct timespec start,end,start1,end1;
    	clock_gettime(CLOCK_REALTIME, &start);
    	
	BubbleSort(r1,n,kpass);
	BubbleSort(r1,n,n);
	
	clock_gettime(CLOCK_REALTIME, &end);
	clock_gettime(CLOCK_REALTIME, &start1);
	
	SelectionSort(r1,n,kpass);
	SelectionSort(r1,n,n);
	
	
	clock_gettime(CLOCK_REALTIME, &end1);
	int timeinseconds= end.tv_sec - start.tv_sec;
	int timeinseconds1= end1.tv_sec - start1.tv_sec;
	double timeinnseconds= end.tv_nsec - start.tv_nsec;
	timeinnseconds = timeinseconds + (timeinnseconds * pow(10,-9));
	double timeinnseconds1= end1.tv_nsec - start1.tv_nsec;
	timeinnseconds1 = timeinseconds1 + (timeinnseconds1 * pow(10,-9));
	
	
	printf("%f\n",timeinnseconds);
	printf("%f\n",timeinnseconds1);
	

}


  int BubbleSort(record *r1,  int n,  int k)
{
	if(k<=n)
	{
		record*temp=(record*)malloc(sizeof(record)*1);
		for(  int i=0;i<k;i++)
		{
			for(  int j=0;j<n-i-1;j++)
			{
				if(r1[j].value > r1[j+1].value)
				{
					*temp=r1[j];
					r1[j]=r1[j+1];
					r1[j+1]=*temp;
				}
			}
		}
		for(  int i=0;i<n;i++)
		{
			printf("%d %d\n",r1[i].id,r1[i].value);
		}
	}
	else
	{
		for(  int i=0;i<n;i++)
		{
			printf("%d %d\n",r1[i].id,r1[i].value);
		}
	}
		
}


 int SelectionSort(record*a, int n,  int k1)
{
	if(k1<=n)
	{	
		record*min=(record*)malloc(sizeof(record)*1);
			
		  int k;
		for(  int i=0;i<k1;i++)
		{     
			*min=a[i];
			for(  int j=i;j<n;j++)
			{
		
				if(min->value > a[j].value)
				{
					*min=a[j];
					k=j;
				}
			}
			if(a[i].value > min->value)
			{
				a[k]=a[i];
				a[i]=*min;
				
			}
		}
		for(  int i=0;i<n;i++)
		{
			printf("%d %d\n",a[i].id,a[i].value);
		}
	}
	else
	{
		for(  int i=0;i<n;i++)
		{
			printf("%d %d\n",a[i].id,a[i].value);
		}
	}
		
	
	
}
	
	
