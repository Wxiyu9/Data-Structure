#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int state = 0;
// 0 δ��ʼ��
// 1 �ѳ�ʼ��
// 2 ������

bool Check()
{
	if (state == 1)
	{
		return true;
	}
	else if (state == 0)
	{
		printf("δ��ʼ�����������Ϸ�\n");
	}
	else {
		printf("�����٣��������Ϸ�\n");
	}
	return false;
}

typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;

	//size_t size;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueueClear(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		cur->data = 0;
		cur = cur->next;
	}
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		assert(pq->head == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//return pq->head == NULL && pq->tail == NULL;
	return pq->head == NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}
void QueuePrint(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void Rearrange(Queue* A, Queue* B, Queue* C) {
	QDataType temp = 0;
	while (!QueueEmpty(A)) {
		temp = QueueFront(A);
		if (temp % 2 == 0)
		{
			// Ů�����ڶ���B��
			QueuePush(B, temp);
		}
		else {
			// �������ڶ���C��
			QueuePush(C, temp);
		}
		QueuePop(A);
	}
}


void PrintMenu() {
	printf("*****************************\n");
	printf("**       1.��ʼ������      **\n");
	printf("**       2.���ٶ���        **\n");
	printf("**       3.��ն���        **\n");
	printf("**       4.�����п�        **\n");
	printf("**       5.����г���      **\n");
	printf("**       6.��ȡ��ͷԪ��    **\n");
	printf("**       7.����һ��Ԫ��    **\n");
	printf("**       8.ɾ��һ��Ԫ��    **\n");
	printf("**       9.�������Ԫ��    **\n");
	printf("**       10.�����Ŷ�       **\n");
	printf("**       11.�˳�����       **\n");
	printf("*****************************\n");
}

int main()
{
	PrintMenu();
	Queue q;
	Queue A, B, C;
	QDataType element = 0;
	int input = 0;
	do {
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			QueueInit(&q);
			printf("��ʼ���ɹ�\n");
			state = 1;
			break;
		case 2:
			if (Check()) {
				QueueDestory(&q);
				printf("���ٳɹ�\n");
				state = 2;
			}
			break;
		case 3:
			if (Check()) {
				QueueClear(&q);
				printf("��ճɹ�\n");
			}
			break;
		case 4:
			if (Check()) {
				if (QueueEmpty(&q)) {
					printf("����Ϊ��\n");
				}
				else {
					printf("���в�Ϊ��\n");
				}
			}
			break;
		case 5:
			if (Check()) {
				printf("���г���Ϊ��%d\n", QueueSize(&q));
			}
			break;
		case 6:
			if (Check()) {
				printf("��ͷԪ��Ϊ��%d\n", QueueFront(&q));
			}
			break;
		case 7:
			if (Check()) {
				printf("�����������Ԫ�أ�");
				scanf("%d", &element);
				QueuePush(&q, element);
				printf("����ɹ���\n");
			}
			break;
		case 8:
			if (Check()) {
				QueuePop(&q);
				printf("ɾ���ɹ�\n");
			}
			break;
		case 9:
			if (Check()) {
				printf("����Ԫ��Ϊ��");
				QueuePrint(&q);
			}
			break;
		case 10:
			QueueInit(&A);
			QueueInit(&B);
			QueueInit(&C);
			printf("��������Ů���ֲ���");
			while (true) {
				scanf("%d", &element);
				if (element != -1)
				{
					QueuePush(&A, element);
				}
				else {
					break;
				}
			}
			Rearrange(&A, &B, &C);
			printf("Ů������Ԫ��Ϊ��");
			QueuePrint(&B);
			printf("��������Ԫ��Ϊ��");
			QueuePrint(&C);
			break;
		case 11:
			printf("�����˳�\n");
			break;
		default:
			printf("������������������\n");
			break;
		}
		} while (input != 11);
	return 0;
}