#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

//��������ڵ�ṹ��
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//�˵���ӡ
void PrintMenu()
{
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*       1.��ʼ������������       *\n");
	printf("*           2.��������           *\n");
	printf("*         3.�������             *\n");
	printf("*         4.������             *\n");
	printf("*       5.ָ��λ�õ�Ԫ��ֵ       *\n");
	printf("*     6.�����Ѵ���Ԫ�ص�λ��     *\n");
	printf("*     7.������Ԫ�ص�ֱ��ǰ��     *\n");
	printf("*     8.������Ԫ�ص�ֱ�Ӻ��     *\n");
	printf("*    9.�ڵ�i��λ�ò���һ��Ԫ��   *\n");
	printf("*        10.ɾ����i��Ԫ��        *\n");
	printf("*      11.����е�����Ԫ��       *\n");
	printf("* 12.��ʼ������ͷ/β�巨����Ԫ�� *\n");
	printf("*     13.ʵ�ֵ������������    *\n");
	printf("*      14.ʵ�ֵ����������       *\n");
	printf("*         15.�˳�����             *\n");
	printf("*                                *\n");
	printf("**********************************\n");
}

//2.��������
void SListDesTroy(SListNode** pphead)
{
	assert(pphead);
	SListNode* temp = *pphead;
	while (temp)
	{
		SListNode* next = temp->next;
		free(temp);
		temp = next;
	}
	*pphead = NULL;
}

//1.��ʼ������
void InitList(SListNode** pphead)
{
	SListDesTroy(pphead);
}

//3.�������
int EmptyList(SListNode** pphead)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return 0;
	}
	SListNode* cur = *pphead;
	while (cur)
	{
		cur->data = 0;
		cur = cur->next;
	}
	return 1;
}

// 4.��������
int ListLength(SListNode* phead)
{
	int Length = 0;
	SListNode* cur = phead;
	while (cur)
	{
		Length++;
		cur = cur->next;
	}
	return Length;
}
//5.����λ��Ѱ��Ԫ��ֵ
SListNode* SLTFindElement(SListNode* phead, int location)
{
	SListNode* cur = phead;
	int times = 0;
	while (cur)
	{
		if (times == location)
			return cur;
		cur = cur->next;
		times++;
	}
	return NULL;
}

//6.����Ԫ��Ѱ��λ��
int SLTFindLocation(SListNode* phead, SLTDataType x)
{
	int location = 0;
	SListNode* cur = phead;
	while (cur)
	{
		location++;
		if (x == cur->data)
			return location;
		cur = cur->next;
	}
	return -1;//��Ԫ�ز�����
}

//����
SListNode* SLTFind(SListNode* phead, SLTDataType x)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 11.�����ӡ
void PrintList(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//�����½ڵ�
SListNode* SLTBuyNode(SLTDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
	{
		perror("malloc error");
		exit(1);
	}

	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

//����β��
void SLTPushBack(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//����ͷ��
void SLTPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//����βɾ
void SLTPopBack(SListNode** pphead)
{
	assert(*pphead && pphead);
	SListNode* cur = *pphead;
	SListNode* curpre = *pphead;
	if ((*pphead)->next == NULL)
	{
		free((*pphead));
		*pphead = NULL;
	}
	else
	{
		//1 2 3 null
		while (cur->next)
		{
			curpre = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		curpre->next = NULL;
	}
}

//����ͷɾ
void SLTPopFront(SListNode** pphead)
{
	assert(pphead && *pphead);
	SListNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}


//9.��ָ��λ��֮ǰ��������
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x)
{
	assert(pphead && pos && *pphead);
	SListNode* newNode = SLTBuyNode(x);
	if (pos == *pphead)//ͷ��
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newNode->next = pos;
		cur->next = newNode;
	}
}


//ɾ��ָ��λ�õ�����
void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SListNode* curpre = *pphead;
		while (curpre->next != pos)
		{
			curpre = curpre->next;
		}
		curpre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//ɾ��ָ��λ��֮�������
void SLTEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}



int main()
{
	SListNode* head = NULL;
	int location;
	SLTDataType element;
	PrintMenu();
	int input = 0;
	do {
		printf("��ѡ�������");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			InitList(&head);
			printf("��ʼ���ɹ���\n");
			break;
		}
		case 2:
		{
			SListDesTroy(&head);
			printf("���ٳɹ���\n");
			break;
		}
		case 3:
		{
			if (EmptyList(&head))
				printf("��ճɹ���\n");
			else
				printf("����Ϊ�ջ򴫲β��Ϸ������ʧ�ܣ�\n");
			break;
		}
		case 4:
		{
			printf("������Ϊ��%d", ListLength(head));
			break;
		}
		case 5:
		{
			printf("������Ҫ���ҵ�λ�ã�");
			scanf("%d", &location);
			SListNode* temp = SLTFindElement(head, location);
			if (temp == NULL)
			{
				printf("λ�ò��Ϸ���\n");
			}
			else {
				printf("��λ�õ�Ԫ��Ϊ��%d ", temp->data);
			}
			break;
		}
		case 6:
		{
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &element);
			int temp = SLTFindLocation(head, element);
			if (temp == -1)
				printf("��Ԫ�ز�����\n");
			else
				printf("��Ԫ��Ϊ��%d���ڵ�\n", temp);
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			printf("�����������λ�ã�");
			scanf("%d", &location);
			if(location == 1)
			SListNode* temp = SLTFindElement(head, location-1);
			if (temp == NULL)
			{
				printf("λ�ò��Ϸ���\n");
				break;
			}
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			SLTInsert(&head, temp, element);
			printf("����ɹ���\n");
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			PrintList(head);
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
			break;
		}
		default:
		{

		}
		}
	} while (input != 15);
	return 0;
}