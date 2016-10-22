#include <stdio.h>
#include <stdlib.h>

//输出数组里的数
void print(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);;
	printf("\n");
}

//返回数组里的最大值
int max(int nums[], int n)
{
	int mx = nums[0];
	int i;
	for (i = 1; i < n; i++)
		if (nums[i] > mx)
			mx = nums[i];
	return mx;
}

//计数排序（参考counting_sort.c文件）
void radix_counting_sort(int nums[], int n, int exp, int radix)
{
	int *output = (int *)malloc(sizeof(int) * n);
	//这里最大数和最小的数的范围(+1)就是基底
	//比如0-9的数的范围为10
	int *count = (int *)malloc(sizeof(int) * radix);
	
	int i;
	for (i = 0; i < radix; i++)
		count[i] = 0;

	//比如nums[i]为12345，exp为100,radix是10
	//nums[i]/exp%radix就是nums[i]的百位上的数（3）
	for (i = 0; i < n; i++)
		count[(nums[i] / exp) % radix]++;

	for (i = 1; i < radix; i++)
		count[i] += count[i - 1];

	//注意这里倒着循环，是因为一样大的数排序之后相互位置会颠倒
	//比如34和31，第一次是比较4和1，那么31排在34前边
	//然后比较3和3，如果从前往后循环会变成34,31
	//所以需要倒着循环
	for (i = n - 1; i >= 0; i--)
	{
		int num = nums[i];
		output[count[(num / exp) % radix] - 1] = nums[i];
		count[(num / exp) % radix]--;
	}

	for (i = 0; i < n; i++)
		nums[i] = output[i];
}

void radix_sort(int nums[], int n)
{
	int radix = 10;
	int mx = max(nums, n);

	//从最低位开始计数排序直到最高位
	int exp;
	for (exp = 1; mx / exp > 0; exp *= radix)
		radix_counting_sort(nums, n, exp, radix);
}

int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);

	radix_sort(nums, n);
	print(nums, n);
	return 0;
}