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

//返回数组里的最小值
int min(int nums[], int n)
{
	int mn = nums[0];
	int i;
	for (i = 1; i < n; i++)
		if (nums[i] < mn)
			mn = nums[i];
	return mn;
}

void counting_sort(int nums[], int n)
{
	//计算数组里最大值和最小值的差距
	int high = max(nums, n);
	int low = min(nums, n);
	int size = high - low + 1;
	
	//新建一个用来存储数组里边所有元素的数组
	int *output = (int *)malloc(sizeof(int) * n);
	//新建一个存储min到max之间的数字的出现次数的数组
	int *count = (int *)malloc(sizeof(int) * size);

	//初始化计数器为0
	int i;
	for (i = 0; i < size; i++)
		count[i] = 0;

	//计数
	for (i = 0; i < n; i++)
		count[nums[i] - low]++;

	//计数数组内的每一个元素的值替换成前面所有数的与自己的和
	for (i = 1; i < size; i++)
		count[i] += count[i - 1];

	//把原始数组的每一个元素的放到output数组的正确位置
	for (i = 0; i < n; i++)
	{
		//第i个元素
		int num = nums[i];
		//第i个元素应该在output数组的位置
		int pos = count[num - low] - 1;
		//将这个元素复制到output数组对应位置
		output[pos] = nums[i];
		//这个数对应的计数器减1
		count[num - low]--;
	}

	//将排好序的output数组再复制回原数组里
	for (i = 0; i < n; i++)
		nums[i] = output[i];
}

int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);

	counting_sort(nums, n);
	print(nums, n);
	return 0;
}