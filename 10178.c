#include<stdio.h>

int main()
{
	int i, T, candy, children;//�ݺ��� ����, �׽�Ʈ Ƚ��, ���� ��, �ֵ� ��
	scanf("%d", &T);
	for(i=1;i<=T;i++)
	{
		scanf("%d %d", &candy, &children);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", candy/children, candy%children);
	}//������/���̵� ���� �ϸ� ������ ����, ������ ���� ���� ������ �� ����� ���̴�. �� �������� %�� ���갡��
	return 0;
}