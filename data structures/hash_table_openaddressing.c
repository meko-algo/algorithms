#include <stdio.h>
#include <stdlib.h>

//哈希表大小
#define MAX_SIZE 20
#define EMPTY -1
#define OCCUPIED -2
#define DELETED	-3

//初始化哈希表为数组
int hash_table[MAX_SIZE];
//哈希表的实际大小(存的数的个数)
int size = 0;

//哈希函数
int hash(int val)
{
    return val % MAX_SIZE;
}

//查看val是否在哈希表中
int search(int val)
{
    //计算val的哈希值
    int hash_code = hash(val);

    //如果hash_table[i]没有存值，则返回0
    //如果hash_table[i]等于val，则返回1
    //如果hash_table[i]不等于val，则继续查看下一位
    int i;
    for (i = hash_code; i < hash_code + MAX_SIZE; i = (i + 1) % MAX_SIZE)
    {
        if (hash_table[i] == EMPTY)
            return 0;
        if (hash_table[i] == val)
            return 1;
    }

    return 0;
}

//插入一个数
void insert(int val)
{
    //如果哈希表已满，则直接返回
    if (size == MAX_SIZE)
    {
        printf("hash table is full\n");
        return;
    }

    //计算val的哈希值
    int hash_code = hash(val);

    //如果hash_table[i]没有存值，则存放val
    //如果hash_table[i]有值，则存放在后边第一个没有存值得地方（可以循环到前边）
    int i = hash_code;
    while (hash_table[i] == OCCUPIED)
        i = (i + 1) % MAX_SIZE;
    hash_table[i] = val;

    //哈希表大小加1
    size++;
}

int del(int val)
{
    //计算val的哈希值
    int hash_code = hash(val);

    //如果hash_table[i]没有存值，则返回0
    //如果hash_table[i]等于val，则将其值置为-1（等效于删除）
    //如果hash_table[i]不等于val，则继续比较下一位
    int i;
    for (i = hash_code; i < hash_code + MAX_SIZE; i = (i + 1) % MAX_SIZE)
    {
        if (hash_table[i] == EMPTY)
            return 0;
        if (hash_table[i] == val)
        {
            hash_table[i] = DELETED;
            size--;
            return 1;
        }
    }

    return 0;
}

//输出哈希表
void print(int hash_table[])
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
        if (hash_table[i] != OCCUPIED)
            printf("X ");
        else
            printf("%d ", hash_table[i]);
    printf("\n");
}

//主函数
int main()
{
    //将哈希表全置为-1
    memset(hash_table, EMPTY, MAX_SIZE * sizeof(int));

    insert(1);
    insert(2);
    insert(42);
    insert(4);
    insert(12);
    insert(14);
    insert(17);
    insert(13);
    insert(37);

    print(hash_table);

    int found = search(37);
    if (found)
        printf("37 found\n");
    else
        printf("37 not found\n");

    del(37);
    found = search(37);
    if (found)
        printf("37 found\n");
    else
        printf("37 not found\n");

    return 0;
}
