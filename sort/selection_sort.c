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

//选择排序
void selection_sort(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		//找到最小的数的下标
		int min_idx = i;
		int j;
		for (j = i + 1; j < n; j++)
			if (nums[j] < nums[min_idx])
				min_idx = j;
		//将最小的数交换到第i个位置去
		swap(&nums[min_idx], &nums[i]);
	}
}

//主函数
int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	selection_sort(nums, n);
	print(nums, n);
	
	return 0;
}