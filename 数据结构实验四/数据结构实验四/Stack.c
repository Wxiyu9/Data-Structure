#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef int STDataType;

// ջ״̬
// 0��δ��ʼ��
// 1���ѳ�ʼ��
// 2��������
int state = 0;

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

//�ж�״̬�Ƿ�Ϸ�
// 0 �Ƿ�
// 1 �Ϸ�
int CheckState() {
	if (state == 0)
	{
		printf("δ��ʼ�����������Ϸ�!\n");
		return 0;
	}
	else if (state == 1) {
		return 1;
	}
	else {
		printf("�����٣��������Ϸ�!\n");
		return 0;
	}
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

//���ջ
void StackClear(Stack* ps) {
	assert(ps);
	for (int i = 0; i < ps->_top; i++)
	{
		*(ps->_a + i) = 0;
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
int StatckSize(Stack* ps) {
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

// ����ת��
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
	// ת��Ϊʮ����

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
	
	// ת��ΪĿ�����
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
	printf("**         1.��ʼ��ջ         **\n");
	printf("**         2.����ջ           **\n");
	printf("**         3.���ջ           **\n");
	printf("**         4.ջ�п�           **\n");
	printf("**         5.��ջ����         **\n");
	printf("**         6.��ȡջ��Ԫ��     **\n");
	printf("**         7.����Ԫ��         **\n");
	printf("**         8.ɾ��һ��Ԫ��     **\n");
	printf("**         9.�������Ԫ��     **\n");
	printf("**         10.����ת��        **\n");
	printf("**         11.�˳�����        **\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input) {
		case 1: {
			StackInit(&s);
			printf("��ʼ���ɹ�!\n");
			state = 1;
			break;
		}
		case 2: {
			if (CheckState()) {
				StackDestroy(&s);
				state = 2;
				printf("���ٳɹ�!\n");
			}
			break;
		}
		case 3: {
			if (CheckState()) {
				StackClear(&s);
				printf("��ճɹ�!\n");
			}
			break;
		}
		case 4:
		{
			if (CheckState()) {
				if (StackEmpty(&s)) {
					printf("ջΪ��\n");
				}
				else {
					printf("ջ��Ϊ��\n");
				}
			}
			break;
		}
		case 5: {
			if (CheckState()) {
				printf("ջ����Ϊ��%d\n", StatckSize(&s));
			}
			break;
		}
		case 6: {
			if (CheckState()) {
				temp = StackTop(&s);
				printf("ջ��Ԫ��Ϊ��%d\n", temp);
			}
			break;
		}
		case 7: {
			if (CheckState()) {
				printf("���������Ԫ�أ�");
				scanf("%d", &temp);
				StackPush(&s, temp);
			}
			break;
		}
		case 8: {
			if (CheckState()) {
				StackPop(&s);
				printf("ɾ���ɹ�\n");
			}
			break;
		}
		case 9: {
			if (CheckState()) {
				printf("ջ��Ԫ�أ�");
				PrintStack(&s);
			}
			break;
		}
		case 10: {
			printf("�������ת�����ƣ�");
			scanf("%d", &OriginBase);
			printf("���������ݣ�");
			scanf("%s", &data);
			printf("������Ŀ����ƣ�");
			scanf("%d", &AimBase);
			printf("ת�����Ϊ��%s\n",BaseConversion(&data, OriginBase, AimBase));
			break;
		}
		case 11: {
			printf("�����˳�\n");
			break;
		}
		default: {
			printf("��������\n");
			break;
		}
		}
	} while (input != 11);
	return 0;
}