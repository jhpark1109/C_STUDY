#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> vec;
bool binary(int n)
{
	int high=N-1;
	int low=0;
	int mid;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(vec[mid]==n)
			return true;
		else if(vec[mid]>n)
			high=mid-1;
		else
			low=mid+1;
	}
	return false;
}
int main()
{
	scanf("%d", &N);
	vec.resize(N);
	for(int i=0;i<N;i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());
	scanf("%d", &M);
	for(int i=0;i<M;i++)
	{
		int n;
		scanf("%d", &n);
		printf("%d ", upper_bound(vec.begin(), vec.end(), n)-lower_bound(vec.begin(), vec.end(), n));//서로의 위치를 빼주면 그 사이의 개수가 나온다
	}
	return 0;
}

