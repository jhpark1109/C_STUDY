#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;
int N, M;

void division(int k)
{
	int low=0;
	int high=N-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(vec[mid]==k)
		{
			printf("1\n");//ã�Ҵ�
			return;
		}
		else if(vec[mid]<k)
			low=mid+1;
		else if(vec[mid]>k)
			high=mid-1;
	}
	printf("0\n");//�ᱹ ��ã�Ҵ�
}

int main()
{
	scanf("%d", &N);
	vec.resize(N,0);
	for(int i=0;i<N;i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());//�迭 ����
	scanf("%d", &M);
	while(M--)
	{
		int target;
		scanf("%d", &target);
		division(target);
	}
	return 0;
}