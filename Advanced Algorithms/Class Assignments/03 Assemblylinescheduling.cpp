#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits>
const int no = 4;
int min(int a, int b) { return a < b ? a : b; } 

int dp2(int a[][no], int t[][no], int *e, int *x){
	long int l1, l2;
	l1 = e[0] + a[0][0];
	l2 = e[1] + a[1][0];
	int i, l3;
	for(i = 1; i<no; i++){
		l3 = min(l1 + a[0][i], l2 + t[1][i] + a[0][i]);
		l2 = min(l2 + a[1][i], l1 + t[0][i] + a[1][i]);
		l1 = l3;
	}
	return min(l1 + x[0], l2+x[1]);
}

void memoize_recurse(int a[][no], int t[][no], int *e, int *x, int *MemL1, int *MemL2, int start){
	int i = 1;
	while(MemL1[i]==-1 || MemL2[i] == -1){
		MemL1[i] = min(MemL1[i-1]+a[0][i], MemL2[i-1]+t[1][i] + a[0][i]);
		MemL2[i] = min(MemL2[i-1]+ a[1][i], MemL1[i-1]+ t[0][i]+ a[1][i]);
		i++;
	}
	return;
}

int memoize(int a[][no], int t[][no], int *e, int *x){

	int *MemL1 = (int *)malloc(sizeof(int)*no);
	int *MemL2 = (int *)malloc(sizeof(int)*no);

	for(int i = 0; i<no; i++){
		MemL1[i] = -1;
	}
	for(int i = 0; i<no; i++){
		MemL2[i] = -1;
	}
	
	MemL1[0] = e[0] + a[0][0];
	MemL2[0] = e[1] + a[1][0];
	memoize_recurse(a, t, e,x,MemL1, MemL2, 1);
	int minval = min(MemL1[no-1] + x[0], MemL2[no-1]+x[1]);
	free(MemL1);
	free(MemL2);
	return minval;
	
}

int naive(int a[][no], int t[][no], int *e, int *x){
	
}

int dp1(int a[][no], int t[][no], int *e, int *x){
	int L1[no], L2[no], i;
	L1[0] = e[0] + a[0][0];
	L2[0] = e[1] + a[1][0];

	for(i = 1; i< no; ++i){
		L1[i] = min(L1[i-1]+ a[0][i], L2[i-1] + t[1][i] + a[0][i]);
		L2[i] = min(L2[i-1]+ a[1][i], L1[i-1] + t[0][i] + a[1][i]);
		
	}
	return min(L1[no-1] + x[0], L2[no-1] + x[1]); 
}



int main() 
{ 
    int a[][no] = {{4, 5, 3, 2}, 
                {2, 10, 1, 4}}; 
    int t[][no] = {{0, 7, 4, 5}, 
                {0, 9, 2, 8}}; 
    int e[] = {10, 12}, x[] = {18, 7}; 
  
    printf("%d\n", dp1(a, t, e, x)); 
    printf("%d\n", memoize(a, t, e, x));
	printf("%d", dp2(a, t, e,x));
    
  
    return 0; 
} 


