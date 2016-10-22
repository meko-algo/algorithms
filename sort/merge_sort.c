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

//归并排序--归并操作
void merge(int nums[], int l, int m, int r)
{
    int i, j;

    int n1 = m - l + 1; //左子数组的长度
    int n2 = r - m;     //右子数组的长度

    //新建两个新数组（数组大小是变量所以用new动态分配）
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
 
    //把原数组的数拷贝到两个小数组L, R里
    for (i = 0; i < n1; i++)
        L[i] = nums[l + i];
    for (i = 0; i < n2; i++)
        R[i] = nums[m + 1 + i];
    
    //把小数组的数按从小到大的顺序放回原数组
    i = j = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            nums[l + i + j] = L[i];
            i++;
        }
        else
        {
            nums[l + i + j] = R[j];
            j++;
        }
    }
    while (i < n1)
    {
        nums[l + i + j] = L[i];
        i++;
    }
    while (j < n2)
    {
        nums[l + i + j] = R[j];
        j++;
    }

    //释放动态分配的空间
    free(L);
    free(R);
}

//归并排序函数（需指定左右边界）-- 递归函数
void _merge_sort(int nums[], int l, int r)
{
    //递归结束条件l = r (l不会大于r)
    //这里l = r就不会进入if，所以就不会往下递归了
    if (l < r)
    {
        int m = (l + r) / 2; //中间数的下标
        _merge_sort(nums, l, m); //排序左子数组
        _merge_sort(nums, m+1, r);//排序右子数组
        merge(nums, l, m, r);//排序好的左右子数组合并
    }
}

//归并排序函数
void merge_sort(int nums[], int n)
{
    _merge_sort(nums, 0, n - 1);
}

//主函数
int main()
{
    int nums[] = { 2, 10, 3, 14, 15, 6, 3, 9 };
    int n = sizeof(nums) / sizeof(nums[0]);
    
    merge_sort(nums, n);
    print(nums, n);
    
    return 0;
}