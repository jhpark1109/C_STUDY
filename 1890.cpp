#include<cstdio>
using namespace std;
int arr[1000];
int dp[1000];                   //dp[i] : i번째 값을 마지막으로 하는
int main(){                     //        감소 수열의 길이의 최대값
	
	int ans=0;
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &arr[i]);

	for(int i=0;i<N;i++){
		for(int j=i-1;j>=0;j--){ //(현재를 기준으로 뒤로 돌아간다)
			if(arr[i]<arr[j]){   //1.감소 수열인지
				if(dp[i]<dp[j]){ //2.현재 dp[i]가 가지고
					dp[i]=dp[j]; //  있는 것보다 큰(긴)지
				}
			}
		}
		dp[i]+=1;                //3.1을 더해준다
	}

	for(int i=0;i<N;i++){        //4.가장 큰(긴) 값을 찾는다
		if(ans<dp[i])
			ans=dp[i];
	}

	printf("%d", ans);
	return 0;
}