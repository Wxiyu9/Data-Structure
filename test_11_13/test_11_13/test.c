#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct {
	int* top;
	int* bottom;
	int stacksize;
}SqStack;

int InitStack(SqStack* S) {
	S->bottom = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (S->bottom == NULL) {
		return 0;
	}
	S->top = S->bottom;
	S->stacksize = STACK_INIT_SIZE;

	return 1;
}

int Destroy(SqStack* S) {
	if (S->bottom == NULL) {
		return 0;
	}
	else {
		free(S->bottom);
		S->bottom = NULL;
		S->top = NULL;
		S->stacksize = 0;

		return 1;
	}
}

int Clear(SqStack* S) {
	if (S->bottom == NULL) {
		return 0;
	}

	S->top = S->bottom;

	return 1;
}

int Judge(SqStack* S) {
	if (S->bottom == NULL) {
		return 0;
	}
	if (S->bottom == S->top) {
		return -1;
	}
	else {
		return 1;
	}
}

int GetTop(SqStack* S, int* e) {
	if (S->bottom == NULL) {
		return -1;
	}
	if (S->bottom == S->top) {
		return 0;
	}
	*e = *(S->top - 1);

	return 1;
}

int GetLength(SqStack* S) {
	if (S->bottom == NULL) {
		return 0;
	}
	if (S->bottom == S->top) {
		return -1;
	}
	return (S->top - S->bottom);
}

int Insert(SqStack* S, int* e) {
	if (S->bottom == NULL) {
		return 0;
	}
	if (S->top - S->bottom == S->stacksize) {
		int newstacksize = S->stacksize + STACKINCREMENT;
		int* newbottom = (SElemType*)realloc(S->bottom, newstacksize * sizeof(SElemType));
		if (newbottom == NULL) {
			return -1;
		}

		S->top = newbottom + (S->top - S->bottom);
		S->bottom = newbottom;
		S->stacksize = newstacksize;
	}

	printf("��������ջԪ�أ�");
	scanf_s("%d", e);
	printf("\n");

	*(S->top) = *e;
	S->top++;

	return 1;
}

//�˺���Ϊ��ջ����ʼ���
int Print(SqStack* S) {
	if (S->bottom == NULL) {
		return -1;
	}
	if (S->bottom == S->top) {
		return 0;
	}

	int i = 0;
	int* temp = S->top;//�ĳɴ�ջ�׿�ʼ�����int *temp = S->bottom;

	//�ĳɴ�ջ�׿�ʼ�����while (temp < S->top)
	while (temp > S->bottom) {
		printf("%d", *(--temp));//�ĳɴ�ջ�׿�ʼ�����printf ("%d", *(temp++));
		i++;
		if (i % 5 == 0) {
			printf("\n");
		}
		else {
			printf(" ");
		}
	}

	printf("\n\n");

	return 1;
}

int Delete(SqStack* S, int* e) {
	if (S->bottom == NULL) {
		return -1;
	}
	if (S->bottom == S->top) {
		return 0;
	}

	*e = *(--S->top);

	return 1;
}

int GetNumeralSystem(int* numeral1, int* numeral2) {
	printf("��Ӷ����ơ��˽��ơ�ʮ���ơ�ʮ������������Դ���ƣ�����2��8��10��16���ɣ���");
	scanf_s("%d", numeral1);
	printf("\n");

	if (*numeral1 != 2 && *numeral1 != 8 && *numeral1 != 10 && *numeral1 != 16) {
		return -1;
	}

	printf("��Ӷ����ơ��˽��ơ�ʮ���ơ�ʮ������������Ŀ����ƣ�����2��8��10��16���ɣ���");
	scanf_s("%d", numeral2);
	printf("\n");

	if (*numeral2 != 2 && *numeral2 != 8 && *numeral2 != 10 && *numeral2 != 16) {
		return -2;
	}

	return 1;
}

int HtoD(const char* numStr) {
	int number = 0;
	int len = strlen(numStr);
	for (int i = 0; i < len; i++) {
		if (isdigit(numStr[i])) {
			number = number * 16 + (numStr[i] - '0');
		}
		else if (numStr[i] >= 'A' && numStr[i] <= 'F') {
			number = number * 16 + (numStr[i] - 'A' + 10);
		}
	}

	return number;
}

int BorOorDtoD(const char* numStr, int numeral1) {
	int number = 0;
	int len = strlen(numStr);
	for (int i = 0; i < len; i++) {
		number = number * numeral1 + (numStr[i] - '0');
	}

	return number;
}

int main() {
	int e, order, num, flag, numeral1, numeral2;
	char numStr[100];

	printf("****************************\n");
	printf("*** 1--��ʼ��ջ          ***\n");
	printf("*** 2--����ջ            ***\n");
	printf("*** 3--���ջ            ***\n");
	printf("*** 4--ջ�п�            ***\n");
	printf("*** 5--��ջ����          ***\n");
	printf("*** 6--��ȡջ��Ԫ��      ***\n");
	printf("*** 7--����һ��Ԫ��      ***\n");
	printf("*** 8--ɾ��һ��Ԫ��      ***\n");
	printf("*** 9--�������Ԫ��      ***\n");
	printf("*** 10-����ת��          ***\n");
	printf("*** ����һ�������˳����� ***\n");
	printf("****************************\n\n");

	printf("�����빦�ܱ�ţ�");
	scanf_s("%d", &num);
	printf("\n");

	while (num != 1) {
		if (num < 0) {
			printf("�˳�����ɹ���\n");
			return 0;
		}
		else if (num == 0 || num > 10) {
			printf("���빦�ܱ���������������롣\n\n");
			printf("�����빦�ܱ�ţ�");
			scanf_s("%d", &num);
			printf("\n");
		}
		else {
			printf("ջδ��ʼ������������1���г�ʼ����\n\n");
			printf("�����빦�ܱ�ţ�");
			scanf_s("%d", &num);
			printf("\n");
		}
	}

	SqStack S;

	order = num;

	do {
		if (order != 1) {
			printf("�����빦�ܱ�ţ�");
			scanf_s("%d", &order);
			printf("\n");
		}
		switch (order) {
		case 1:
			flag = InitStack(&S);

			if (flag == 0) {
				printf("ջ��ʼ��ʧ�ܡ�\n\n");
			}
			if (flag == 1) {
				printf("ջ��ʼ���ɹ���\n\n");
			}

			order = 0;

			break;


		case 2:
			flag = Destroy(&S);

			if (flag == 0) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == 1) {
				printf("ջ���ٳɹ���\n\n");
			}

			break;

		case 3:
			flag = Clear(&S);

			if (flag == 0) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == 1) {
				printf("ջ�����ϡ�\n\n");
			}

			break;

		case 4:
			flag = Judge(&S);

			if (flag == 0) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == -1) {
				printf("ջΪ�ա�\n\n");
			}
			if (flag == 1) {
				printf("ջ�ǿա�\n\n");
			}

			break;

		case 5:
			flag = GetLength(&S);

			if (flag == 0) {
				printf("���ȳ�ʼ��ջ��\n\n");
				break;
			}
			if (flag == -1) {
				printf("ջΪ�գ�����Ϊ0��\n\n");
				break;
			}
			printf("ջ�ĳ���Ϊ��%d\n\n", flag);

			break;

		case 6:
			flag = GetTop(&S, &e);
			if (flag == -1) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == 0) {
				printf("ջΪ�գ�û��ջ��Ԫ�ء�\n\n");
			}
			if (flag == 1) {
				printf("ջ��Ԫ��Ϊ��%d\n\n", e);
			}

			break;

		case 7:
			flag = Insert(&S, &e);
			if (flag == 0) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == -1) {
				printf("ջ�����ڴ����·���ʧ�ܡ�\n\n");
			}
			if (flag == 1) {
				printf("����ɹ���\n\n");
			}

			break;

		case 8:
			flag = Delete(&S, &e);
			if (flag == -1) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == 0) {
				printf("ջΪ�գ��޷�ɾ��Ԫ�ء�\n\n");
			}
			if (flag == 1) {
				printf("��ɾ��ջ�����һ��Ԫ�أ�%d����\n\n", e);
			}

			break;

		case 9:
			flag = Print(&S);

			if (flag == -1) {
				printf("���ȳ�ʼ��ջ��\n\n");
			}
			if (flag == 0) {
				printf("ջΪ�գ�û��Ԫ�ء�\n\n");
			}
			if (flag == 1) {
				printf("ջԪ�������ϡ�\n\n");
			}
			break;

		case 10:
			flag = GetNumeralSystem(&numeral1, &numeral2);

			if (flag == -1) {
				printf("Դ������������\n\n");
				break;
			}
			if (flag == -2) {
				printf("Ŀ�������������\n\n");
				break;
			}
			if (flag == 1) {
				printf("Դ������Ŀ�����¼��ɹ���\n\n");
				printf("������Ҫת��������");
				scanf_s("%s", &numStr);
				printf("\n");
				if (numeral1 == 16) {
					e = HtoD(numStr);
				}
				else {
					e = BorOorDtoD(numStr, numeral1);
				}
				printf("%d", e);
			}

			break;

		default:
			if (order == 0 || order > 10) {
				printf("���빦�ܱ���������������롣\n\n");
			}
			else {
				break;
			}
		}
	} while (order >= 0);

	printf("�˳�����ɹ���\n");

	return 0;
}