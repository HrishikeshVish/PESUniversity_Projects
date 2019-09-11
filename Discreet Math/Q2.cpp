#include<stdio.h>
int diff(int);
int sum(int);
int sq(int);
int main(){
	
	int limit;
//	printf("Enter the number \n");
//	scanf("%d", &limit);
	printf("The difference is %d\n", diff(100));
	
}

int diff(int limit){
	return (sum(limit)- sq(limit));
}

int sum(int limit){
	int sum = (limit *(limit+1))/2;
	return (sum *sum);
}

int sq(int limit){
	
	int sum = limit*(limit + 1)*(2*limit + 1);
	return (sum/6);
}


