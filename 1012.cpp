#include<cstdio>
using namespace std;
int m, n, num;
bool arr[50][50];//배추밭
bool visited[50][50];//지나간 곳
int x[4]={1,-1,0,0};//방향키1
int y[4]={0,0,1,-1};//방향키2
void reset()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=visited[i][j]=false;
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
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=n)//범위out->continue
			continue;
		if(arr[u+nx][v+ny]&& !visited[u+nx][v+ny])//->배추 ㅇ&& 방문한적 없다-> 그 배추부터 다시 확인
		{
			dfs(u+nx, v+ny);
		}
	}
}

int check()//하나씩 확인해봄(확인한적있다->pass, 확인한적없다&&배추가 있다->인접배추 싹 다 확인(dfs)->답+=1)
{
	int ans=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!visited[i][j])
			{
				if(arr[i][j])
				{
					dfs(i, j);
					ans++;
				}
			}
		}
	}
	return ans;

}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d", &m, &n, &num);
		reset();
		while(num--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			arr[u][v]=true;
		}
		printf("%d\n", check());
	}
	return 0;
}