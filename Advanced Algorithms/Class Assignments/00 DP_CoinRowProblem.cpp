#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Naive implementation
long int naive(int* A, int n);

//Memoization or memory function (top-down) implementation
long int memoize(int* A, int n);
long int memoize_rec(int* A, int n, long int* Mem);

//Dynamic Programming (bottom up) implementation
long int dp(int* A, int n);

//Dynamic Programming (bottom up) implementation with improved space efficiency
long int dp2(int* A, int n);

//returns the duration from start to end times in sec
double time_elapsed(struct timespec *start, struct timespec *end);

int main(int argc, char const *argv[]) {
	int n;
	int *A;
	long int ans;
	struct timespec start_time;
	struct timespec end_time;

	//time_t t; //Using time to seed random number in one of the test cases
	//srand((unsigned)time(&t));
	srand(3);

	A = (int *) malloc(50 * sizeof(int));

	for (n = 1; n <= 50; ++n) {
		A[n-1] = (rand() % 10) + 1;
		if(n < 30) continue;

		printf("%d: ", n);

		printf("Naive: ");
		clock_gettime(CLOCK_REALTIME, &start_time); //start timestamp
		ans = naive(A, n);
		clock_gettime(CLOCK_REALTIME, &end_time); //end timestamp
		printf("%lf, ", time_elapsed(&start_time, &end_time));

		printf("Memoization: ");
		clock_gettime(CLOCK_REALTIME, &start_time); //start timestamp
		if(ans != memoize(A, n)) printf("\nWRONG ANSWER!\n");
		clock_gettime(CLOCK_REALTIME, &end_time); //end timestamp
		printf("%lf, ", time_elapsed(&start_time, &end_time));

		printf("DP: ");
		clock_gettime(CLOCK_REALTIME, &start_time); //start timestamp
		if(ans != dp(A, n)) printf("\nWRONG ANSWER!\n");
		clock_gettime(CLOCK_REALTIME, &end_time); //end timestamp
		printf("%lf, ", time_elapsed(&start_time, &end_time));

		printf("DP2: ");
		clock_gettime(CLOCK_REALTIME, &start_time); //start timestamp
		if(ans != dp2(A, n)) printf("\nWRONG ANSWER!\n");
		clock_gettime(CLOCK_REALTIME, &end_time); //end timestamp
		printf("%lf sec.\n", time_elapsed(&start_time, &end_time));
	}
	return 0;
}

//Naive implementation
long int naive(int* A, int n) {
	long int r1, r2;
	if(n == 0) return 0;
	if(n == 1) return A[0];

	r1 = naive(A, n-1);
	r2 = naive(A, n-2) + A[n-1];
	return (r1 > r2) ? r1 : r2;
}

//Memoization or memory function (top-down) implementation
long int memoize(int* A, int n) {
	long int *Mem = (long int*) malloc((n+1) * sizeof(long int));
	for (int i = 0; i < n+1; ++i) {
		Mem[i] = -1;
	}
	Mem[0] = 0;
	Mem[1] = A[0];
	long int ans = memoize_rec(A, n, Mem);
	free(Mem);
	return ans;
}

long int memoize_rec(int* A, int n, long int* Mem) {
	if(Mem[n] == -1) {
		long int r1, r2;
		r1 = memoize_rec(A, n-1, Mem);
		r2 = memoize_rec(A, n-2, Mem) + A[n-1];
		Mem[n] = (r1 > r2) ? r1 : r2;
	}
	return Mem[n];
}

//Dynamic Programming (bottom up) implementation
long int dp(int *A, int n) {
	if(n == 0) return 0;
	if(n == 1) return A[0];

	long int *F = (long int*) malloc((n+1) * sizeof(long int));
	F[0] = 0;
	F[1] = A[0];
	for (int i = 2; i <= n; ++i) {
		F[i] = (F[i-1] > F[i-2] + A[i-1]) ? F[i-1] : F[i-2] + A[i-1];
	}
	long int ans = F[n];
	free(F);
	return ans;
}

//Dynamic Programming (bottom up) implementation with improved space efficiency
long int dp2(int *A, int n) {
	if(n == 0) return 0;
	if(n == 1) return A[0];

	long int f0 = 0, f1, fi;
	f1 = A[0];
	for (int i = 2; i <= n; ++i) {
		fi = (f1 > f0 + A[i-1]) ? f1 : f0 + A[i-1];
		f0 = f1;
		f1 = fi;
	}
	return fi;
}

//returns the duration from start to end times in sec
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
