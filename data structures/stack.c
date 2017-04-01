#include <stdio.h>
#include <stdlib.h>

//定义栈数据类型
typedef struct stack
{
	int *data;
	int top;
	int max_size;
} *stack;

//新建栈
stack create(int size)
{
	if (size <= 0) 	return NULL;

	stack s = (stack)malloc(sizeof(struct stack));
	s->data = (int *)malloc(sizeof(int) * size);
	s->top = 0;
	s->max_size = size;
	return s;
}

//销毁栈
void destory(stack s)
{
	free(s->data);
	free(s);
}

//进栈
void push(stack s, int val)
{
	if (s->top == s->max_size)
		printf("Stack's underlying storage is overflow");
	else
		s->data[s->top++] = val;
}

//取栈顶的数（不出栈）
int peek(stack s)
{
	if (s->top == 0)
		printf("Stack is empty");
	else
		return s->data[s->top - 1];
}

//出栈
int pop(stack s)
{
	if (s->top == 0)
		printf("Stack is empty");
	else
		return s->data[--s->top];
}

//栈是否为空
int is_empty(stack s)
{
	return s->top == 0;
}

//输出栈内元素
void print(stack s)
{
	int i;
	for (i = 0; i != s->top; i++)
		printf("%d ", s->data[i]);
	printf("\n");
}

//主函数
int main()
{
	stack s = create(20);
	push(s, 2);	print(s);
	push(s, 4);	print(s);
	push(s, 6);	print(s);
	pop(s);		print(s);
	push(s, 8);	print(s);

	return 0;
}
