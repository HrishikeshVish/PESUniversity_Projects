#include<iostream>
#include<limits>
#include<stdlib.h>
#include<vector>
#define INF 100000

using namespace std;
class pathproblems{
	private:
		int paths;
		int *pathlist;
	public:
		void num_paths_recurse(int graph[][5], int current, int end){
			if(current == end){
		
				paths = paths + 1;
				return;
			}
			else{
				for(int i = current+1; i<=4; i++){
					if(graph[current][i] !=0 && graph[current][i] !=INF){
			
						num_paths_recurse(graph, i, end);
					}
				}
			}
	
	
		}
		int returnpath(){
			int path2 = paths;
			paths = 0;
			return path2;
		}
		void shortestpath(int graph[][5]){
			pathlist = (int*)malloc(sizeof(int)*5);
			pathlist[0] = 0;
			int pathlistvar = 1;
			int dist[5][5], i, j, k;
			for(i = 0;i<5; i++){
				for(j = 0; j<5; j++){
					dist[i][j] = graph[i][j];
				}
			}
			for(k = 0;k<5; k++){
				for(i = 0; i<5; i++){
		
					for(j = 0; j<5; j++){
						if(dist[i][k]+ dist[k][j]<dist[i][j]){
							if(notinlist(k))
							pathlist[pathlistvar++] = k;
						
							dist[i][j] = dist[i][k] + dist[k][j];
						}
			
					}
				}
	
			}
		pathlist[pathlistvar++] = 4;
		print(pathlist, pathlistvar);
		free(pathlist);
		printf("\n");
		printf("The shortest path from 0 to 4 is %d\n", dist[0][4]);
		}
	void print(int *pathlist, int n){
		for(int i = 0; i<n; i++){
			printf("%d\t", pathlist[i]);
		}
		printf("\n");
	}
	int notinlist(int k){
		int i = 0;
		while(i<5){
			if(pathlist[i] == k){
				return 0;
			}
			i++;
		}
		return 1;
	}
	int shortespath_topleft_to_bottomright(int m, int n){
		return c(m+n, m);
	}
	/* If moving horizontally is 1 and vertically 0, then, this function returns the number of bit strings, representing the jumps between two vertices, 
		from start to end.	
	*/
	int c(int a, int b){
		int p = fact(a);
		int q = fact(b);
		int r = fact(a-b>0?a-b:b-a);
		return p/(q*r);
	}
	int fact(int a){
		int pr = 1;
		for(int i = 1;i<=a;i++ ){
			pr = pr*i;
		}
		return pr;
	}
	pathproblems(){
		paths = 0;
	}

};

int main(){
	pathproblems *obj = new pathproblems();
	
	int a = -1;
	int graph[5][5];// = {{0, 4,8,15,INF}, {INF,0,5,9,12}, {INF,INF,0,INF,9}, {INF,INF,INF,0,2}, {INF,INF,INF,INF,0}};
	for(int i = 0; i<5; i++){
		for(int j = 0;j<5; j++){
			scanf("%d", &graph[i][j]);
		}
	}
	obj->num_paths_recurse(graph, 0, 4);
	printf("No of Paths is %d\n", obj->returnpath());
	obj->shortestpath(graph);
	printf("Shortest path from top left to bottom right = %d\n", obj->shortespath_topleft_to_bottomright(4,4));
}
