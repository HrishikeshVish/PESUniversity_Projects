#include<stdio.h>
int product(){
	int i, j, k;
	for(i=1;i<=500;i++){
		for(j=1;j<=500;j++){
			for(k=1;k<=500;k++){
				if(i+j+k==1000){
					if((i*i)+(j*j) == (k*k)){
						//printf("%d %d %d\n", i, j, k);
						return (i*j*k);
					}
				}
			}
		}
	}
}

int main(){
	
	printf("The product of the three numbers is %d", product());
}
