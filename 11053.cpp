#include<cstdio>
using namespace std;
int arr[1000];
int dp[1000];
int main(){
	
	int ans=0;
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){   //1.���� ��������
				if(dp[i]<dp[j]){ //2.���� dp[i]�� ������
					dp[i]=dp[j]; //  �ִ� �ͺ��� ū��
				}
			}
		}
		dp[i]+=1;                //3.�������� 1�� �����ش�
	}

	for(int i=0;i<N;i++){        //4.���� ū ���� ã�´�
		if(ans<dp[i])
			ans=dp[i];
	}

	printf("%d", ans);
	return 0;
}