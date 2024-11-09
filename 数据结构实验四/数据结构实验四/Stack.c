#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef int STDataType;

// 栈状态
// 0：未初始化
// 1：已初始化
// 2：已销毁
int state = 0;

//通过顺序表来实现栈
typedef struct Stack {
	STDataType* _a;
	int _top;		//栈顶
	int _capacity;	//容量
}Stack;

//初始化栈
void StackInit(Stack* ps) {
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

//判断状态是否合法
// 0 非法
// 1 合法
int CheckState() {
	if (state == 0)
	{
		printf("未初始化，操作不合法!\n");
		return 0;
	}
	else if (state == 1) {
		return 1;
	}
	else {
		printf("已销毁，操作不合法!\n");
		return 0;
	}
}


//检查空间是否足够
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

//清空栈
void StackClear(Stack* ps) {
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		*(ps->_a + i) = 0;
	}
}

//入栈
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	CheckCapacity(ps);
	*(ps->_a + ps->_top) = data;
	ps->_top++;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

//获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return *(ps->_a + ps->_top - 1);
}

//获取栈中有效元素个数
int StatckSize(Stack* ps) {
	assert(ps);
	return ps->_top;
}

//检测栈是否为空，若为空则返回非零结果
//若不为空则返回0
int StackEmpty(Stack* ps) {
	return ps->_top == 0;
}

//输出栈
void PrintStack(Stack* ps)
{
	for (int i = 0; i < ps->_top; i++)
	{
		printf("%d ", *(ps->_a + i));
	}
	printf("\n");
}




//销毁栈
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// 进制转换
char* BaseConversion(char* data, int OriginBase, int AimBase) {
	Stack s;
	StackInit(&s);
	int n = 0;
	int temp = 0;
	char* cur = data;
	size_t size = strlen(data);
	int decimal = 0;
	char* result = (char*)malloc(sizeof(char) * 4 * size);
	result[0] = '\0';
	// 转换为十进制

	for (int i = size - 1; i >= 0; i--)
	{
		if (*(data + i) >= '0' && *(data + i) <= '9') {
			n = (int)(*(data + i) - 48);
		}
		else if (*(data + i) >= 'a' && *(data + i) <= 'f') {
			n = (int)(*(data + i) - 87);
		}
		else if (*(data + i) >= 'A' && *(data + i) <= 'F') {
			n = (int)(*(data + i) - 54);
		}
		decimal += n * (int)pow(OriginBase, size - i - 1);
	}
	
	// 转换为目标进制
	while (decimal) {
		temp = decimal % AimBase;
		StackPush(&s, temp);
		decimal /= AimBase;
	}
	while (!StackEmpty(&s))
	{
		char a = 0;
		temp = StackTop(&s);
		if (temp < 10)
		{
			a = (char)(temp + 48);
		}
		else {
			a = (char)(temp + 55);
		}
		strncat(result, &a,1);
		StackPop(&s);
	}
	return result;
}

void PrintMenu() {
	printf("********************************\n");
	printf("**                            **\n");
	printf("**         1.初始化栈         **\n");
	printf("**         2.销毁栈           **\n");
	printf("**         3.清空栈           **\n");
	printf("**         4.栈判空           **\n");
	printf("**         5.求栈长度         **\n");
	printf("**         6.获取栈顶元素     **\n");
	printf("**         7.插入元素         **\n");
	printf("**         8.删除一个元素     **\n");
	printf("**         9.输出所有元素     **\n");
	printf("**         10.进制转换        **\n");
	printf("**         11.退出程序        **\n");
	printf("**                            **\n");
	printf("********************************\n");
}

int main()
{
	PrintMenu();
	Stack s;
	int OriginBase;
	int AimBase;
	char data = 0;
	STDataType temp;
	int input = 0;
	do {
		printf("请选择：");
		scanf("%d", &input);
		switch (input) {
		case 1: {
			StackInit(&s);
			printf("初始化成功!\n");
			state = 1;
			break;
		}
		case 2: {
			if (CheckState()) {
				StackDestroy(&s);
				state = 2;
				printf("销毁成功!\n");
			}
			break;
		}
		case 3: {
			if (CheckState()) {
				StackClear(&s);
				printf("清空成功!\n");
			}
			break;
		}
		case 4:
		{
			if (CheckState()) {
				if (StackEmpty(&s)) {
					printf("栈为空\n");
				}
				else {
					printf("栈不为空\n");
				}
			}
			break;
		}
		case 5: {
			if (CheckState()) {
				printf("栈长度为：%d\n", StatckSize(&s));
			}
			break;
		}
		case 6: {
			if (CheckState()) {
				temp = StackTop(&s);
				printf("栈顶元素为：%d\n", temp);
			}
			break;
		}
		case 7: {
			if (CheckState()) {
				printf("请输入插入元素：");
				scanf("%d", &temp);
				StackPush(&s, temp);
			}
			break;
		}
		case 8: {
			if (CheckState()) {
				StackPop(&s);
				printf("删除成功\n");
			}
			break;
		}
		case 9: {
			if (CheckState()) {
				printf("栈中元素：");
				PrintStack(&s);
			}
			break;
		}
		case 10: {
			printf("请输入待转换进制：");
			scanf("%d", &OriginBase);
			printf("请输入数据：");
			scanf("%s", &data);
			printf("请输入目标进制：");
			scanf("%d", &AimBase);
			printf("转换结果为：%s\n",BaseConversion(&data, OriginBase, AimBase));
			break;
		}
		case 11: {
			printf("程序退出\n");
			break;
		}
		default: {
			printf("输入有误\n");
			break;
		}
		}
	} while (input != 11);
	return 0;
}