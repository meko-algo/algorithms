#include <stdio.h>

int _binary_search(int nums[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = (l + r) / 2;

		if (nums[mid] == x)
			return mid;
		else if (nums[mid] > x)
			return _binary_search(nums, l, mid - 1, x);
		else
			return _binary_search(nums, mid + 1, r, x);
	}
	return -1;
}

int binary_search(int nums[], int n, int x)
{
	return _binary_search(nums, 0, n - 1, x);
}

int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);

	printf("%d\n", binary_search(nums, n, 14));

	return 0;
}