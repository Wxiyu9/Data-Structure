#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 1250

typedef int ElemType;

//三元组节点
typedef struct {
	int i;             //元素行号
	int j;            //元素列号
	ElemType e;     //元素值
} Triple;

//矩阵
typedef struct {
	Triple  data[MAXSIZE + 1];
	//三元组表，以行为主序存入一维向量 data[ ]中
	int mu;       //矩阵总行数
	int nu;       //矩阵总列数
	int tu;       //矩阵中非零元素总个数
} TsMatrix;

// 1.创建矩阵
void CreatMatrix(TsMatrix* tm, int mu,int nu,int tu) {
	assert(tm);
	TsMatrix* NewTm = (TsMatrix*)malloc(sizeof(TsMatrix));
	if (NewTm == NULL) {
		perror("malloc fail : ");
	}
	NewTm->mu = mu;
	NewTm->nu = nu;
	NewTm->tu = tu;
	tm = NewTm;
	int i = 0, j = 0;
	ElemType e = 0;
	int num = 0;
	while(num < tu){
		printf("请分别输入元素的行号、列号、元素值：");
		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &e);
		if (num != 0) {
			int ipre = tm->data[num - 1].i;
			int jpre = tm->data[num - 1].j;
			int epre = tm->data[num - 1].e;
			if (i < ipre || (i == ipre && j < jpre)) {
				printf("输入错误，下标输入时要递增输入，请重新输入！\n");
				continue;
			}//if
			else if (i == ipre && j == jpre) {
				printf("输入错误，输入的下标重复，请重新输入！\n");
				continue;
			}//else if
		}//if
		//走到这的，输入合法
		Triple* temp = (Triple*)malloc(sizeof(Triple));
		if (temp == NULL) {
			perror("malloc fail:");
		}
		temp->i = i;
		temp->j = j;
		temp->e = e;
		tm->data[num] = *temp;
		num++;
	}//while
}//Creat

// 3.打印
void PrintMatrix(TsMatrix* tm) {
	int num = 0;
	for (int i = 0; i < tm->mu;i++) {
		for (int j = 0; j < tm->nu;j++) {
			if (i == tm->data[num].i && j == tm->data[num].j) {
				printf("%d ", tm->data[num].e);
				num++;
			}
			else {
				printf("0 ");
			}
		}
		printf("\n");
	}
}

void Menu() {
	printf("***********************\n");
	printf("*                     *\n");
	printf("*     1.创建矩阵      *\n");
	printf("*     2.销毁矩阵      *\n");
	printf("*     3.输出矩阵      *\n");
	printf("*     4.转置矩阵      *\n");
	printf("*     5.快速转置矩阵  *\n");
	printf("*     6.退出          *\n");
	printf("*                     *\n");
	printf("***********************\n");
}



int main()
{
	TsMatrix tm;
	int mu, nu, tu;
	int input = 0;
	Menu();
	do {
		
		printf("请输入选项:");
		scanf("%d", &input);
		switch (input) {
		case 1:
			do {
				printf("请分别输入矩阵行数、列数、非零元个数：");
				scanf("%d", &mu);
				scanf("%d", &nu);
				scanf("%d", &tu);
				if (mu * nu < tu) {
					printf("输入错误，非零元素个数要小于等于行数乘列数，请从新输入\n");
				}
				else {
					CreatMatrix(&tm, mu, nu, tu);
					break;
				}
			} //do-while
			while (1);
			break;
		case 2:
			break;
		case 3:
			PrintMatrix(&tm);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			printf("输入错误\n");
			break;
		}//switch

	}//do-while
	while (input != 6);
	
	return 0;
}// main