#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
#define PI 3.14

//������˵�
void menu()
{
	printf("****************************************\n");
	printf("******         СС������         ******\n");
	printf("******      1.�ӷ�    2.����      ******\n");
	printf("******      3.�˷�    4.����      ******\n");
	printf("******      5.�ж����ֵ�λ��      ******\n");
	printf("******      6.����Բ���          ******\n");
	printf("******      7.�ж�����            ******\n");
	printf("******      8.�ɼ�ת��            ******\n");
	printf("******      9.����1~x��������     ******\n");
	printf("******      10.����1~x��ż����    ******\n");
	printf("******      11.���1~x��3�ı���   ******\n");
	printf("******   12.���x~y�е�һ������3  ******\n");
	printf("******      �����ֱ�5��������     ******\n");
	printf("******      13.��ˮ�ɻ���         ******\n");
	printf("******      14.�����ֵ           ******\n");
	printf("******      15.�������Сֵ       ******\n");
	printf("******      16.ð������(10)       ******\n");
	printf("******      17.����ת��(3��4)      ******\n");
	printf("******      18.��Խ���֮��       ******\n");
	printf("******      19.ͳ�Ƶ��ʸ���       ******\n");
	printf("******      20.������̬����       ******\n");
	printf("******      21.������̬����       ******\n");
	printf("******      22.ѧ���ɼ�����       ******\n");
	printf("******      23.ѧ���ɼ�����       ******\n");
	printf("******      24.ȡģ����           ******\n");
	printf("******      25.�˳�����           ******\n");
	printf("****************************************\n");
}
//5.�ж�����λ��
void Num(int x)
{
	if (x < 0)
	{
		printf("Ҫ���������Ϊ������\n");
		return;
	}
	else if (x > 999)
	{
		printf("Ҫ���������Ϊ��λ���ڵ�������\n");
		return;
	}
	int arr[3] = { 0 };
	int i = 0;
	while (x)
	{
		arr[i] = x % 10;
		x /= 10;
		i++;
	}
	if (i == 1)
		printf("����Ϊ1λ������λ��%d\n", arr[0]);
	else if (i == 2)
		printf("����Ϊ2λ����ʮλ��%d����λ��%d\n", arr[1], arr[0]);
	else
		printf("����Ϊ3λ������λ��%d��ʮλ��%d����λ��%d\n", arr[2], arr[1], arr[0]);
}

//7.�ж��Ƿ�Ϊ����
void Year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d������\n", year);
	else
		printf("%d��ƽ��\n", year);
}

//8.�ɼ�ת��
void Grade(int x)
{
	if (x < 0 || x > 100)
	{
		printf("�ɼ��������\n");
		return;
	}
	if (x >= 90)
		printf("����\n");
	else if (x < 90 && x >= 80)
		printf("��\n");
	else if (x < 80 && x >= 70)
		printf("��\n");
	else if (x < 70 && x >= 60)
		printf("����\n");
	else
		printf("������\n");
}

//9.�ж�1~x��������
void OddNum(int x)
{
	int i;
	int num = 0;
	for (i = 1; i <= x; i++)
	{
		if (i % 2 == 1)
			num += i;
	}
	printf("1~%d�е�������Ϊ%d\n", x, num);
}

//10.�ж�1~x��ż����
void EvenNum(int x)
{
	int i = 1;
	int num = 0;
	while (i <= x)
	{
		if (i % 2 == 0)
			num += i;
		i++;
	}
	printf("1~%d�е�ż����Ϊ%d\n", x, num);
}

//11.���1~x��3�ı���
void ModThree(int x)
{
	int i = 1;
	int num = 0;
	do
	{
		if (i % 3 == 0)
		{
			printf("%d ", i);
			num += i;
		}
		i++;
	} while (i <= x);
	if (!num)
	{
		printf("������\n");
	}
	else
		printf("\n");
}

//12.���x~y�е�һ�������������ֱ�����������
void ModThreeFive(int x, int y)
{
	int i = 0;
	for (i = x; i <= y; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("%d\n", i);
			return;
		}
	}
	printf("������\n");
}

//13.���ˮ�ɻ���
void DafNum()
{
	for (int i = 100; i < 1000; i++)
	{
		int q = i % 10;
		int w = (i / 10) % 10;
		int e = (i / 100) % 10;
		int num = q * q * q + w * w * w + e * e * e;
		if (num == i)
			printf("%d ", num);
	}
	printf("\n");
}

//14.�����ֵ
int Max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

//15.�������Сֵ
void MaxMin(int* x, int* y)
{
	assert(x && y);
	if (*x > *y)
		return;
	int a = *x;
	*x = *y;
	*y = a;
}

//16.ð������
void Bubbles(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int n = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = n;
			}
		}
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//17.����ת��
void MatTra(int* arr1, int* arr2, int row, int col)
{
	assert(arr1 && arr2);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(arr2 + j * row + i) = *(arr1 + i * col + j);
		}
	}
	printf("ת�ý����\n");
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			printf("%d ", *(arr2 + i * row + j));
		printf("\n");
	}
}

//18.��Խ��ߺ�
int  DiaNum(int* arr, int size)
{
	assert(arr);
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		num += *(arr + i * size + i);
	}
	return num;
}

//19.ͳ�Ƶ��ʸ���
int WordNum(char* str)
{
	assert(str);
	char* ch = str;
	int num = 0;
	while (*ch != '\0')
	{
		if (*ch == ' ')
			num++;
		ch++;
	}
	return num + 1;
}

//20.��̬����
void StaticList()
{
	typedef struct SQStaticList {
		int data;
		struct SQStaticList* next;
	}SSL;
	SSL arr[4];
	arr[0].data = 1;
	arr[1].data = 2;
	arr[2].data = 3;
	arr[3].data = 4;

	SSL* head = &arr[0];
	arr[0].next = &arr[1];
	arr[1].next = &arr[2];
	arr[2].next = &arr[3];
	arr[3].next = NULL;

	SSL* cur = head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//21.��̬����
void SListNode()
{
	typedef struct SListNode
	{
		int data;
		struct SListNode* next;
	}SLTNode;
	SLTNode* head = NULL;
	int n = 0;
	printf("��������ͷ���������ݣ�");
	scanf("%d", &n);
	do {
		SLTNode* pcur = (SLTNode*)malloc(sizeof(SLTNode));
		pcur->data = n;
		pcur->next = head;
		head = pcur;
		printf("��������ͷ���������ݣ�");
		scanf("%d", &n);
	} while (n >= 0);
	SLTNode* ccur = head;
	printf("���������Ϊ��");
	while (ccur)
	{
		printf("%d ", ccur->data);
		ccur = ccur->next;
	}
	printf("\n");
}

//22.ͳ��ѧ����Ϣ
void StuInformation()
{
	typedef struct StuInformation {
		char id[20];
		char name[10];
		int grade;
	}Stu;
	Stu inf[10];
	size_t sz = sizeof(inf) / sizeof(inf[0]);
	for (int i = 0; i < sz; i++)
	{
		printf("������ѧ��%d��ѧ�ţ�", i + 1);
		scanf("%s", inf[i].id);
		printf("������ѧ��%d��������", i + 1);
		scanf("%s", inf[i].name);
		printf("������ѧ��%d�ĳɼ���", i + 1);
		scanf("%d", &inf[i].grade);
		printf("\n");
	}
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (inf[j].grade > inf[j + 1].grade)
			{
				Stu a = inf[j];
				inf[j] = inf[j + 1];
				inf[j + 1] = a;
			}
		}
	}
	printf("���������\n");
	int num = 0;
	for (int i = 0; i < sz; i++)
	{
		num += inf[i].grade;
		printf("ѧ�ţ�%s\t������%s\t�ɼ���%d\t\n", inf[i].id, inf[i].name, inf[i].grade);
	}
	printf("ѧ�����ܳɼ�Ϊ��%d\n", num);
}

//23.�ɼ�����
void StuGradUpper()
{
	FILE* pf = fopen("d:\\my.txt.txt", "r+");
	if (pf == NULL)
	{
		perror("fopen");
		return 1;
	}
	int grade[10] = { 0 };
	int i = 0;
	while (!feof(pf))
	{
		fscanf(pf, "%d", &grade[i]);
		grade[i] += 10;
		i++;
	}
	rewind(pf);
	for (int i = 0; i < 10; i++)
	{
		if (i == 9)
			fprintf(pf, "%d", grade[i]);
		else
			fprintf(pf, "%d\n", grade[i]);
	}
	printf("�ɼ�����10�ֳɹ���\n");
	fclose(pf);
	pf = NULL;
}

int main()
{
	int x, y, input;
	float a, b;
	do
	{
		system("cls");
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 25:
			printf("�˳�����...\n");
			break;
		case 1:
			printf("�������������");
			scanf("%d%d", &x, &y);
			printf("�ӷ������ʮ������ʽ�ǣ�%d\n", x + y);
			printf("�ӷ�����İ˽�����ʽ�ǣ�%o\n", x + y);
			printf("�ӷ������ʮ��������ʽ�ǣ�%x\n", x + y);
			break;
		case 2:
			printf("�������������");
			scanf("%d%d", &x, &y);
			printf("���������ʮ������ʽ�ǣ�%d\n", x - y);
			printf("��������İ˽�����ʽ�ǣ�%o\n", x - y);
			printf("���������ʮ��������ʽ�ǣ�%x\n", x - y);
			break;
		case 3:
			printf("�������������");
			scanf("%f%f", &a, &b);
			printf("�˷������С����ʽ�ǣ�%f\n", a * b);
			printf("�˷������ָ����ʽ�ǣ�%e\n", a * b);
			break;
		case 4:
			printf("�������������");
			scanf("%f%f", &a, &b);
			printf("���������С����ʽ�ǣ�%f\n", a / b);
			printf("���������ָ����ʽ�ǣ�%e\n", a / b);
			break;
		case 24:
			printf("�������������");
			scanf("%d%d", &x, &y);
			if (y == 0)
			{
				printf("����Ϊ0���޷����г�������\n");
				break;
			}
			printf("ȡģ�����ʮ������ʽ�ǣ�%d\n", x % y);
			printf("ȡģ����İ˽�����ʽ�ǣ�%o\n", x % y);
			printf("ȡģ�����ʮ��������ʽ�ǣ�%x\n", x % y);
			break;
		case 6:
			printf("������Բ�뾶��");
			scanf("%f", &a);
			printf("��Բ����ǣ�%f\n", PI * a * a);
			printf("��Բ���������λС���Ľ���ǣ�%.2f\n", PI * a * a);
			break;
		case 5:
			printf("������Ҫ�жϵ����֣�");
			scanf("%d", &x);
			Num(x);
			break;
		case 7:
			printf("��������ж���ݣ�");
			scanf("%d", &x);
			Year(x);
			break;
		case 8:
			printf("������ɼ���");
			scanf("%d", &x);
			Grade(x);
			break;
		case 9:
			printf("������x��");
			scanf("%d", &x);
			OddNum(x);
			break;
		case 10:
			printf("������x��");
			scanf("%d", &x);
			EvenNum(x);
			break;
		case 11:
			printf("������x��");
			scanf("%d", &x);
			ModThree(x);
			break;
		case 12:
			printf("������x��y��");
			scanf("%d%d", &x, &y);
			ModThreeFive(x, y);
			break;
		case 13:
			printf("ˮ�ɻ����У�");
			DafNum();
			break;
		case 14:
			printf("�������������");
			scanf("%d%d", &x, &y);
			printf("���ֵΪ��%d\n", Max(x, y));
			break;
		case 15:
			printf("�������������");
			scanf("%d%d", &x, &y);
			MaxMin(&x, &y);
			printf("���ֵΪ��%d\n��СֵΪ��%d\n", x, y);
			break;
		case 16:
			printf("������Ҫ�����ʮ������");
			int arr[10] = { 0 };
			int size = sizeof(arr) / sizeof(arr[0]);
			for (int i = 0; i < size; i++)
				scanf("%d", &arr[i]);
			Bubbles(arr, size);
			break;
		case 17:
			printf("������һ��3��4����������\n");
			int arr1[3][4] = { 0 };
			int arr2[4][3] = { 0 };
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					scanf("%d", &arr1[i][j]);
				}
			}
			MatTra(arr1, arr2, 3, 4);
			break;
		case 18:
			printf("������һ��3��3����������\n");
			int arr3[3][3] = { 0 };
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					scanf("%d", &arr3[i][j]);
				}
			}
			printf("���Խ���֮��Ϊ��%d\n", DiaNum(arr3, 3));
			break;
		case 19:
			printf("�����룺\n");
			char str1[256] = { 0 };
			getchar();
			gets(str1);
			printf("��%d������\n", WordNum(str1));
			break;
		case 20:
			StaticList();
			break;
		case 21:
			SListNode();
			break;
		case 22:
			StuInformation();
			break;
		case 23:
			StuGradUpper();
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
		system("pause");
	} while (input != 25);
	return 0;
}