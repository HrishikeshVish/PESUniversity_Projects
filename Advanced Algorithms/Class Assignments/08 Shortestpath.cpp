#include<iostream>
#include<stdlib.h>
int  w[5][5];
int in(int *e, int k, int n){
	for(int i = 0; i<n; i++){
		if(e[i] == k){
			return 1;
		}
	}
	return 0;
}
int shtp(int w[5][5], int *e, int cur, int start, int end){
	int min = 10000000;
	int count;
	for(int k = 0; k<end; k++){
		if(k == end){
			continue;
		}
		if(!in(e, k, cur)){
			
			e[cur+1] = k;
			count = shtp(w, e, cur+1, start, k) + w[k][end];

			count  = count %10000000;
			printf("Count is when k = %d is %d and min is %d\n", k, count, min);
			if(min>count){
				
				min = count;
			}
		}
	}
	return min;
}
/*
void bfs_main(int w[5][5]){
	int v[5];
	for(int i = 0; i<5;i++){
		v[i] =-1;
	}
	for(int i = 0; i<5;i++){
		if(v[i] == -1){
			bfs(i, v, w);
		}
	}
}
void bfs(int i, int *v, int w[5][5]){
	printf("%d\n", i);
	v[i] = 1;
	
}

*/
void print(int w[5][5]){
	for(int i = 0; i<5; i++){
		for(int j = 0; j<5; j++){
			printf("%d\t", w[i][j]);
		}
		std::cout<<"\n";
	}
}
int floyd(int w[5][5]){
	printf("Inside Floyd\n");
	print(w);
	int *pathlist = (int*)malloc(sizeof(int)*5);
			pathlist[0] = 0;
			int pathlistvar = 1;
			int dist[5][5], i, j, k;
			for(i = 0;i<5; i++){
				for(j = 0; j<5; j++){
					dist[i][j] = w[i][j];
				}
			}
			for(k = 0;k<5; k++){
				for(i = 0; i<5; i++){
		
					for(j = 0; j<5; j++){
						if(dist[i][k]+ dist[k][j]<dist[i][j]){
							
						
							dist[i][j] = dist[i][k] + dist[k][j];
						}
			
					}
				}
	
			}

		
		printf("\n");
		printf("The shortest path from 0 to 4 is %d\n", dist[0][4]);
}
int sdu(int w[5][5], int i , int j, int k){
	if(k == 4){

		return w[i][j];
	}
	int c1 = sdu(w, i, j, k-1);
	int c2 = sdu(w, 0,k, k-1) + sdu(w,k, j, k-1);
	return c1>=c2? c1:c2;
}

int main(){
	int w[][5] = {{0,74,83,91,11700}, {13,0,21,84,253}, {67,76,0,95,68}, {48,518,646,0,33}, {71,28,93,75,0}};
	/*for(int i = 0; i<5;i++){
		for(int j = 0; j<5; j++){
			scanf("%d", &w[i][j]);
		}
	}*/
	int *e = (int*)malloc(sizeof(int)*5);
	int min = shtp(w, e, 0,0,4);
	printf("%d", min);
	floyd(w);
	printf("Sdu is %d", sdu(w, 0, 4, 0));
}
