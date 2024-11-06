#define _CRT_SECURE_NO_WARNINGS 1
//225.用队列实现栈

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;



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

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);


typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

MyStack* myStackCreate() {
	MyStack* s = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(s->q1));
	QueueInit(&(s->q2));
	return s;
}

void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&(obj->q1)))//q1为空
	{
		QueuePush(&(obj->q2), x);
	}
	else {
		QueuePush(&(obj->q1), x);
	}
}

int myStackPop(MyStack* obj) {
	if (QueueEmpty(&(obj->q1))) {
		while (QueueSize(&(obj->q2)) != 1) {
			int x = QueueFront(&(obj->q2));
			QueuePush(&(obj->q1), x);
			QueuePop(&(obj->q2));
		}
		int y = QueueBack(&(obj->q2));
		QueuePop(&(obj->q2));
		return y;
	}
	else {
		while (QueueSize(&(obj->q1)) != 1) {
			int x = QueueFront(&(obj->q1));
			QueuePush(&(obj->q2), x);
			QueuePop(&(obj->q1));
		}
		int y = QueueBack(&(obj->q1));
		QueuePop(&(obj->q1));
		return y;
	}
}

int myStackTop(MyStack* obj) {
	if (QueueEmpty(&(obj->q1))) {
		return QueueBack(&(obj->q2));
	}
	else {
		return QueueBack(&(obj->q1));
	}
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&(obj->q1)) == 0 || QueueEmpty(&(obj->q2)) == 0)
		return false;
	else
		return true;
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
	obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/