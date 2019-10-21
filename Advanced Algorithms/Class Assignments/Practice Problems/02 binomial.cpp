#include<stdio.h>
#include<stdlib.h>
#include<iostream>
int binomial_coef(int n, int k, int **DP){

	for(int i = 0; i<=n;i++){
		DP[i][0] = 1;
		DP[i][i] = 1;
	}
	
	
	if(DP[n][k] == -1){
		DP[n][k] = binomial_coef(n-1, k, DP) + binomial_coef(n-1, k-1, DP);
	}
	return DP[n][k];
}
int min(int a, int b){
	return a>b?b:a;
}
int binomial(int n, int k){
	int **DP = (int **)malloc(sizeof(int*)*(n+1));
	*DP = (int*)malloc(sizeof(int)*(k+1));
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=min(i,k);j++){
			if(j == 0 || j==i){
				DP[i][j] = 1;
			}
			else{
				DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
			}
		}
	}
	return DP[n][k];	
}
int max(int a, int b){
	return a>b?a:b;
}
int binomial2(int n, int k, int **DP){

	for(int i = 0; i<=n;i++){
		DP[i][0] = 1;
		DP[i][i] = 1;
	}
	
	if(n-k<k){
		k = n-k;
	}
	for(int i = 0; i<=n; i++){
		for(int j = max(0, k-(n-i));j<=min(i,k);j++){
			if(j == 0 || j ==i){
				DP[i%2][j] = 1;
				
				}
			else{
			
				DP[i%2][j]= DP[(i-1)%2][j] + DP[(i-1)%2][j-1];
			}
		}
	}
	return DP[n%2][k];
}

int main(){
	int n, k;
	std::cin>>n>>k;
	int **DP = (int **)malloc(sizeof(int*)*(n+1));
	*DP = (int *)malloc(sizeof(int)*(k+1));
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=k; j++){
			DP[i][j] = -1;
		}
	}
	std::cout<<binomial2(n,k, DP)<<"\n";
	std::cout<<binomial(n, k)<<"\n";
	std::cout<<binomial_coef(n, k, DP)<<"\n";
}
