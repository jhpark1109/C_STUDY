#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

bool is_prime[10001];//소수라면 true
bool visited[10001];

int F, T;

void erathos()//에라토스의 체는 굉장히 유명한 공식이다. 꼭 알아두자
{
	memset(is_prime,true, 10001);

	is_prime[0]=is_prime[1]=false;

	for(int i=2;i*i<10001;i++)
	{
		for(int j=i+i;j<10001;j+=i)//어떤수의 배수가 된다면 그 값들을 제거해준다
		{
			if(is_prime[j])
				is_prime[j]=false;
		}
	}
	for(int i=2;i<1001;i++)//4자리 숫자들만 취급해준다
		is_prime[i]=false;
}

int bfs()// 
{
	queue<pair<int,int> > q;
	q.push(make_pair(F,0));
	visited[F]=true;

	if(F==T)
		return 0;
	int n, t;

	while(!q.empty())
	{
		n=q.front().first;
		t=q.front().second;
		q.pop();

		int carry=1;
		for(int i=0;i<4;i++)//1, 10, 100, 1000 자리를 바꿔가면서 해당 숫자가 가능한지 확인한다
		{			
			int next;
			next=n-n/carry%10*carry;//현재 자릿수의 숫자를 비워준다
			for(int j=0;j<10;j++)//현재 자릿수의 숫자를 바꿔준다
			{				
				if(!visited[next] && is_prime[next])//바뀐수가 소수인지, 방문한적이 없는지 확인해준다
				{
					visited[next]=true;
					q.push(make_pair(next, t+1));//조건을 만족하는 현재 숫자도 각 자릿수를 바꿔주면 소수가 될 수도 있다
					if(next==T)//우리가 원하는 숫자로 변했다면 지금까지 걸린 횟수 +1 값을 되돌려준다
						return t+1;
				}
				next+=carry;//만약 return되지 못했다면 자릿수를 하나 올려준다
			}
			carry*=10;
		}
	}
	return -1;//모든 숫자를 바꿨지만 실패했다면 -1을 return 해준다
}

int main()
{
	erathos();

	int testcase;
	scanf("%d", &testcase);

	while(testcase--)
	{
		scanf("%d %d", &F, &T);

		memset(visited, false, 10001);
		int ans=bfs();

		if(ans==-1)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}