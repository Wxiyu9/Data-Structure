#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void Menu()
{
	printf("***********************\n");
	printf("*  1.��ʼ��           *\n");
	printf("*  2.��ջ             *\n");
	printf("*  3.��ջ             *\n");
	printf("*  4.��ȡջ��Ԫ��     *\n");
	printf("*  5.��ȡ��ЧԪ�ظ��� *\n");
	printf("*  6.�п�             *\n");
	printf("*  7.����ջ           *\n");
	printf("*  8.���ջ           *\n");
	printf("***********************\n");
}

int main()
{
	int input = 0;
	int data = 0;
	Stack s;
	Menu();
	do {	
		printf("������ѡ�");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//��ʼ��
			StackInit(&s);
			break;
		case 2:
			//��ջ
			printf("���������ݣ�");
			scanf("%d", &data);
			StackPush(&s, data);
			break;
		case 3:
			//��ջ
			StackPop(&s);
			break;
		case 4:
			//��ȡջ��Ԫ��
			printf("%d\n",StackTop(&s));
			break;
		case 5:
			//��ȡջ����ЧԪ�ظ���
			printf("%d\n", StatckSize(&s));
			break;
		case 6:
			//����Ƿ�Ϊ��
			if (StackEmpty(&s) == 0)
			{
				printf("��Ϊ��\n");
			}
			else {
				printf("Ϊ��\n");
			}
			break;
		case 7:
			//����ջ
			StackDestroy(&s);
			break;
		case 8:
			//���ջ
			PrintStack(&s);
			break;
		default:
			break;
		}
	} while (input != 0);
	return 0;
}