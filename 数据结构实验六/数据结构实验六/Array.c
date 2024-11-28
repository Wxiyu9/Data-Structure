#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 1250

typedef int ElemType;

//��Ԫ��ڵ�
typedef struct {
	int i;             //Ԫ���к�
	int j;            //Ԫ���к�
	ElemType e;     //Ԫ��ֵ
} Triple;

// ����
// �������д�1��ʼ�����±�
typedef struct {
	Triple  data[MAXSIZE + 1];
	//��Ԫ�������Ϊ�������һά���� data[ ]��
	int mu;       //����������
	int nu;       //����������
	int tu;       //�����з���Ԫ���ܸ���
} TsMatrix;

// 1.��������
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
		printf("��ֱ�����Ԫ�ص��кš��кš�Ԫ��ֵ��");
		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &e);
		if (i > tm->mu || j > tm->nu || i <= 0 || j <= 0) {
			printf("��������±겻�ڷ�Χ��\n");
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
				printf("�������������±��ظ������������룡\n");
				continue;
			}
			int ipre = tm->data[num - 1].i;
			int jpre = tm->data[num - 1].j;
			int epre = tm->data[num - 1].e;
			if (i < ipre || (i == ipre && j < jpre)) {
				printf("��������±�����ʱҪ�������룬���������룡\n");
				continue;
			}//if
		}//if
		//�ߵ���ģ�����Ϸ�
		tm->data[num].i = i;
		tm->data[num].j = j;
		tm->data[num].e = e;
		num++;
	}//while
}//Creat

// 2.����
void DestroyedMatrix(TsMatrix* tm) {
	assert(tm);
	tm->mu = tm->nu = tm->tu = 0;
}

// 3.��ӡ
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

// 4.ת�þ���
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


// 5.����ת�þ���
void FastTransposeSMatrix(TsMatrix M, TsMatrix* T) {
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	int num[MAXSIZE]; // ÿ�з���Ԫ�ظ���
	int cpot[MAXSIZE]; // ÿ�з���Ԫ����ʼλ��
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
	printf("*     1.��������      *\n");
	printf("*     2.���پ���      *\n");
	printf("*     3.�������      *\n");
	printf("*     4.ת�þ���      *\n");
	printf("*     5.����ת�þ���  *\n");
	printf("*     6.�˳�          *\n");
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
		
		printf("������ѡ��:");
		scanf("%d", &input);
		switch (input) {
		case 1:
			do {
				printf("��ֱ������������������������Ԫ������");
				scanf("%d", &mu);
				scanf("%d", &nu);
				scanf("%d", &tu);
				if (mu * nu < tu) {
					printf("������󣬷���Ԫ�ظ���ҪС�ڵ������������������������\n");
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
			printf("���ٳɹ�\n");
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
			printf("�����˳�...");
			break;
		default:
			printf("�������ѡ��Ϸ�\n");
			break;
		}//switch

	}//do-while
	while (input != 6);
	
	return 0;
}// main