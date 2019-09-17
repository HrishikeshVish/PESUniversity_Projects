#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Naive implementation
long int naive(int n);

//Memoization or memory function (top-down) implementation
long int memoize(int n);
long int memoize_rec(int n, long int* Mem);

//Dynamic Programming (bottom up) implementation
long int dp(int n);

//Dynamic Programming (bottom up) implementation with improved space efficiency
long int dp2(int n);

//returns the duration from start to end times in sec


int main(int argc, char const *argv[]) {
	int n;
	int *A;
	long int ansnaive, ansmem, ansdp1, ansdp2;
	clock_t start, end;
	double time_exec;
	A = (int *) malloc(50 * sizeof(int));

	for (n = 1; n <= 55000; ++n) {
		//A[n-1] = (rand() % 10) + 1;
		if(n >20) continue;

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
		ansdp1 = dp(n);

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

//Naive implementation
long int naive(int n) {

	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n==2) return 1; 

	return naive(n-1) + naive(n-2);
}

//Memoization or memory function (top-down) implementation
long int memoize(int n) {

	long int *Mem;
	long int ans;
	int i;
	Mem = (long int*)malloc(sizeof(long int)*(n+2));

	for(i = 0; i < n+1; ++i) {
		Mem[i] = -1;
	}

	Mem[0] = 0;
	Mem[1] = 1;
	Mem[2] = 1;

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

//Dynamic Programming (bottom up) implementation
long int dp(int n) {
	long int *F;
	long int ans;
	int i;

	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;

	F = (long int*) malloc((n+1) * sizeof(long int));
	
	F[0] = 0;
	F[1] = 1;
	F[2] = 1;
	for (i = 2; i <= n; ++i) {
		F[i] = F[i-1] + F[i-2];
	}
	ans = F[n];
	free(F);
	return ans;
}

//Dynamic Programming (bottom up) implementation with improved space efficiency
long int dp2(int n) {
	long int f0 = 0, f1, fi;
	int i; 

	if(n == 0) return 0;
	if(n == 1) return 1;
	if(n == 2) return 1;

	
	f1 = 1;
	for (i = 2; i <= n; ++i) {
		fi = f0 + f1;
		f0 = f1;
		f1 = fi;
	}
	return fi;
}
