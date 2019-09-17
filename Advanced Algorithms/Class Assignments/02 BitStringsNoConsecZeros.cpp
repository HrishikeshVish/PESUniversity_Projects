#include<iostream>
#include<stdlib.h>
#include<time.h>
long int dp1(long int *);
long int dp2(long int *);
long int naive(long int n);
long int memoize(int n);
long int memoize_rec(int n, long int* Mem) ;
using namespace std;
long int dp1(long int n){
	long int a[n], b[n];
	a[0] = b[0] = 1;
	long int i;
	for(i = 1; i<n; i++){
		a[i] = a[i-1] + b[i-1];
		b[i] = a[i-1];
	}
	return a[n-1] + b[n-1];
}
long int dp2(long int n){
	long int x, y, z;
	int i;
	if (n == 0 || n== 1){
		return 1;
	}
	x = 1; y = 2;
	for(i = 2; i<=n; i++){
		z = x+y;
		x = y;
		y = z;
	}
	return z;
}
long int naive(long int n){
	if(n == 1){
		return 2;
	}
	if(n == 0){
		return 1;
	}

	return naive(n-1) + naive(n-2);
}
long int memoize(int n) {

	long int *Mem;
	long int ans;
	int i;
	Mem = (long int*)malloc(sizeof(long int)*(n+2));

	for(i = 0; i < n+1; ++i) {
		Mem[i] = -1;
	}

	Mem[0] = 1;
	Mem[1] = 2;
	Mem[2] = 3;

	ans = memoize_rec(n, Mem);
	free(Mem);
	return ans;
}

long int memoize_rec(int n, long int* Mem) {

	if(Mem[n] == -1) {
		Mem[n] = memoize_rec(n-1, Mem) + memoize_rec(n-2, Mem);
	}
	return Mem[n];
}
int main(){
	long int n;
	int *A;
	long int ansnaive, ansmem, ansdp1, ansdp2;
	clock_t start, end;
	double time_exec;
	A = (int *) malloc(50 * sizeof(int));

	for (n = 1; n <= 55; ++n) {
		//A[n-1] = (rand() % 10) + 1;
		if(n < 30) continue;

		printf("%d: ", n);

		
		start = clock();
		ansnaive = naive(n);
		end = clock();
		printf("%ld\t", ansnaive); 

		printf("Naive: ");
		time_exec = ((double)(end-start))/ CLOCKS_PER_SEC;
		printf("%lf\t", time_exec);
		printf("Memoization: ");
		start = clock();
		ansmem = memoize(n);

		end = clock();
		time_exec = ((double)(end-start))/ CLOCKS_PER_SEC;
		printf("%lf\t", time_exec);

		printf("DP: ");
		start = clock();
		ansdp1 = dp1(n);

		end = clock();
		time_exec = ((double)(end-start))/ CLOCKS_PER_SEC;
		printf("%lf\t", time_exec);
	

		printf("DP2: ");
		start = clock();
		ansdp2 = dp2(n);
		end = clock();
		
		time_exec = ((double)(end-start))/ CLOCKS_PER_SEC;
		printf("%lf\n", time_exec);
	}
	return 0;
}
