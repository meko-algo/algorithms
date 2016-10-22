#include <stdio.h>

//交换两个数
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//输出数组里的数
void print(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);;
	printf("\n");
}

//分割函数（找一个pivot，把小于等于pivot的放左边，大于pivot的放右边）
int partition(int nums[], int l, int r)
{
	//pivot是用来比较的数，可以随便选一个，这里选的是最后一个
	int pivot = nums[r];
	int i = l;
	
	//小于等于pivot的放到左边，大于pivot的放到右边
	int j;
	for (j = l; j <= r - 1; j++)
	{
		if (nums[j] <= pivot)
		{
			swap(&nums[i], &nums[j]);
			i++;
		}
	}

	//把pivot放到小于等于它的最后一个数的后边（交换之前pivot还在最后）
	swap(&nums[i], &nums[r]);
	
	//放回最后pivot的位置
	return i;
}

//快速排序（需指定左右边界）-- 递归函数
void _quick_sort(int nums[], int l, int r)
{
	//递归结束条件l = r (l不会大于r)
	//这里l = r就不会进入if，所以就不会往下递归了
	if (l < r)
	{
		int pi = partition(nums, l, r); //分割
		_quick_sort(nums, l, pi - 1); //对左边继续排序
		_quick_sort(nums, pi + 1, r); //对右边继续排序
	}
}

//快速排序
void quick_sort(int nums[], int n)
{
	_quick_sort(nums, 0, n - 1);
}

//主函数
int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	quick_sort(nums, n);
	print(nums, n);

	return 0;
}