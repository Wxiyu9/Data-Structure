#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 662.���ѭ������

typedef int STDataType;

//ͨ��˳�����ʵ��ջ
typedef struct Stack {
    STDataType* _a;
    int _top;		//ջ��
    int _capacity;	//����
}Stack;

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
int StackSize(Stack* ps) {
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

//��ʼ��ջ
void StackInit(Stack* ps);

//��ջ
void StackPush(Stack* ps, STDataType data);

//��ջ
void StackPop(Stack* ps);

//��ȡջ��Ԫ��
STDataType StackTop(Stack* ps);

//��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);

//���ջ�Ƿ�Ϊ�գ���Ϊ���򷵻ط�����
//����Ϊ���򷵻�0
int StackEmpty(Stack* ps);

//���ջ
void PrintStack(Stack* ps);

//����ջ
void StackDestroy(Stack* ps);


typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&(q->s1));
    StackInit(&(q->s2));
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    if (StackEmpty(&(obj->s1)))//s1��
    {
        StackPush(&(obj->s2), x);
    }
    else {
        StackPush(&(obj->s1), x);
    }
}

//1 2 3 4 5 6
//6 5 4 3 2
//2 3 4 5 6
int myQueuePop(MyQueue* obj) {
    int n = 0;
    if (StackEmpty(&(obj->s1))) {
        //s1��
        while (StackSize(&(obj->s2)) != 1) {
            int x = StackTop(&(obj->s2));
            StackPop(&(obj->s2));
            StackPush(&(obj->s1), x);
        }
        n = StackTop(&(obj->s2));
        StackPop(&(obj->s2));
        while (!StackEmpty(&(obj->s1))) {
            int x = StackTop(&(obj->s1));
            StackPop(&(obj->s1));
            StackPush(&(obj->s2), x);
        }
    }
    else {
        //s2��
        while (StackSize(&(obj->s1)) != 1) {
            int x = StackTop(&(obj->s1));
            StackPop(&(obj->s1));
            StackPush(&(obj->s2), x);
        }
        n = StackTop(&(obj->s1));
        StackPop(&(obj->s1));
        while (!StackEmpty(&(obj->s2))) {
            int x = StackTop(&(obj->s2));
            StackPop(&(obj->s2));
            StackPush(&(obj->s1), x);
        }
    }

    return n;
}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&(obj->s1)))
    {
        return *(obj->s2._a);
    }
    else {
        return *(obj->s1._a);
    }
}

bool myQueueEmpty(MyQueue* obj) {
    if (StackSize(&(obj->s1)) == 0 && !StackSize(&(obj->s2)) == 0)
    {
        return false;
    }
    else {
        return true;
    }
}

void myQueueFree(MyQueue* obj) {
    StackDestroy(&(obj->s1));
    StackDestroy(&(obj->s2));
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/