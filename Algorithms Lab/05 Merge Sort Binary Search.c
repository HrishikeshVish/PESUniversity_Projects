#include<stdio.h>
#include<stdlib.h>


//Header file for session5_mergesort_binsearch.c

typedef struct Data {
	int id;
	int value;
} data;

//Merge Sort
//Use Merge Sort algorithm to sort the array of length with respect to their values.
void MergeSort(data* a, int l,int r);
void merge(data *a,int l,int m,int r);
void printarray(data*a,int n);

//Binary Search
//Returns the index of one of the records of A which matches key_value with 'value'
int BinarySearch(data * a, int l,int r, int key);

int main()
{
	int n,key;
	scanf("%d",&n);
	data*a=(data*)malloc(sizeof(data)*n);	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&(a[i].id),&(a[i].value));
	}
	MergeSort(a,0,n-1);
	printarray(a,n);
	scanf("%d",&key);
	
	int ans=BinarySearch(a,0,n,key);
	/*if(ans==1)
		puts("FOUND");
	else
		puts("NOT FOUND");*/

}



void MergeSort(data* a, int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		merge(a,l,m,r);
		//puts("eefhj");
	}
	//printarray(a,r+1);

}

void merge(data *a,int l1,int m,int r1)
{
	int i, j, k; 
    int n1 = m - l1 + 1; 
    int n2 =  r1- m; 
	//data*temp=(data*)malloc(sizeof(data)*1);
  
    /* create temp arrays */
  //  int L[n1], R[n2]; 
	data*l=(data*)malloc(sizeof(data)*n1);
	data*r=(data*)malloc(sizeof(data)*n2);
	
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        l[i] = a[l1 + i]; 
    for (j = 0; j < n2; j++) 
        r[j] = a[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l1; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (l[i].value <= r[j].value) 
        { 
            a[k] = l[i];
            i++; 
        } 
        else
        { 
            a[k] = r[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        a[k] = l[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        a[k] = r[j]; 
        j++; 
        k++; 
    } 
}
	
void printarray(data*a,int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].id,a[i].value);
	}
}


int BinarySearch(data * a, int l,int r, int key)
{
	//puts("chal raha hai");
	if(r-l<=1)
	{
		//puts("ok");
		return 0;
	}
	else
	{
		int m=(l+r)/2;
		
		
		if(a[m].value == key)
		{
			printf("%d %d %d\n",m,a[m].id,a[m].value);
			return 1;
		}
		else if(a[m].value > key)
		{
			BinarySearch(a,l,m,key);
		}
		else
		{
			BinarySearch(a,m,r,key);
		}
	}
	
		
	
}

	
	






		
	
