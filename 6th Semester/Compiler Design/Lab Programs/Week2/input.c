#include<stdio.h>

//Program to calculate the factorial of an integer

//Recursive implementation
int fact(int a){
	if(a<=0){
		return 1; // Border case
	}
/* Base case when a is 1
the function returns 1 because
the factorial of 1 is 1*/
	if(a == 1){
		return 1;
	}
	return a*fact(a-1); //recursive call
}

int main(){

	int n;
	scanf("%d", &n); 
/* Input is a positive integer 
greater than or equal to one
*/
	printf("%d", fact(a));
	
}

//
/*   */
/**    */
/*
/*
*/
*/
