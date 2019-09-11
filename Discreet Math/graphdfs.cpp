#include<stdio.h>
#include<stdlib.h>
int count (int[][5], int);
int dfs(int[][5], int[], int, int , int);
int main(){
	int graph[5][5];
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			graph[i][j] = 0;
		}
	}
	graph[0][1] = 1;
	graph[1][0] = 1;
	graph[0][2] = 1;
	graph[2][0] = 1;
	graph[3][4] = 1;
	graph[4][3] = 1;
	printf("%d", count(graph,5));
	
}

int count(int graph[][5], int size){
	int reach[size];
	int i;
	for(i=0;i<5;i++){
		reach[i] = 0;
	}
	int c = 0;
	c = dfs(graph, reach, size,0,1);
	for(i=0;i<5;i++){
		if(reach[i] ==0){
			c = c + dfs(graph, reach,size,i,1);
		}
	}
	return c;
}

int dfs(int graph[][5], int reach[], int size, int start, int flag){
	reach[start] = 1;
	int j;
	for(j=0;j<5;j++){
		if(graph[start][j] == 1 && reach[j] == 0){
			dfs(graph, reach, size, j, 0);
		}
	}
	if(flag == 1){
		return 1;
	}
	else{
		return 0;
	}
}
