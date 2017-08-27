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
			if(arr[i]>arr[j]){   //1.증가 수열인지
				if(dp[i]<dp[j]){ //2.현재 dp[i]가 가지고
					dp[i]=dp[j]; //  있는 것보다 큰지
				}
			}
		}
		dp[i]+=1;                //3.마지막에 1을 더해준다
	}

	for(int i=0;i<N;i++){        //4.가장 큰 값을 찾는다
		if(ans<dp[i])
			ans=dp[i];
	}

	printf("%d", ans);
	return 0;
}