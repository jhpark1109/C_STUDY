#include<stdio.h>

int main()
{
	int i, T, a, b;
	scanf("%d", &T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d", &a, &b);//매 반복문 마다 정수 A B를 입력받고
		printf("%d\n", a+b);//그 A, B 또한 매번 더해서 출력해준다.
	}
	return 0;
}