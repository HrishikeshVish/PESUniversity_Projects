//Header file for session6_quicksort.c
#include<stdio.h>
#include<time.h>
typedef struct Data {
	int id;
	int value;
} Data;

//Quick Sort
//Use Quick Sort algorithm to sort the array an of records by their id.
void QuickSort(Data* A, int a, int n);

//Hoare Partition
//Partitions the array on a pivot element and returns the index of the 
// pivot element in the partitioned array of records
int Partition(Data * A, int a, int n);

int main(){
	int n;
	scanf("%d", &n);
	Data p[n];
	for(int i = 0;i<n;i++){
		scanf("%d %d", &p[i].id, &p[i].value);
		
	
	}
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	//printf("Quick Sort called\n");
	QuickSort(p,0, n);
		clock_gettime(CLOCK_REALTIME,&end);
	double seconds= end.tv_sec - start.tv_sec;

	//printf("After Quick Sort\n");
		for(int i = 0;i<n;i++){
		printf("%d %d\n", p[i].id, p[i].value);
		
	
	}	


	printf("%lf sec\n", seconds);
	

}

void QuickSort(Data *A, int low, int high){
	if(low<high){
	int s = Partition(A, low, high);
//	printf("Partition is %d\n",s);
	QuickSort(A, low, s-1);
	//QS(A +s+1, n-1);
	//QS(A, s-1);
	//Part(A, n-1);
	QuickSort(A, s+1, high);
//	printf("After two quick sorts\n");
	return;
	}
}

int Partition(Data *A, int low, int high){
/*
	while (i<=j)
	.
	.
	.
	.
	
	return j+1



*/
	
  Data pivot = A[high]; Data temp;   // pivot 
  int i = (low - 1);  // Index of smaller element  
  for (int j = low; j <= high- 1; j++) 
   { 
        // If current element is smaller than or 
        // equal to pivot 
        if (A[j].id <= pivot.id) 
        { 
            i++;    // increment index of smaller element 
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        } 
    } 
    temp = A[i+1];
    A[i+1] = A[high];
    A[high] = temp;
 //   swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
	

}
