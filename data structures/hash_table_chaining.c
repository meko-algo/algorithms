#include <stdio.h>
#include <stdlib.h>

//哈希表大小
#define MAX_SIZE 20

//定义链表
typedef struct node
{
	int key;
	char *name[20];
	struct node *next;
} node, *list;

//初始化哈希表
list hash_table[MAX_SIZE];

//哈希函数
int hash(int key) 
{
    return key % MAX_SIZE;
}

//使用key在哈希表中查找
node* search(int key) 
{
	//计算key的哈希值
	int hash_code = hash(key);

	//在hash_code对应的链表进行线性查找
	node *p = hash_table[hash_code];
	while (p != NULL)
	{
		if (p->key == key)
			return p;
		p = p->next;
	}

	//如果没有找到则返回NULL
	return NULL;
}

//插入一个值
void insert(int key, char *name)
{
	//计算key的哈希值
	int hash_code = hash(key);

	//新建一个node
	node *new_node = (node*)malloc(sizeof(node));
	new_node->key = key;
	strcpy(new_node->name, name);
	new_node->next = NULL;

	//将新建的node插入hash_code对应链表的最后
	node *p = hash_table[hash_code];
	if (p == NULL)
	{
		hash_table[hash_code] = new_node;
		return;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new_node;
}

int del(int key)
{
	//计算key的哈希值
	int hash_code = hash(key);

	node *p = hash_table[hash_code];
	//如果hash_code对应链表为空，直接返回0
	if (p == NULL)
		return 0;
	//如果hash_code对应链表表头为删除对象，则删除表头
	if (p->key == key)
	{
		hash_table[hash_code] = p->next;
		free(p);
		return 1;
	}
	//删除链表中key一致的结点
	node *prev = p;
	p = p->next;
	while (p != NULL)
	{
		if (p->key == key)
		{
			prev->next = p->next;
			free(p);
			return 1;
		}
		prev = p;
		p = p->next;
	}

	//如果没有找到则返回0
	return 0;
}

//输出哈希表
void print()
{
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		node *p = hash_table[i];
		if (p == NULL)
		{
			printf("X\n");
		}
		else
		{
			while (p != NULL)
			{
				printf("(%d,%s) ", p->key, p->name);
				p = p->next;
			}
			printf("\n");
		}
	}
}

//主函数
int main() 
{
    insert(1, "tokyo");
    insert(2, "osaka");
    insert(42, "kyoto");
    insert(4, "nagoya");
    insert(12, "yokohama");
    insert(14, "chiba");
    insert(17, "sendai");
    insert(13, "hokkaido");
    insert(37, "okinawa");

    print(hash_table);

    node *found = search(37);
    if (found)
        printf("37 is %s\n", found->name);
    else
        printf("37 not found\n");

    del(37);
    found = search(37);
    if (found)
        printf("37 is %s\n", found->name);
    else
        printf("37 not found\n");

    return 0;
}