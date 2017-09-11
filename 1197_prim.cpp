#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > vec; //�������� ����: [���� ����](�� ����, ����ġ)
vector<int> visited; //������ �湮����

int prim(int start)
{
	int answer=0;
	priority_queue<pair<int, int> > q;//�켱���� ť ����
	visited[start]=true;

	for(int i=0;i<vec[start].size();i++)
		q.push(make_pair(-vec[start][i].second, vec[start][i].first));
	//ť�� ���� ����(-����ġ, ���� ����)
	//���ڰ� ū ������� pop�Ǳ� ������ ����ġ�� ���� ������ �ٲ��־���
	
	while(!q.empty())
	{
		int now=q.top().second;//���� ����
		int nowcost=-q.top().first;//����ġ
		q.pop();

		if(visited[now])//���� ������ �湮�� ���� �ִٸ� while�� ó������
			continue;

		visited[now]=true;
		
		for(int i=0;i<vec[now].size();i++)
		{
			int next=vec[now][i].first;//���� ����
			int nextcost=vec[now][i].second;//���� �������� ���� ���
			if(!visited[next])
				q.push(make_pair(-nextcost, next));//(-����ġ, ��������)
		}
		answer+=nowcost;//����� ������
	}
	return answer;
}

int main()
{
	scanf("%d %d", &N, &M);
	vec.resize(N+1);
	visited.resize(N+1);

	for(int i=0;i<M;i++)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vec[start].push_back(make_pair(end, cost));//������ ������̱� ������
		vec[end].push_back(make_pair(start, cost));//�� ������ ���� ��� ����� �Ѵ�
	}
	
	printf("%d\n", prim(1));//���� ������ 1�� ������ ���̴�. �ƹ� �����̳� �־��൵ ������.
	return 0;
}