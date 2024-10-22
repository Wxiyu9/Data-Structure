#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;

//通过顺序表来实现栈
typedef struct Stack {
	STDataType* _a;
	int _top;		//栈顶
	int _capacity;	//容量
}Stack;

//初始化栈
void StackInit(Stack* ps);

//入栈
void StackPush(Stack* ps, STDataType data);

//出栈
void StackPop(Stack* ps);

//获取栈顶元素
STDataType StackTop(Stack* ps);

//获取栈中有效元素个数
int StatckSize(Stack* ps);

//检测栈是否为空，若为空则返回非零结果
//若不为空则返回0
int StackEmpty(Stack* ps);

//输出栈
void PrintStack(Stack* ps);

//销毁栈
void StackDestroy(Stack* ps);