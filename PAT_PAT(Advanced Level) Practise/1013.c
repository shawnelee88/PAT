#include <stdio.h>
#include <stdlib.h>

#define MaxN 1001

typedef struct _Node{
	int adjvex;
	struct _Node *next;
}Node;

int visited[MaxN];
Node nodes[MaxN];

void InsertEdge(int head, int tail)
{
	Node *hEdge;
	Node *tEdge;

	hEdge = malloc(sizeof(Node));
	if(hEdge == NULL){
		perror("Our of space!");
		exit(1);
	}
	hEdge->adjvex = tail;
	hEdge->next = nodes[head].next;
	nodes[head].next = hEdge;

	tEdge = malloc(sizeof(Node));
	if(tEdge == NULL){
		perror("Out of space!");
		exit(1);
	}
	tEdge->adjvex = head;
	tEdge->next = nodes[tail].next;
	nodes[tail].next = tEdge;
	
	return;
}


void dfs(int index)
{
	Node *tmpEdge;

	visited[index] = 1;
	tmpEdge = nodes[index].next;
	while(tmpEdge != NULL){
		if(!visited[tmpEdge->adjvex]){
			dfs(tmpEdge->adjvex);
		}
		tmpEdge = tmpEdge->next;
	}

}




int main()
{
	int n, m, k;
	int i, j;
	int city1, city2;
	int tmpcity;
	Node *edge;
	int components[MaxN];

	scanf("%d%d%d", &n, &m, &k);
	for(i = 1; i <= n; i++){
		nodes[i].adjvex = i;
		nodes[i].next = NULL;
	}

	for(i = 0; i < m; i++){
		scanf("%d%d", &city1, &city2);
		InsertEdge(city1, city2);
	}
	
	for(i = 1; i <= k; i++){
		if(k != 1){
			components[i] = 0;
			scanf("%d", &tmpcity);
			for(j = 0; j <= n; j++){
				visited[j] = 0;
			}
			visited[tmpcity] = 1;
			////for w adjacent to v, dfs w
			//edge = nodes[tmpcity].next;
			//while(edge != NULL){
			//	if(!visited[edge->adjvex]){
			//		dfs(edge->adjvex);
			//		components[i]++;
			//	}
			//	edge = edge->next;
			//}
			for (j = 1; j <= n; ++ j) {
				if (!visited[j]) {
					dfs(j);
					components[i] ++;
				}
			}
		}else{
			components[i] = 1;
			scanf("%d", &tmpcity);
		}
		
	}
	
	for(i = 1; i <= k; i++){
		printf("%d\n", components[i] - 1);
	}


	return 0;
}
