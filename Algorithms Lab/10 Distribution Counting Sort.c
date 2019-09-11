#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void DistributionCountingSort(int*, int, int, int, int*);
void mergeSort(int arr[], int l, int r) ;
//void MergeSort(int *A, int n);
void merge(int arr[], int l, int m, int r);
int main(){

	int n;
	scanf("%d", &n);
	//printf("N taken\n");
	int *s = (int*)malloc(sizeof(int)*n);
	printf("S Seg FAULT\n");
	//int a1[n], a2[n];
	int *a1 = (int*)malloc(sizeof(int)*n);
	int *a2 = (int *)malloc(sizeof(int)*n);
	//printf("a1 and a2 created\n");
	int l = 0, u = 0;
	for(int i = 0; i<n; i++){
		
		scanf("%d", &a1[i]);
		a2[i] = a1[i];
		
		if(i == 0){
			
			l = a1[i]; u = a1[i];}
		else{
			if(a1[i]<= l)
				{l = a1[i];}
		if(a1[i]>=u)
			{u = a1[i];}
		}
	}
//printf("After for\n");
struct timespec t;
double start = t.tv_sec;
//printf("Before calling\n");
DistributionCountingSort(a1, n, l, u, s);
double end = t.tv_sec;
double startm = t.tv_sec;
//mergeSort(a2,0,n);
double endm = t.tv_sec;
for(int i = 0; i<n; i++){
if(s[i] != 0){
printf("%d\n", s[i]);
}
}
printf("%lf sec\n%lf sec\n", end-start, endm-startm);
}

void DistributionCountingSort(int *A,int n,int l,int u,int *S){
int *D;
//printf("inside Distributioncountingsort\n");

D = (int*)malloc(sizeof(int)*(u-l)+u);
//printf("%d\n", u);
//printf("%d\n", l);
for(int j = 0; j<u; j++){

D[j] = 0;
}
//printf("Init D\n");
int k;
for(int i = 0; i<n; i++){
//printf("Inside for\n");	
//printf("A[i] = %d\n", A[i]);
k = A[i] -l;
//printf("k = %d\n", k);
D[k] = D[k] + 1;

//printf("After copy\n");
}

//printf("Copy D\n");
for(int j = 1; j<u; j++){
D[j] = D[j] + D[j-1];
}
//printf("Second Copy \n");
int j;
for(int i = n-1; i>=0; i--){
	j = A[i] - l;
	S[D[j]-1] = A[i];
	D[j] = D[j] -1;

}
//printf("Assign a to d\n");
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 





