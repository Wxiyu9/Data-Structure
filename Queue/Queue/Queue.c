#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

// ��ʼ������
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}

// ����ڵ�
QNode* QListBuyNode(QDataType x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* newNode = QListBuyNode(data);
	if (q->size == 0)
	{
		q->_front = q->_rear = newNode;
	}
	else {
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
	q->size++;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q && q->size);
	if (q->size == 1)
	{
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else {
		QNode* PopNode = q->_front;
		q->_front = q->_front->_next;
		free(PopNode);
		PopNode = NULL;
	}
	q->size--;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q && q->size);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q && q->size);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ��
// ���Ϊ�շ��ط�����
// ����ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->size == 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_front) {
		QueuePop(q);
	}
	q->_front = NULL;
	q->_rear = NULL;
}

