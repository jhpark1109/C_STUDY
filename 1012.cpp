#include<cstdio>
using namespace std;
int m, n, num;
bool arr[50][50];//���߹�
bool visited[50][50];//������ ��
int x[4]={1,-1,0,0};//����Ű1
int y[4]={0,0,1,-1};//����Ű2
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

void dfs(int u, int v)//arr[u][v]���� 4�������� �������� �����ΰ�
{
	visited[u][v]=true;//�湮��(u, v�� ���ǿ� �´¾ַ� ����)
	for(int i=0;i<4;i++)
	{
		int nx=x[i];
		int ny=y[i];
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=n)//����out->continue
			continue;
		if(arr[u+nx][v+ny]&& !visited[u+nx][v+ny])//->���� ��&& �湮���� ����-> �� ���ߺ��� �ٽ� Ȯ��
		{
			dfs(u+nx, v+ny);
		}
	}
}

int check()//�ϳ��� Ȯ���غ�(Ȯ�������ִ�->pass, Ȯ����������&&���߰� �ִ�->�������� �� �� Ȯ��(dfs)->��+=1)
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