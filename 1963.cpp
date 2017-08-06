#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

bool is_prime[10001];//�Ҽ���� true
bool visited[10001];

int F, T;

void erathos()//�����佺�� ü�� ������ ������ �����̴�. �� �˾Ƶ���
{
	memset(is_prime,true, 10001);

	is_prime[0]=is_prime[1]=false;

	for(int i=2;i*i<10001;i++)
	{
		for(int j=i+i;j<10001;j+=i)//����� ����� �ȴٸ� �� ������ �������ش�
		{
			if(is_prime[j])
				is_prime[j]=false;
		}
	}
	for(int i=2;i<1001;i++)//4�ڸ� ���ڵ鸸 ������ش�
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
		for(int i=0;i<4;i++)//1, 10, 100, 1000 �ڸ��� �ٲ㰡�鼭 �ش� ���ڰ� �������� Ȯ���Ѵ�
		{			
			int next;
			next=n-n/carry%10*carry;//���� �ڸ����� ���ڸ� ����ش�
			for(int j=0;j<10;j++)//���� �ڸ����� ���ڸ� �ٲ��ش�
			{				
				if(!visited[next] && is_prime[next])//�ٲ���� �Ҽ�����, �湮������ ������ Ȯ�����ش�
				{
					visited[next]=true;
					q.push(make_pair(next, t+1));//������ �����ϴ� ���� ���ڵ� �� �ڸ����� �ٲ��ָ� �Ҽ��� �� ���� �ִ�
					if(next==T)//�츮�� ���ϴ� ���ڷ� ���ߴٸ� ���ݱ��� �ɸ� Ƚ�� +1 ���� �ǵ����ش�
						return t+1;
				}
				next+=carry;//���� return���� ���ߴٸ� �ڸ����� �ϳ� �÷��ش�
			}
			carry*=10;
		}
	}
	return -1;//��� ���ڸ� �ٲ����� �����ߴٸ� -1�� return ���ش�
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