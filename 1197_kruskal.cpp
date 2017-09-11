#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

vector<pair<int, pair<int, int> > > vec;
vector<int> root;//a의 root가 b일때 root[a]=b
int N, M;

int find(int q)//root를 찾아줌, root가 없다면(자신이면) 자신을 return
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
};//두 정점의 root를 같게 해준다 == 두 정점을 이어준다

int main()
{
	int answer=0;
	scanf("%d %d", &N, &M);
	root.resize(N+1);

	for(int i=1;i<=N;i++)//아직은 처음이므로 각각의 간선의 root는 없다. 자기 자신이 root임
		root[i]=i;

	for(int i=0;i<M;i++)
	{
		int start, end, cost;
		scanf("%d %d %d", &start, &end, &cost);
		vec.push_back(make_pair(cost, make_pair(start, end)));//가중치를 가장 앞으로 해줌
	}
	sort(vec.begin(), vec.end());//가중치가 가장 작은 순으로 정렬됨

	for(int i=0;i<M;i++)//간선의 개수만큼 확인해주면됨
	{
		if(find(vec[i].second.first) != find(vec[i].second.second))//간선 끝 각각의 노드의 root가 같다면 순환되는 것이다.
		{
			answer+=vec[i].first;
			Union(vec[i].second.first, vec[i].second.second);// 간선을 이어준다
		}
	}
	printf("%d", answer);
}