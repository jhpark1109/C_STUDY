#include<stdio.h>

int main()
{
	int i, T, a, b;
	scanf("%d", &T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d", &a, &b);//�� �ݺ��� ���� ���� A B�� �Է¹ް�
		printf("%d\n", a+b);//�� A, B ���� �Ź� ���ؼ� ������ش�.
	}
	return 0;
}