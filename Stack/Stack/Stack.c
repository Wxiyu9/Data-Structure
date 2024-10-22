#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

//��ʼ��ջ
void StackInit(Stack* ps) {
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

//���ռ��Ƿ��㹻
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

//��ջ
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	CheckCapacity(ps);
	*(ps->_a + ps->_top) = data;
	ps->_top++;
}

//��ջ
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return *(ps->_a + ps->_top - 1);
}

//��ȡջ����ЧԪ�ظ���
int StatckSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

//���ջ�Ƿ�Ϊ�գ���Ϊ���򷵻ط�����
//����Ϊ���򷵻�0
int StackEmpty(Stack* ps) {
	return ps->_top == 0;
}

//���ջ
void PrintStack(Stack* ps)
{
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", *(ps->_a + i));
	}
	printf("\n");
}




//����ջ
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}