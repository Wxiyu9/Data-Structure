#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

int state = 0;
// 0 未初始化
// 1 已初始化
// 2 已销毁

bool Check()
{
	if (state == 1)
	{
		return true;
	}
	else if (state == 0)
	{
		printf("未初始化，操作不合法\n");
	}
	else {
		printf("已销毁，操作不合法\n");
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
			// 女生放在队列B中
			QueuePush(B, temp);
		}
		else {
			// 男生放在队列C中
			QueuePush(C, temp);
		}
		QueuePop(A);
	}
}


void PrintMenu() {
	printf("*****************************\n");
	printf("**       1.初始化队列      **\n");
	printf("**       2.销毁队列        **\n");
	printf("**       3.清空队列        **\n");
	printf("**       4.队列判空        **\n");
	printf("**       5.求队列长度      **\n");
	printf("**       6.获取队头元素    **\n");
	printf("**       7.插入一个元素    **\n");
	printf("**       8.删除一个元素    **\n");
	printf("**       9.输出所有元素    **\n");
	printf("**       10.重新排队       **\n");
	printf("**       11.退出程序       **\n");
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
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			QueueInit(&q);
			printf("初始化成功\n");
			state = 1;
			break;
		case 2:
			if (Check()) {
				QueueDestory(&q);
				printf("销毁成功\n");
				state = 2;
			}
			break;
		case 3:
			if (Check()) {
				QueueClear(&q);
				printf("清空成功\n");
			}
			break;
		case 4:
			if (Check()) {
				if (QueueEmpty(&q)) {
					printf("队列为空\n");
				}
				else {
					printf("队列不为空\n");
				}
			}
			break;
		case 5:
			if (Check()) {
				printf("队列长度为：%d\n", QueueSize(&q));
			}
			break;
		case 6:
			if (Check()) {
				printf("队头元素为：%d\n", QueueFront(&q));
			}
			break;
		case 7:
			if (Check()) {
				printf("请输入待插入元素：");
				scanf("%d", &element);
				QueuePush(&q, element);
				printf("输入成功！\n");
			}
			break;
		case 8:
			if (Check()) {
				QueuePop(&q);
				printf("删除成功\n");
			}
			break;
		case 9:
			if (Check()) {
				printf("队列元素为：");
				QueuePrint(&q);
			}
			break;
		case 10:
			QueueInit(&A);
			QueueInit(&B);
			QueueInit(&C);
			printf("请输入男女生分布：");
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
			printf("女生队列元素为：");
			QueuePrint(&B);
			printf("男生队列元素为：");
			QueuePrint(&C);
			break;
		case 11:
			printf("程序退出\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
		} while (input != 11);
	return 0;
}