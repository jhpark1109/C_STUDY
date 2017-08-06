#include<cstdio>
#include<iostream>
using namespace std;

int m, ans1, ans2;

char arr[100][100];//판

bool visited[100][100];//지나간 곳

int x[4]={1,-1,0,0};//방향키1

int y[4]={0,0,1,-1};//방향키2

void reset()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			visited[i][j]=false;
		}
	}
}



void dfs(int u, int v)//arr[u][v]에서 4방향으로 뻗었을때 ㅇㅋ인가
{
	visited[u][v]=true;//방문함(u, v가 조건에 맞는애로 들어옴)
	for(int i=0;i<4;i++)
	{
		int nx=x[i];
		int ny=y[i];
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=m)//범위out->continue
			continue;
		if(arr[u+nx][v+ny]==arr[u][v]&& !visited[u+nx][v+ny])//->서로같다&& 방문한적 없다-> 그 지점부터 다시 확인
		{
			dfs(u+nx, v+ny);
		}
	}
}
void dfs2(int u, int v)//arr[u][v]에서 4방향으로 뻗었을때 ㅇㅋ인가
{
	visited[u][v]=true;//방문함(u, v가 조건에 맞는애로 들어옴)
	for(int i=0;i<4;i++)
	{
		int nx=x[i];
		int ny=y[i];
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=m)//범위out->continue
			continue;
		if(!visited[u+nx][v+ny]){//->일단 방문한적이 없어야 한다
			if(arr[u+nx][v+ny]==arr[u][v])//->서로 같다 == (R, R) (G, G) (B, B)
			{
				dfs2(u+nx, v+ny);
			}
			else if((arr[u+nx][v+ny]=='R' || arr[u+nx][v+ny]=='G' )&&( arr[u][v]=='G' || arr[u][v]=='R'))
			{//-> 서로 R 또는 G이다
				dfs2(u+nx, v+ny);
			}
		}
	}
}

void check()//평범하게 DFS로 탐색한다
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!visited[i][j])
			{
				dfs(i, j);
				ans1+=1;
			}
		}
	}
}
void check2()//특수 규칙이 적용된 DFS2를 사용
{
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j])
			{
				dfs2(i, j);
				ans2+=1;
			}
		}
	}
}

int main()
{
	scanf("%d", &m);

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}
	check();
	reset();// check에서 사용한 visited함수를 초기화해준다
	check2();
	printf("%d %d", ans1, ans2);

	return 0;

}