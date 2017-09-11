#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > vec; //간선정보 저장: [시작 정점](끝 정점, 가중치)
vector<int> visited; //정점의 방문여부

int prim(int start)
{
	int answer=0;
	priority_queue<pair<int, int> > q;//우선순위 큐 선언
	visited[start]=true;

	for(int i=0;i<vec[start].size();i++)
		q.push(make_pair(-vec[start][i].second, vec[start][i].first));
	//큐에 들어가는 형태(-가중치, 다음 정점)
	//숫자가 큰 순서대로 pop되기 때문에 가중치를 음의 값으로 바꿔주었다
	
	while(!q.empty())
	{
		int now=q.top().second;//현재 정점
		int nowcost=-q.top().first;//가중치
		q.pop();

		if(visited[now])//지금 정점을 방문한 적이 있다면 while문 처음으로
			continue;

		visited[now]=true;
		
		for(int i=0;i<vec[now].size();i++)
		{
			int next=vec[now][i].first;//다음 정점
			int nextcost=vec[now][i].second;//다음 정점으로 가는 비용
			if(!visited[next])
				q.push(make_pair(-nextcost, next));//(-가중치, 다음정점)
		}
		answer+=nowcost;//비용을 더해줌
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
		vec[start].push_back(make_pair(end, cost));//간선이 양방향이기 때문에
		vec[end].push_back(make_pair(start, cost));//두 정점에 대해 모두 해줘야 한다
	}
	
	printf("%d\n", prim(1));//시작 지점을 1로 정해준 것이다. 아무 정점이나 넣어줘도 괜찮다.
	return 0;
}