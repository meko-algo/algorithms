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

//冒泡排序
void bubble_sort(int nums[], int n)
{
	//i: 已排好序的数的个数
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 1; j < n - i; j++)
			if (nums[j] < nums[j - 1])
				swap(&nums[j], &nums[j - 1]);
}

//主函数
int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	bubble_sort(nums, n);
	print(nums, n);

	return 0;
}