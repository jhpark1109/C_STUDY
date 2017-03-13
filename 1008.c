#include <stdio.h>

int main()
{
	double A, B;
	scanf("%lf %lf", &A, &B);//%d를 이용하여 입력을 받아도 값은 같다.
	printf("%.9lf", A/B);//오차범위가 10^(-9)이기 때문에 소수 9째 자리까지 나타내준다.
	//실수형의 출력 서식문자는 f, lf둘다 사용가능하다.
	return 0;
}