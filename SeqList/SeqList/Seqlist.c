#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//ʵ��˳�����

//��ʼ��
void SLInit(SL* ps)
{
	assert(ps);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//����
void SLDestroy(SL* ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->size = 0;
}
//��ӡ
void SLPrint(SL s)
{
	for (int i = 0; i < s.size; i++)
	{
		printf("%d ", *(s.arr + i));
	}
	printf("\n");
}
//����Ƿ�ռ��㹻
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//���ռ�Ϊ0��������ռ��СΪ4������Ϊ�㣬��ռ��С����
		int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, sizeof(SLDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("realloc");
		}
		ps->arr = tmp;
		ps->capacity = NewCapacity;
	}
}
//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size++] = x;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}
//βɾ
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}
//ͷɾ
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size++;
}
//ָ��λ��֮ǰ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//ָ��λ��֮ǰɾ��
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//����ĳԪ��
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			printf("�ҵ�%d�����±�Ϊ%d\n", x, i);
			return i;
		}
	}
	printf("û���ҵ�%d\n",x);
	return -1;
}