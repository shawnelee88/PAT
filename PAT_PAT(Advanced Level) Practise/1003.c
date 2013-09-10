#include <stdio.h>
#include <stdlib.h>

#define INFINITY 100000
#define MAXNUM 500
int map[MAXNUM][MAXNUM];
int team[MAXNUM];
int isVisit[MAXNUM];
int dist[MAXNUM];
int ans;
int maxTeamNum = 0;


void init()
{
	int i, j;
	for(i = 0; i < MAXNUM; i++){
		isVisit[i] = 0;
		team[i] = 0;
		dist[i] = INFINITY;
		for(j = 0; j < MAXNUM; j++){
			if(j != i){
				map[i][j] = INFINITY;
				map[j][i] = INFINITY;
			}
		}
	}
}


void dijskra(int n, int source)
{

	int i,j;
	int minDis = INFINITY;
	int index = 0;

	for(i=0; i<n; i++){
		dist[i] = map[source][i];
	}

	isVisit[source] = 1;//将其加入已访问点的集合
	
	for(i = 0; i < n-1; i++){
		minDis = INFINITY;
		index = 0;
		for(j = 0; j < n; j++){
			if(!isVisit[j] && dist[j] < minDis){//找到最小距离点
				minDis = dist[j];
				index = j;
			}
		}

		isVisit[index] = 1;//将其加入已访问点的集合
		for(j = 0; j < n; j++){//更新源点与每个点之间的距离
			if(map[index][j] < INFINITY && dist[j] > dist[index] + map[index][j])
				dist[j] = dist[index] + map[index][j];
		}
	}
}



void dfs(int n,int cId,int dest,int curDis,int curTeamNum)
{
	int i;

	isVisit[cId] = 1;
	if(cId == dest){
		if(curDis == dist[dest]){
			ans++;//最短路径数+1
			if(curTeamNum > maxTeamNum)
				maxTeamNum = curTeamNum;
		}
		return;
	} 

	if(curDis > dist[dest]){//当前的路径长度已经超过最短路径,就没有必要继续搜索了。
		return;
	}

	for(i = 0; i < n; i++){
		if(!isVisit[i] && map[cId][i] < INFINITY){//城市i未被访问过，且cId到i连通
			dfs(n, i, dest, curDis + map[cId][i], curTeamNum + team[i]);
			isVisit[i]=0;
		}
	}
}

int main()
{
	int n, m, source, dest;
	int c1, c2, length;
	int i;

	scanf("%d%d%d%d", &n, &m, &source, &dest);

	init();
	for(i = 0; i < n; i++){
		scanf("%d", &team[i]);
	}

	for(i = 0; i < m; i++){
		scanf("%d%d%d", &c1, &c2, &length);
		map[c1][c2] = length;
		map[c2][c1] = length;
	}

	dijskra(n, source);
	for(i = 0; i < n; i++){
		isVisit[i] = 0;
	}
		
	dfs(n, source, dest, 0, team[source]);
	printf("%d %d\n", ans, maxTeamNum);
	return 0;
}
