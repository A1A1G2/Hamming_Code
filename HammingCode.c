#include <stdio.h>
#include <stdlib.h>
int backtracking(int graph[][5],int curr, int *visited,int start);
int main(){
	int graph1[5][5]={{0, 0, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
                     
    int visited[5] = {0};
    backtracking(graph1,0,visited,0);

    
}

int backtracking(int graph[][5],int curr, int *visited,int start){
	int i;
	visited[curr] = 1;
	for(i = 0; i < 5; i++){
		if(graph[curr][i] == 1){
			if(!visited[i] && backtracking(graph,i,visited,start)){
				printf(" %d \n",curr);
				return 1;
			}
		}	
	}
	if(graph[curr][0]){
		for(i = 0; i < 5; i++){
			if(visited[i] == 0){
				visited[curr] = 0;
				return 0;
			}
		}
		printf(" %d \n",curr);
		return 1;
	}
	visited[curr] = 0;
	return 0;
}
