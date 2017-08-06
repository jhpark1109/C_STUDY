#include<cstdio>
#include<iostream>
using namespace std;

int m, ans1, ans2;

char arr[100][100];//��

bool visited[100][100];//������ ��

int x[4]={1,-1,0,0};//����Ű1

int y[4]={0,0,1,-1};//����Ű2

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



void dfs(int u, int v)//arr[u][v]���� 4�������� �������� �����ΰ�
{
	visited[u][v]=true;//�湮��(u, v�� ���ǿ� �´¾ַ� ����)
	for(int i=0;i<4;i++)
	{
		int nx=x[i];
		int ny=y[i];
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=m)//����out->continue
			continue;
		if(arr[u+nx][v+ny]==arr[u][v]&& !visited[u+nx][v+ny])//->���ΰ���&& �湮���� ����-> �� �������� �ٽ� Ȯ��
		{
			dfs(u+nx, v+ny);
		}
	}
}
void dfs2(int u, int v)//arr[u][v]���� 4�������� �������� �����ΰ�
{
	visited[u][v]=true;//�湮��(u, v�� ���ǿ� �´¾ַ� ����)
	for(int i=0;i<4;i++)
	{
		int nx=x[i];
		int ny=y[i];
		if(u+nx<0 || u+nx>=m || v+ny<0 || v+ny>=m)//����out->continue
			continue;
		if(!visited[u+nx][v+ny]){//->�ϴ� �湮������ ����� �Ѵ�
			if(arr[u+nx][v+ny]==arr[u][v])//->���� ���� == (R, R) (G, G) (B, B)
			{
				dfs2(u+nx, v+ny);
			}
			else if((arr[u+nx][v+ny]=='R' || arr[u+nx][v+ny]=='G' )&&( arr[u][v]=='G' || arr[u][v]=='R'))
			{//-> ���� R �Ǵ� G�̴�
				dfs2(u+nx, v+ny);
			}
		}
	}
}

void check()//����ϰ� DFS�� Ž���Ѵ�
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
void check2()//Ư�� ��Ģ�� ����� DFS2�� ���
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
	reset();// check���� ����� visited�Լ��� �ʱ�ȭ���ش�
	check2();
	printf("%d %d", ans1, ans2);

	return 0;

}