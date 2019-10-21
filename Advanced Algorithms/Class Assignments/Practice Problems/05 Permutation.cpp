#include<stdlib.h>
#include<stdio.h>
#include<iostream>

void winner(int apos, int bpos, int *cells, int n){
	int counter=-1;
	for(int i = apos+1; i<n; i++){
		if(cells[i]>cells[apos]){
			if((i-apos)%cells[apos] == 0){
				counter = i;
			}
		}
		
	}
	if(counter==-1){
		std::cout<<"Player 2 Wins\n";
		exit(0);
	}

	int counter2=-1;
	for(int j = bpos+1; j<n; j++){
		if(cells[j]>cells[apos]){
			if((j-apos)%cells[apos] == 0){
				counter2 = j;
			}
		}
		
	}
	if(counter2 == -1){
		std::cout<<"Player 1 Wins\n";
		exit(0);
	}
	winner(counter, bpos, cells, n);
	winner(apos, counter2, cells, n);
}
int main(){
	int a[] = {1,2,3,4,5,6,7};
	int apos = 0;
	int bpos = 4;
	winner(apos, bpos, a, 7);
}
