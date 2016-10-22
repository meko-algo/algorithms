//简化版桶排序
#include <stdio.h>

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

//桶排序
void bucket_sort(int nums[], int n)
{	
	//将桶的数量设置为最小数到最大数的区间大小
	int bucket_num = max(nums, n) - min(nums, n) + 1;
    int *count_buckets = (int *)malloc(sizeof(int) *  bucket_num);
   	
   	//将桶内计数器都初始化为0
   	int i;
    for (i = 0; i < bucket_num; i++)
        count_buckets[i] = 0;
 	
 	//将原始数组内的元素放到对应桶内(桶计数器加1)
    for (i = 0; i < n; i++)
        count_buckets[nums[i]]++;
 
 	//按顺序从桶内取出来放回原数组
 	int k = 0;
 	int j;
    for (i = 0; i < bucket_num; i++)
        for(j = 0; j < count_buckets[i]; j++)
            nums[k++] = i;
}   

//主函数
int main()
{
	
	int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
	int n = sizeof(nums) / sizeof(nums[0]);
	
	bucket_sort(nums, n);
	print(nums, n);
	
	return 0;
}