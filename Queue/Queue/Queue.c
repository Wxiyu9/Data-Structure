#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

// 初始化队列
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}

// 申请节点
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

// 队尾入队列
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	assert(q && q->size);
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	assert(q && q->size);
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	assert(q);
	return q->size;
}

// 检测队列是否为空
// 如果为空返回非零结果
// 如果非空返回0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->size == 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->_front) {
		QueuePop(q);
	}
	q->_front = NULL;
	q->_rear = NULL;
}

