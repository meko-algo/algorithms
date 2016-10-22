#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//定义队列数据类型
typedef struct queue
{
	int data[MAX_SIZE]; //队列存储空间
	int front; //队首
	int rear;  //队尾
} *queue;

//新建队列
queue create()
{
	queue q = (queue)malloc(sizeof(struct queue));
	q->front = 0;
	q->rear = 0;
	return q;
}

//返回队列大小
int size(queue q)
{
	return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

//队列是否为空
int is_empty(queue q)
{
	return q->front == q->rear;
}

//队列是否已满
int is_full(queue q)
{
	return (q->rear + 1) % MAX_SIZE == q->front;
}

//进队列
int enqueue(queue q, int x)
{
	if (is_full(q))
	{
		printf("Error: queue is full\n");
		return 0;
	}
	else
	{
		q->data[q->rear] = x;
		q->rear = (q->rear + 1) % MAX_SIZE;
		return 1;
	}
}

//出队列
int dequeue(queue q)
{
	if (is_empty(q))
	{
		printf("Error: queue is empty\n");
	}
	else
	{
		int head = q->data[q->front];
		q->front = (q->front + 1) % MAX_SIZE;
		return head;
	}
}

//输出队列内元素
void print(queue q)
{
	int i;
	for (i = q->front; i != q->rear; i=(i+1)%MAX_SIZE)
		printf("%d ", q->data[i]);
	printf("\n");
}

//主函数
int main()
{
	queue q = create();
	enqueue(q, 2);	print(q);
	enqueue(q, 4);	print(q);
	enqueue(q, 6);	print(q);
	dequeue(q);		print(q);
	enqueue(q, 8);	print(q);

	return 0;
}