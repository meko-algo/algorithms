#include <stdio.h>
#include <stdlib.h>

//定义结点和链表数据类型
typedef struct node
{
   int data;
   struct node *prev, *next;
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
   int list_size = size(head);
   if (pos > list_size)
      return head;
   
   //新建一个结点
   node *new_node = (node *)malloc(sizeof(node));
   new_node->data = val;

   new_node->next = NULL;
   
   //表头插入结点的情况
   if (pos == 0)
   {
      new_node->prev = NULL;
      new_node->next = head;
      head->prev = new_node;
      return new_node;
   }

   //找到插入位置前一个结点
   node *prev_node = head;
   int i;
   for (i = 0; i < pos - 1; i++)
      prev_node = prev_node->next;
   
   //双向链表的插入操作
   new_node->next = prev_node->next;
   new_node->prev = prev_node;
   if (pos != list_size) //新结点插在链表最后的时候pre_node->next为空
      prev_node->next->prev = new_node;
   prev_node->next = new_node;

   //返回链表
   return head;
}

//链表尾部插入一个数
list insert_last(list head, int val)
{
   //新建结点
   node *new_node = (node *)malloc(sizeof(node));
   new_node->data = val;
   new_node->prev = NULL;
   new_node->next = NULL;

   //链表为空的情况
   if (head == NULL)
      return new_node;

   //链表最后插入结点
   node *last_node = head;
   while (last_node->next)
      last_node = last_node->next;
   new_node->prev = last_node;
   last_node->next = new_node;
   
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
   int list_size = size(head);
   if (pos >= list_size)
      return head;

   //删除表头的情况
   if (pos == 0)
   {
      node *tmp = head;
      head = head->next;
      head->prev = NULL;
      free(tmp);
      return head;
   }

   //指定位置删除结点
   node *prev_node = head;
   int i;
   for (i = 0; i < pos - 1; i++)
      prev_node = prev_node->next;

   node *tmp = prev_node->next;
   if (pos != list_size - 1) //要删除的结点在链表最后的时候tmp->next为空
      tmp->next->prev = prev_node;
   prev_node->next = tmp->next;
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
   l = insert_last(l, 2);  print(l);
   l = insert(l, 4, 0); print(l);
   l = insert(l, 6, 1); print(l);
   l = del(l, 1);       print(l);
   l = insert_last(l, 8);  print(l);

   return 0;
}