#include <stdio.h>

//输出数组里的数
void print(int nums[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", nums[i]);;
	printf("\n");
}

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

//堆化操作（把结点i下沉到适当的位置）-- 递归函数
void heapify(int nums[], int n, int i)
{
	//递归结束条件i比左右孩子都大或者i是叶子结点

	int largest = i;
	int l = 2 * i + 1; //左孩子
	int r = 2 * i + 2; //右孩子

	//如果左右孩子有一个比父结点i大，那么就把孩子结点赋给largest
	if (l < n && nums[l] > nums[largest])
		largest = l;
	if (r < n && nums[r] > nums[largest])
		largest = r;

	//largest不等于i说明左右孩子至少有一个比i大或者i是叶子结点
	if (largest != i)
	{
		swap(&nums[i], &nums[largest]); //交换父结点i和大的那个孩子结点
		heapify(nums, n, largest); //继续向下沉
	}
}

//堆排序
void heap_sort(int nums[], int n)
{
	//把原始数组建成一个大顶堆（从最后一个非叶子结点开始堆化操作）
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		heapify(nums, n, i);
	
	//把最大得数（堆顶）交换到数组最后，
	//再把交换之后的堆顶进行堆化操作，
	//然后把堆的大小减1（数组实际大小没变）
	for (i = n - 1; i >= 0; i--)
	{
		swap(&nums[0], &nums[i]);
		heapify(nums, i, 0);
	}
}

//主函数
int main()
{
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	heap_sort(nums, n);
	print(nums, n);

	return 0;
}