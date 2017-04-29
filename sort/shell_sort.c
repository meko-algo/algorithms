#include <stdio.h>

void print(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);;
	printf("\n");
}

void shell_sort(int nums[], int n)
{
	int gap;
	for (gap = n/2; gap > 0; gap /= 2)
	{
		int i;
		for (i = gap; i < n; i += 1)
		{
			int key = nums[i];
			int j = i;
			while (j >= gap && nums[j - gap] > key)
			{
				nums[j] = nums[j - gap];
				j -= gap;
			}
			nums[j] = key;
		}
	}
}

int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);

	shell_sort(nums, n);
	print(nums, n);

	return 0;
}
