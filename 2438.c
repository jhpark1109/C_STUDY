#include<stdio.h>

int main()
{
	int N, i, j;//N: 입력받을 수, i, j: 반복문 인자가 2개 필요하다
	scanf("%d", &N);//처음에는 N입력
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=i;j++)//첫줄에는 i개 만큼 별을 입력해줘야 한다.
		{
			printf("*");
		}
		printf("\n");//한줄의 별을 다 찍었으면 다음줄로 넘어간다.
	}
	return 0;
}