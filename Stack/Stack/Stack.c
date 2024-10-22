#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//初始化栈
void StackInit(Stack* ps) {
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

//检查空间是否足够
void CheckCapacity(Stack* ps)
{
	if (ps->_top == ps->_capacity)
	{
		int NewCapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
		STDataType* NewA = (STDataType*)realloc(ps->_a, sizeof(STDataType) * NewCapacity);
		if (NewA == NULL)
		{
			perror("realloc fail");
		}
		ps->_capacity = NewCapacity;
		ps->_a = NewA;
	}
}

//入栈
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	CheckCapacity(ps);
	*(ps->_a + ps->_top) = data;
	ps->_top++;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return *(ps->_a + ps->_top - 1);
}

//获取栈中有效元素个数
int StatckSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

//检测栈是否为空，若为空则返回非零结果
//若不为空则返回0
int StackEmpty(Stack* ps) {
	return ps->_top == 0;
}

//输出栈
void PrintStack(Stack* ps)
{
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", *(ps->_a + i));
	}
	printf("\n");
}




//销毁栈
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}