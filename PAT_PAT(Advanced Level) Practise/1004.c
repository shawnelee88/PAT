#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 100


int level[MAXNUM];
int parent[MAXNUM];
int isleaf[MAXNUM];
int maxLevel = 0;

void findLevel(int x)
{
	int r = x;
	int tmp = 0;  //叶节点的层数，从0开始

	while(parent[r] != r){
		tmp++;
		r = parent[r];
	}
	level[tmp]++;  //所在层数的叶节点数+1
	if(tmp >= maxLevel){
		maxLevel = tmp;
	}
}

//节点号应该默认是从01递增
int main()
{
	int i, j;
	int n, m, id, k, tmp;

	for(i = 0; i < MAXNUM; i++){
		level[i] = 0;
		parent[i] = i;
		isleaf[i] = 1;
	}
	
	scanf("%d%d", &n, &m);
	if(n == 1){
		printf("1\n");
		return 0;
	}else{
		for(i = 0; i < m; i++){  //input m lines
			scanf("%d%d", &id, &k);
			for(j = 0; j < k; j++){
				scanf("%d", &tmp);
				parent[tmp] = id;  //set the parent of j to id
			}
			isleaf[id] = 0;  //node id is not leaf again
		}

		for(i = 1; i <= n; i++){
			if(isleaf[i] == 1){
				findLevel(i);
			}
		}

		printf("%d", level[0]);
		for(i = 1; i <= maxLevel; i++){
			printf(" %d", level[i]);
		}
		printf("\n");
		return 0;
	}
}