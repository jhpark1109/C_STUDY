#include <cstdio>
#include <queue>
using namespace std;
int N, M, V;
bool arr[1001][1001];
bool visited[1001];

void DFS(int n){
	visited[n]=true;
	printf("%d ", n);
	for(int i=1;i<=N;i++){
		if(arr[n][i] && !visited[i]){
			DFS(i);
		}
	}

}

void BFS(int n){
	queue<int> q;
	visited[n]=true;
	q.push(n);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d ", now);
		for(int i=1;i<=N;i++){
			if(arr[now][i] && !visited[i]){
				q.push(i);
				visited[i]=true;
			}
		}	
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	for(int i=0;i<M;i++){
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v]=arr[v][u]=true;
	}
	DFS(V);
	printf("\n");
	for(int i=1;i<=N;i++){
		visited[i]=false;
	}
	BFS(V);
	return 0;
}