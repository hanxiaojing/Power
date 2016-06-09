#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

bool g_invalidInput = false;

bool isEqual(double num1,int num2)
{
	return((num1 - num2 >= -0.0000001) && (num1 - num2 <= 0.0000001));
}

double _Power(double base, int absexp)
{
	double result = 1.0;
	while (absexp--)
	{
		result *= base;
	}
	return result;
}


double Power(double base,int exp)
{
	//����Ϊ0.0��ָ��С��0������0.0
	if (isEqual(0.0, base) && exp < 0)
	{
		g_invalidInput = true;//��ʱ�Ƿ����룬����������ķ���0.0����
		return 0.0;
	}
	
	//ָ��С��0����ȥ����ָ���Ĵ�������ȡ����
	int absexp = exp;
	if (exp < 0)
	{
		absexp = -exp;
	}

	double result = _Power(base, absexp);
	if (exp < 0)
	{
		result = 1.0 / result;
	}
	return result;
}


void testpower()
{
	double base = 0.0;
	int exp = 0;
	scanf("%lf%d", &base, &exp);
	double ret = Power(base, exp);
	printf("%lf", ret);
}

int main()
{
	testpower();
	system("pause");
	return 0;
}