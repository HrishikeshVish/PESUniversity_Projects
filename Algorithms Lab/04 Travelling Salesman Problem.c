#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int tsp(int **graph, int n);
int get_next_permutation(int *permutation, int n);
void print_permutation(int *permutation, int n);
void main(){
int n;

    int **a = (int **)malloc(25 * sizeof(int *)); 
    for (int i=0; i<25; i++) 
         a[i] = (int *)malloc(25 * sizeof(int));
scanf("%d",&n);
getchar();
for(int i=0;i<=n-1;i++)
{
	for(int j=0;j<=n-1;j++)
	scanf("%d",&a[i][j]);
	getchar();
}
struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	int min_cost =tsp(a,n);
	clock_gettime(CLOCK_REALTIME,&end);
	double seconds= end.tv_nsec - start.tv_nsec;
	printf("%d\n",min_cost);
	printf("%lf",seconds);
}


int tsp (int **graph, int n){
	int min = 99999999;
	int *perm = (int *)malloc(sizeof(int)*(n-1));
	int *temp = (int*)malloc(sizeof(int)*(n-1));	
	for(int i = 0; i<n-1 ; i++){
		perm[i] = i+1;
	}
	
	
	int cost = 0;
	do{
		cost = graph[0][perm[0]];
		cost = cost + graph[perm[n-2]][0];
		for (int i = 0; i <=n-3;i++)
			cost = cost + graph[perm[i]][perm[i+1]];
			
		
	if(cost<min){min = cost; for(int i = 0;i<n-1;i++){temp[i] = perm[i];}}

	}while(get_next_permutation(perm, n-1));
	
	print_permutation(temp, n-1);
	
	return min;
}

int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}
void print_permutation(int *permutation, int n) {
	int i;
	printf("[");
	for(i = 0; i < n-1; i++) {
		printf("%d, ", permutation[i]);
	}
	printf("%d]\n", permutation[n-1]);
}
