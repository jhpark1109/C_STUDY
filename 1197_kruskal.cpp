#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<pair<int, pair<int, int> > > vec;
vector<int> root;//a�� root�� b�϶� root[a]=b
int N, M;

int find(int q)//root�� ã����, root�� ���ٸ�(�ڽ��̸�) �ڽ��� return
{
	if(root[q]==q)
		return q;
	else
		return root[q]=find(root[q]);
}

void Union(int start, int end)
{
	int x=find(start);
	int y=find(end);
	root[y]=x;
};//�� ������ root�� ���� ���ش� == �� ������ �̾��ش�

int main()
{
	int answer=0;
	scanf("%d %d", &N, &M);
	root.resize(N+1);

	for(int i=1;i<=N;i++)//������ ó���̹Ƿ� ������ ������ root�� ����. �ڱ� �ڽ��� root��
		root[i]=i;

	for(int i=0;i<M;i++)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vec.push_back(make_pair(cost, make_pair(start, end)));//����ġ�� ���� ������ ����
	}
	sort(vec.begin(), vec.end());//����ġ�� ���� ���� ������ ���ĵ�

	for(int i=0;i<M;i++)//������ ������ŭ Ȯ�����ָ��
	{
		if(find(vec[i].second.first) != find(vec[i].second.second))//���� �� ������ ����� root�� ���ٸ� ��ȯ�Ǵ� ���̴�.
		{
			answer+=vec[i].first;
			Union(vec[i].second.first, vec[i].second.second);// ������ �̾��ش�
		}
	}
	printf("%d", answer);
}