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
	//底数为0.0且指数小于0，返回0.0
	if (isEqual(0.0, base) && exp < 0)
	{
		g_invalidInput = true;//此时非法输入，与正常结果的返回0.0区分
		return 0.0;
	}
	
	//指数小于0，先去求正指数的次数，再取倒数
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