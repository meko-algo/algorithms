#include <stdio.h>
#include <stdlib.h>

//定义结点和链表数据类型
typedef struct node
{
	int data;
	struct node *next;
} node, *list;

//返回链表的长度
int size(list head)
{
	int i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}

	return i;
}

//在链表的指定位置插入一个数
list insert(list head, int val, int pos)
{
	//指定的位置超出范围直接返回
	if (pos > size(head))
		return head;

	//新建一个结点
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = val;

	//表头插入结点的情况
	if (pos == 0)
	{
		new_node->next = head;
		return new_node;
	}

	//指定位置插入结点
	node *pre = head;
	int i;
	for (i = 1; i < pos; i++) //也可以是 (i = 0; i < pos - 1; i++) 
		pre = pre->next;
	new_node->next = pre->next;
	pre->next = new_node;

	//返回链表
	return head;
}

//链表尾部插入一个数
list insert_last(list head, int val)
{
	//新建结点
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = val;
	new_node->next = NULL;

	//链表为空的情况
	if (head == NULL)
		return new_node;

	//链表最后插入结点
	node *last = head;
	while (last->next)
		last = last->next;
	last->next = new_node;

	//返回链表
	return head;
}

node *search(list head, int val)
{
	while (head != NULL)
	{
		if (head->data == val)
			return head;
		else
			head = head->next;
	}

	return NULL;
}

//链表指定位置删除结点
list del(list head, int pos)
{
	//指定位置超出范围直接返回
	if (pos >= size(head))
		return head;

	//删除表头的情况
	if (pos == 0)
	{
		node *tmp = head;
		head = head->next;
		free(tmp);
		return head;
	}

	//指定位置删除结点
	node *pre = head;
	int i;
	for (i = 1; i < pos; i++) //也可以是 (i = 0; i < pos - 1; i++)
		pre = pre->next;
	node *tmp = pre->next;
	pre->next = tmp->next;
	free(tmp);

	//返回链表
	return head;
}

//输出链表
void print(list head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

//销毁链表
void destroy(list head)
{
	while (head)
	{
		node *tmp = head;
		head = head->next;
		free(tmp);
	}
}

//主函数
int main()
{
	list l = NULL;
	l = insert_last(l, 2);	print(l);
	l = insert(l, 4, 0);	print(l);
	l = insert(l, 6, 1);	print(l);
	l = del(l, 1);			print(l);
	l = insert_last(l, 8);	print(l);

	return 0;
}
