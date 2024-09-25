#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������������
typedef int SLTDataType;

//��������ṹ��
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//����ռ�
SLTNode* SLTBuyNode(SLTDataType x)
{
	SLTNode* NewNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (NewNode == NULL)
	{
		perror("malloc");
		exit(1);
	}
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

//��ӡ
void SLTPrint(SLTNode* phead)
{
	SLTNode* temp = phead;
	while (temp)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

//��ӡ�˵�
void emnu()
{
	printf("***************************************\n");
	printf("******  1.��ӡ����   2.��������  ******\n");
	printf("******  3.ͷ������   4.β������  ******\n");
	printf("******  5.ͷɾ����   6.βɾ����  ******\n");
	printf("******    7.ָ������ɾ���ڵ�     ******\n");
	printf("******   8.ָ������ǰ����ڵ�    ******\n");
	printf("******         0.�˳�����        ******\n");
	printf("***************************************\n");
}

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* NewNode = SLTBuyNode(x);
	if (*pphead == NULL)
		*pphead = NewNode;
	else
	{
		SLTNode* cur = *pphead;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}

}

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* NewHead = SLTBuyNode(x);
	NewHead->next = *pphead;
	*pphead = NewHead;
}

//βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* pcur1 = *pphead;
		SLTNode* pcur2 = *pphead;
		while (pcur1->next)
		{
			pcur2 = pcur1;
			pcur1 = pcur1->next;
		}
		pcur2->next = NULL;
		free(pcur1);
		pcur1 = NULL;
	}

}

//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead && pos && *pphead);
	if (pos == *pphead)
		SLTPushFront(pphead,x);
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		SLTNode* NewNode = SLTBuyNode(x);
		pcur->next = NewNode;
		NewNode->next = pos;
	}
}

//ɾ��pos�ڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead && pos);
	if (*pphead == pos)
		SLTPopFront(pphead);
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
			pcur = pcur->next;
		pcur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//��������
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* temp = pcur->next;
		free(pcur);
		pcur = temp;
	}
}


int main()
{
	SLTNode* phead = NULL;
	int input = 0;
	int n = 0;
	int b = 0;
	do {
		emnu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			SLTPrint(phead);
			break;
		case 2:
			SListDesTroy(&phead);
			break;
		case 3:
			n = 0;
			printf("������Ҫ��������ݣ�");
			scanf("%d", &n);
			SLTPushFront(&phead, n);
			printf("����ɹ���\n");
			break;
		case 4:
			n = 0;
			printf("������Ҫ��������ݣ�");
			scanf("%d", &n);
			SLTPushBack(&phead, n);
			printf("����ɹ���\n");
			break;
		case 5:
			SLTPopFront(&phead);
			printf("ɾ���ɹ���\n");
			break;
		case 6:
			SLTPopBack(&phead);
			printf("ɾ���ɹ���\n");
			break;
		case 8:
			n = 0;
			b = 0;
			printf("�����������λ�ýڵ�����ݣ�");
			scanf("%d", &b);
			printf("������Ҫ��������ݣ�");
			scanf("%d", &n);
			SLTNode* FindPush = SLTFind(phead, b);
			if (FindPush == NULL)
				printf("�ýڵ㲻����\n");
			else
				SLTInsert(&phead, FindPush, n);
			break;
		case 7:
			b = 0;
			printf("�������ɾ��λ�ýڵ�����ݣ�");
			scanf("%d", &b);
			SLTNode* FindPop = SLTFind(phead, b);
			if (FindPop == NULL)
				printf("�ýڵ㲻����\n");
			else
				SLTErase(&phead, FindPop);
			break;
		case 0:
			printf("�����˳�...\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}