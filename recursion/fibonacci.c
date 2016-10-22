#include <stdio.h>

//斐波那契数列
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ...

//递归方法
int fibonacci(int n)
{
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

//循环方法
int fibonacci_iter(int n)
{
	if (n <= 1)
		return n;

	int prior1 = 0, prior2 = 1;
	int i;
	for (i = 2; i <= n; i++)
	{
		int tmp = prior2;
		prior2 = prior2 + prior1;
		prior1 = tmp;
	}
	return prior2;
}

//主函数
int main()
{
	printf("%d\n", fibonacci(10));
	printf("%d\n", fibonacci_iter(10));
	return 0;
}