#include<stdio.h>

int main()
{
	int i, T, candy, children;//반복문 인자, 테스트 횟수, 사탕 수, 애들 수
	scanf("%d", &T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d", &candy, &children);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy/children, candy%children);
	}//사탕수/아이들 수를 하면 나오는 몪이, 사탕을 가장 많이 나누어 준 경우의 수이다. 이 나머지는 %로 연산가능
	return 0;
}