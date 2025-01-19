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

	printf("请输入入栈元素：");
	scanf_s("%d", e);
	printf("\n");

	*(S->top) = *e;
	S->top++;

	return 1;
}

//此函数为从栈顶开始输出
int Print(SqStack* S) {
	if (S->bottom == NULL) {
		return -1;
	}
	if (S->bottom == S->top) {
		return 0;
	}

	int i = 0;
	int* temp = S->top;//改成从栈底开始输出：int *temp = S->bottom;

	//改成从栈底开始输出：while (temp < S->top)
	while (temp > S->bottom) {
		printf("%d", *(--temp));//改成从栈底开始输出：printf ("%d", *(temp++));
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
	printf("请从二进制、八进制、十进制、十六进制中输入源进制（输入2、8、10、16即可）：");
	scanf_s("%d", numeral1);
	printf("\n");

	if (*numeral1 != 2 && *numeral1 != 8 && *numeral1 != 10 && *numeral1 != 16) {
		return -1;
	}

	printf("请从二进制、八进制、十进制、十六进制中输入目标进制（输入2、8、10、16即可）：");
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
	printf("*** 1--初始化栈          ***\n");
	printf("*** 2--销毁栈            ***\n");
	printf("*** 3--清空栈            ***\n");
	printf("*** 4--栈判空            ***\n");
	printf("*** 5--求栈长度          ***\n");
	printf("*** 6--获取栈顶元素      ***\n");
	printf("*** 7--插入一个元素      ***\n");
	printf("*** 8--删除一个元素      ***\n");
	printf("*** 9--输出所有元素      ***\n");
	printf("*** 10-进制转换          ***\n");
	printf("*** 输入一个负数退出程序 ***\n");
	printf("****************************\n\n");

	printf("请输入功能编号：");
	scanf_s("%d", &num);
	printf("\n");

	while (num != 1) {
		if (num < 0) {
			printf("退出程序成功。\n");
			return 0;
		}
		else if (num == 0 || num > 10) {
			printf("输入功能编号有误，请重新输入。\n\n");
			printf("请输入功能编号：");
			scanf_s("%d", &num);
			printf("\n");
		}
		else {
			printf("栈未初始化，请输入编号1进行初始化。\n\n");
			printf("请输入功能编号：");
			scanf_s("%d", &num);
			printf("\n");
		}
	}

	SqStack S;

	order = num;

	do {
		if (order != 1) {
			printf("请输入功能编号：");
			scanf_s("%d", &order);
			printf("\n");
		}
		switch (order) {
		case 1:
			flag = InitStack(&S);

			if (flag == 0) {
				printf("栈初始化失败。\n\n");
			}
			if (flag == 1) {
				printf("栈初始化成功。\n\n");
			}

			order = 0;

			break;


		case 2:
			flag = Destroy(&S);

			if (flag == 0) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == 1) {
				printf("栈销毁成功。\n\n");
			}

			break;

		case 3:
			flag = Clear(&S);

			if (flag == 0) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == 1) {
				printf("栈清空完毕。\n\n");
			}

			break;

		case 4:
			flag = Judge(&S);

			if (flag == 0) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == -1) {
				printf("栈为空。\n\n");
			}
			if (flag == 1) {
				printf("栈非空。\n\n");
			}

			break;

		case 5:
			flag = GetLength(&S);

			if (flag == 0) {
				printf("请先初始化栈。\n\n");
				break;
			}
			if (flag == -1) {
				printf("栈为空，长度为0。\n\n");
				break;
			}
			printf("栈的长度为：%d\n\n", flag);

			break;

		case 6:
			flag = GetTop(&S, &e);
			if (flag == -1) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == 0) {
				printf("栈为空，没有栈顶元素。\n\n");
			}
			if (flag == 1) {
				printf("栈顶元素为：%d\n\n", e);
			}

			break;

		case 7:
			flag = Insert(&S, &e);
			if (flag == 0) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == -1) {
				printf("栈满，内存重新分配失败。\n\n");
			}
			if (flag == 1) {
				printf("插入成功。\n\n");
			}

			break;

		case 8:
			flag = Delete(&S, &e);
			if (flag == -1) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == 0) {
				printf("栈为空，无法删除元素。\n\n");
			}
			if (flag == 1) {
				printf("已删除栈的最后一个元素（%d）。\n\n", e);
			}

			break;

		case 9:
			flag = Print(&S);

			if (flag == -1) {
				printf("请先初始化栈。\n\n");
			}
			if (flag == 0) {
				printf("栈为空，没有元素。\n\n");
			}
			if (flag == 1) {
				printf("栈元素输出完毕。\n\n");
			}
			break;

		case 10:
			flag = GetNumeralSystem(&numeral1, &numeral2);

			if (flag == -1) {
				printf("源进制输入有误。\n\n");
				break;
			}
			if (flag == -2) {
				printf("目标进制输入有误。\n\n");
				break;
			}
			if (flag == 1) {
				printf("源进制与目标进制录入成功。\n\n");
				printf("请输入要转换的数：");
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
				printf("输入功能编号有误，请重新输入。\n\n");
			}
			else {
				break;
			}
		}
	} while (order >= 0);

	printf("退出程序成功。\n");

	return 0;
}