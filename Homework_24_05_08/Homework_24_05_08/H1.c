#define _CRT_SECURE_NO_WARNINGS 1
//225.�ö���ʵ��ջ

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;



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

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
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
	if (QueueEmpty(&(obj->q1)))//q1Ϊ��
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