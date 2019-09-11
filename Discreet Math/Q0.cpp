#include<stdio.h>
long int fib(long int);
int main(){
	
	long int limit = 4000000;
	printf("The sum of the fibonacci series is %ld\n", fib(limit));
}

long int fib(long int limit){
	
	long int sum = 0;
	long int i = 1;
	long int j = 2;
	
	while (i<=limit || j<=limit){
		

		
		if(j%2 == 0){
			
			sum= sum + j;
		}
		if(i%2 == 0){
			sum = sum + i;
		}
		i = i + j;
		j = i + j;
		
		
	}
	return sum;
	
}
