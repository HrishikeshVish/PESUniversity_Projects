#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int mat[5];

int memoize_mult(int *a, int start, int end){
	int k, i;
	int count = INT_MAX;
		if(start == end){
		return 0;
	}
	for(k = start;k<end;k++){
		
		mat[k-1] = memoize_mult(a, start, k) + memoize_mult(a, k+1, end) + a[start-1]*a[k]*a[end];

		if(mat[k-1] < count){
			count = i;
		}
	}
	return count;
}
int dp1(int *a, int start, int end){
	int k, i;
	int count = INT_MAX;
	if(start == end){
		return 0;
	}
	int y;
	for(k = start;k<end;k++){



		i = dp1(a, start, k) + dp1(a, k+1, end) + a[start-1]*a[k]*a[end];

		if(i < count){
			count = i;
		}
	}
	return count;
}
int dp2(int *a, int start, int end){
	int k, i;
	int *F = (int*)malloc(sizeof(int)*(end-start+1));
	int count  = INT_MAX;
	if(start == end){
		return 0;
	}
	int y;
	for(k = start;k<end;k++){
		F[k-start] = dp2(a, start, k) + dp2(a, k+1, end) + a[start-1]*a[k]*a[end];
		if(F[k-start]<count){
			count = F[k-start];
		}
	}
	return count;
}
int main(){
	int  b[7];
	int a[] = {30,35,15,5,10,20,25};
	int i;
	/*for(i = 0; i<7;i++){
		scanf("%d", &a[i]);
	}*/
	int minval;
	minval = dp1(a, 1, 6);
	printf("Minimum number of multiplications = %d\n", minval);
	minval = dp2(a, 1, 6);
	printf("Minimum number of multiplications = %d\n", minval);
	
}

