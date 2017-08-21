#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double x, y, c;
double solve()
{
	double high=max(x, y);
	double low=0.0;
	double mid;
	for(int i=0;i<=10000;i++)
	{
		mid=(low+high)/2.0;
		double d=mid;
		double h1=sqrt(x*x-d*d); //�� �κп� ���� ����
		double h2=sqrt(y*y-d*d); //�˾ƾ߸� Ǯ �� �ִ�
		double h=(h1*h2)/(h1+h2);//
		if(h>c)
			low=mid;
		else
			high=mid;
	}
	return low;
}
int main()
{
	while(scanf("%lf %lf %lf", &x, &y, &c)==3)
	{
		printf("%.3lf\n", solve());
	}
	return 0;
}