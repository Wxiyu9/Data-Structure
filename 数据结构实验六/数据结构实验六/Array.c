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

//����
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
		printf("��ֱ�����Ԫ�ص��кš��кš�Ԫ��ֵ��");
		scanf("%d", &i);
		scanf("%d", &j);
		scanf("%d", &e);
		if (num != 0) {
			int ipre = tm->data[num - 1].i;
			int jpre = tm->data[num - 1].j;
			int epre = tm->data[num - 1].e;
			if (i < ipre || (i == ipre && j < jpre)) {
				printf("��������±�����ʱҪ�������룬���������룡\n");
				continue;
			}//if
			else if (i == ipre && j == jpre) {
				printf("�������������±��ظ������������룡\n");
				continue;
			}//else if
		}//if
		//�ߵ���ģ�����Ϸ�
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

// 3.��ӡ
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
			printf("�������\n");
			break;
		}//switch

	}//do-while
	while (input != 6);
	
	return 0;
}// main