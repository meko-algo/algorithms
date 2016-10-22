#include <stdio.h>

//输出数组里的数
void print(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);;
	printf("\n");
}

//插入排序
void insertion_sort(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		int key = nums[i]; //记录下一个要插入的数
		
		int j = i - 1;
		while (j >= 0 && nums[j] > key)
		{
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
}

//主函数
int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	insertion_sort(nums, n);
	print(nums, n);

	return 0;
}