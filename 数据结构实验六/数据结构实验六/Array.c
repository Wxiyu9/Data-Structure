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

// 矩阵
// 矩阵行列从1开始计算下标
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
	tm->mu = mu;
	tm->nu = nu;
	tm->tu = tu;
	int check = 0;
	int i = 1, j = 1;
	ElemType e = 0;
	int num = 0;
	while(num < tu){
		check = 0;
		printf("请分别输入元素的行号、列号、元素值：");
		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &e);
		if (i > tm->mu || j > tm->nu || i <= 0 || j <= 0) {
			printf("输入错误，下标不在范围内\n");
			continue;
		}
		i -= 1;
		j -= 1;
		if (num != 0) {
			for (int a = 0; a < tm->tu; a++) {
				if (tm->data[a].i == i && tm->data[a].j == j) {
					check = 1;
					break;
				}
			}
			if (check == 1)
			{
				printf("输入错误，输入的下标重复，请重新输入！\n");
				continue;
			}
			int ipre = tm->data[num - 1].i;
			int jpre = tm->data[num - 1].j;
			int epre = tm->data[num - 1].e;
			if (i < ipre || (i == ipre && j < jpre)) {
				printf("输入错误，下标输入时要递增输入，请重新输入！\n");
				continue;
			}//if
		}//if
		//走到这的，输入合法
		tm->data[num].i = i;
		tm->data[num].j = j;
		tm->data[num].e = e;
		num++;
	}//while
}//Creat

// 2.销毁
void DestroyedMatrix(TsMatrix* tm) {
	assert(tm);
	tm->mu = tm->nu = tm->tu = 0;
}

// 3.打印
void PrintMatrix(TsMatrix* tm) {
	int num = 0;
	for (int i = 0; i < tm->mu;i++) {
		for (int j = 0; j < tm->nu;j++) {
			if (i == tm->data[num].i && j == tm->data[num].j && num <= tm->tu) {
				printf("%d  ", tm->data[num].e);
				num++;
			}
			else {
				printf("0  ");
			}
		}
		printf("\n");
	}
}

// 4.转置矩阵
void TransPoseSMatrix(TsMatrix M, TsMatrix* T) {
	assert(T);
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	if (T->tu) {
		int q = 0;
		for (int col = 0; col < T->nu;col++) {
			for (int i = 0; i < T->tu;i++) {
				if (M.data[i].j == col) {
					T->data[q].e = M.data[i].e;
					T->data[q].j = M.data[i].i;
					T->data[q].i = M.data[i].j;
					q++;
				}
			}
		}
	}
}


// 5.快速转置矩阵
void FastTransposeSMatrix(TsMatrix M, TsMatrix* T) {
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	int num[MAXSIZE]; // 每列非零元素个数
	int cpot[MAXSIZE]; // 每列非零元素起始位置
	for (int i = 0; i < M.nu;i++) {
		num[i] = 0;
	}
	for (int i = 0; i < M.tu; i++)
	{
		num[M.data[i].j]++;
	}
	cpot[0] = 0;
	for (int i = 1;i < M.nu;i++) {
		cpot[i] = cpot[i - 1] + num[i - 1];
	}
	for (int i = 0; i < M.tu; i++) {
		T->data[cpot[M.data[i].j]].j = M.data[i].i;
		T->data[cpot[M.data[i].j]].i = M.data[i].j;
		T->data[cpot[M.data[i].j]].e = M.data[i].e;
		cpot[M.data[i].j]++;
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
	TsMatrix TransTm;
	TsMatrix FastTransTm;
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
			DestroyedMatrix(&tm);
			printf("销毁成功\n");
			break;
		case 3:
			PrintMatrix(&tm);
			break;
		case 4:
			TransPoseSMatrix(tm, &TransTm);
			PrintMatrix(&TransTm);
			break;
		case 5:
			FastTransposeSMatrix(tm, &FastTransTm);
			PrintMatrix(&FastTransTm);
			break;
		case 6:
			printf("程序退出...");
			break;
		default:
			printf("输入错误，选项不合法\n");
			break;
		}//switch

	}//do-while
	while (input != 6);
	
	return 0;
}// main