#include <stdio.h>

//阶乘

//递归方法
int factorial(int n)
{
	if (n <= 1)
		return n;
	else
		return n * factorial(n - 1);
}

//循环方法
int factorial_iter(int n)
{
	if (n <= 1)
		return 1;
	int f = 1;
	int i;
	for (i = 2; i <= n; i++)
		f *= i;
	return f;
}

//主函数
int main()
{
	printf("%d\n", factorial(10));
	printf("%d\n", factorial_iter(10));
	return 0;
}