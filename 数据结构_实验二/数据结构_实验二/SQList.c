#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int EmptyType;

//����˳���ṹ��
typedef struct SQList {
	EmptyType* a;
	int size;		//ʵ��������
	int capasity;	//�ܿռ�
}SQList;

//����˳���״̬��
//δ��ʼ��  0
//�ѳ�ʼ��  1
//������    2
char* State = "δ��ʼ��";//�˵�
short StateCode = 0;

char* StateA = "δ��ʼ��";//˳���A
short StateCodeA = 0;

char* StateB = "δ��ʼ��";//˳���B
short StateCodeB = 0;

char* Operands = "";//��������

//��֤�����Ϸ���
//����0�����Ϸ�
//����1���Ϸ�
int CheckAction(short stateCodex)
{
	if (stateCodex == 1)
		return 1;
	else if (stateCodex == 0)
	{
		printf("δ��ʼ�������ܽ��д˲���\n");
		return 0;
	}
	else
	{
		printf("�����٣����ܽ��д˲���\n");
		return 0;
	}
}

//�л��˵���ӡ
void PrintMenu1()
{
	printf("*******************************************\n");
	printf("*                                         *\n");
	printf("*         1.�л�Ϊ˳���A                 *\n");
	printf("*         2.�л�Ϊ˳���B                 *\n");
	printf("*         3.�ϲ������ǵݼ���������Ա�    *\n");
	printf("*         4.�˳�����                      *\n");
	printf("*                                         *\n");
	printf("*******************************************\n");

}

//�����˵���ӡ
void PrintMenu2()
{
	printf("*******************************************\n");
	printf("*                                         *\n");
	printf("*         ��������%s               *\n",Operands);
	printf("*                                         *\n");
	printf("*     1. ��ʼ��һ�����Ա�                 *\n");
	printf("*     2. �������Ա�                       *\n");
	printf("*     3. ������Ա�                       *\n");
	printf("*     4. �ж����Ա��Ƿ�Ϊ��               *\n");
	printf("*     5. �����Ա���                     *\n");
	printf("*     6. ��ȡ���Ա�ָ��λ��Ԫ��           *\n");
	printf("*     7. ��ȡ���Ա���Ԫ�ص�λ��           *\n");
	printf("*     8. ��ֱ��ǰ��                       *\n");
	printf("*     9. ��ֱ�Ӻ��                       *\n");
	printf("*     10.�����Ա�ָ��λ�ò���Ԫ��         *\n");
	printf("*     11.ɾ�����Ա�ָ��λ�õ�Ԫ��         *\n");
	printf("*     12.����Ԫ��ֵ��ɾ�����Ա��е�Ԫ��   *\n");
	printf("*     13.�����Ա��������                 *\n");
	printf("*     14.��ʾ���Ա�                       *\n");
	printf("*     15.������һ���˵�                   *\n");
	printf("*                                         *\n");
	printf("*         ���Ա�״̬��%s            *\n",State);
	printf("*                                         *\n");
	printf("*******************************************\n");
}

//1.��ʼ��˳���
void InitSQList(SQList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capasity = ps->size = 0;
}

//2.����˳���
void DestroyedSQList(SQList* ps) {
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
	}
	ps->a = NULL;
	ps->capasity = ps->size = 0;
	State = "������  ";
	StateCode = 2;
}

//3.���˳���
void EmptySQList(SQList* ps)
{
	assert(ps);
	ps->size = 0;
}

//4.�ж����Ա��Ƿ�Ϊ��
int JudgmentEmpty(SQList* ps) {
	assert(ps);
	if (ps->size == 0)
		return 0;//Ϊ��
	else
		return 1;//��Ϊ��
}

//5.�����Ա���
int SQListLength(SQList* ps)
{
	assert(ps);
	return ps->size;
}

//6.��ȡ���Ա�ָ��λ��Ԫ��
EmptyType SearchElement(SQList* ps, int location) {
	if (ps->size < location || location <= 0)
		return -1;//λ�ò��ںϷ���Χ��
	return *(ps->a + location - 1);
}

//7.��ȡ���Ա���Ԫ�ص�λ��
EmptyType SearchLocation(SQList* ps, EmptyType element) {
	for (int i = 0; i < ps->size; i++)
	{
		if (*(ps->a + i) == element)
			return i + 1;
	}
	return -1;
}

//8.��ֱ��ǰ��
void SearchPrecursor(SQList* ps, EmptyType element) {
	EmptyType n = SearchLocation(ps, element);
	if (n == 1)
		printf("��һ��Ԫ��û��ǰ��\n");
	else if (n == -1)
		printf("%d������\n", element);
	else
		printf("%d��ǰ��Ԫ��Ϊ��%d\n", element, *(ps->a + n - 2));
}

//9.��ֱ�Ӻ���
void SearchBack(SQList* ps, EmptyType element) {
	int i = 0;
	for (i = ps->size - 1; i >= 0; i--)
	{
		if (*(ps->a + i) == element)
		{
			if (i == ps->size - 1)
				printf("���һ������û�к���\n");
			else
				printf("%d��ֱ�Ӻ���Ϊ��%d\n", element, *(ps->a + i + 1));
			return;
		}
	}
	printf("%d������\n", element);
}

//�жϿռ��Ƿ��㹻
void CheckSpace(SQList* ps) {
	if (ps->size == ps->capasity)
	{
		int NewCapasity = ps->capasity == 0 ? 4 : 2 * ps->capasity;
		EmptyType* TempList = (EmptyType*)realloc(ps->a, sizeof(EmptyType) * NewCapasity);
		if (TempList == NULL)
		{
			perror("realloc error:");
		}
		ps->a = TempList;
		ps->capasity = NewCapasity;
	}
}

//10.ָ��λ�ò���Ԫ��
//����1����������
//����0��λ�ò��Ϸ�
int InsertByLocation(SQList* ps ,int location, EmptyType element) {
	CheckSpace(ps);
	if (location <= 0 || location > ps->size + 1)
		return 0;//λ�ò��Ϸ�
	if (ps->size == 0)//˳���Ϊ��ʱ
	{
		*(ps->a) = element;
		ps->size = 1;
		return 1;
	}
	for (int i = ps->size - 1; i >= location - 1; i--)
		*(ps->a + i + 1) = *(ps->a + i);
	*(ps->a + location - 1) = element;
	ps->size++;
	return 1;
}

//11.ɾ��ָ��λ��Ԫ��
//����1������ɾ��
//����0��λ�ò��Ϸ�
int DeleteByLocation(SQList* ps, int location) {
	//0 1  2  3 4 5 6 7
	//1 2 _3_ 4 5 6 7 8
	//- -  -  - -
	if (location <= 0 || location > ps->size || ps->size == 0)
		return 0;//λ�ò��Ϸ�

	for (int i = location - 1; i < ps->size - 1; i++)
		*(ps->a + i) = *(ps->a + i + 1);
	ps->size--;
	return 1;
}

//12.����Ԫ��ֵ��ɾ��ָ��Ԫ��
//����0��Ԫ�ز��Ϸ�
//����1������ɾ��
int DeleteByElement(SQList* ps, EmptyType element) {
	int i = 0;
	int Captcha = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (*(ps->a + i) == element)
		{
			DeleteByLocation(ps, i + 1);
			Captcha = 1;
		}
	}
	return Captcha;
}

//13.�����Ա��������
void SortSQList(SQList* ps) {
	for (int i = 0; i < ps->size - 1; i++)
	{
		for (int j = 0; j < ps->size - 1 - i; j++)
		{
			if (*(ps->a + j) > *(ps->a + j + 1))
			{
				EmptyType temp = *(ps->a + j);
				*(ps->a + j) = *(ps->a + j + 1);
				*(ps->a + j + 1) = temp;
			}
		}
	}
}

//14.��ʾ˳���
void ShowSQList(SQList* ps)
{
	printf("��ʾ˳���");
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", *(ps->a + i));
	}
	printf("\n");
}

//˳���ȥ��
void Deduplication(SQList* ps){
	if (ps->size < 2)
		return;
	int cur = 1;
	while (cur != ps->size)
	{
		if (*(ps->a + cur) == *(ps->a + cur - 1))
		{
			DeleteByLocation(ps, cur);
			continue;
		}
		cur++;
	}
}



//case1 case2
//�����˵���
//˳��� SQList* s 
//״̬ char** statex 
//״̬���� short* stateCodex
//˳������� char* ListName
void OperateMenu(SQList* s, char** statex, short* stateCodex, char* ListName)
{
	int location; //��¼λ��
	EmptyType element; //��¼Ԫ��
	EmptyType Captcha;//��¼�Ƿ�Ϸ�
	int input = 0;//�˵�ѡ��
	do {
		State = *statex;
		StateCode = *stateCodex;
		Operands = ListName;
		PrintMenu2();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			InitSQList(s);
			*statex = "�ѳ�ʼ��";
			*stateCodex = 1;
			printf("��ʼ���ɹ���\n");
			break;
		case 2:
			if (!CheckAction(*stateCodex))
				break;
			DestroyedSQList(s);
			*statex = "������  ";
			*stateCodex = 2;
			printf("���ٳɹ���\n");
			break;
		case 3:
			if (!CheckAction(*stateCodex))
				break;
			EmptySQList(s);
			printf("��ճɹ���\n");
			break;
		case 4:
			if (!CheckAction(*stateCodex))
				break;
			if (JudgmentEmpty(s))
				printf("˳���Ϊ��\n");
			else
				printf("˳���Ϊ��\n");
			break;
		case 5:
			if (!CheckAction(*stateCodex))
				break;
			printf("˳�����Ϊ��%d\n", SQListLength(s));
			break;
		case 6:
			if (!CheckAction(*stateCodex))
				break;
			printf("���������Ԫ��λ�ã�");
			scanf("%d", &location);
			Captcha = SearchElement(s, location);
			if (Captcha == -1)
				printf("λ�ò��Ϸ���\n");
			else
				printf("λ��%d�ϵ�Ԫ��Ϊ��%d\n", location, Captcha);
			break;
		case 7:
			if (!CheckAction(*stateCodex))
				break;
			printf("���������λ�õ�Ԫ�أ�");
			scanf("%d", &element);
			location = SearchLocation(s, element);
			if (location < 0)
				printf("δ�ҵ���Ԫ��\n");
			else
				printf("��Ԫ��λ��Ϊ��%d\n", location);
			break;
		case 8:
			if (!CheckAction(*stateCodex))
				break;
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			SearchPrecursor(s, element);
			break;
		case 9:
			if (!CheckAction(*stateCodex))
				break;
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			SearchBack(s, element);
			break;
		case 10:
			if (!CheckAction(*stateCodex))
				break;
			printf("���������λ�ã�");
			scanf("%d", &location);
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			if (!InsertByLocation(s, location, element))
				printf("λ�ò��Ϸ�������ʧ�ܣ�\n");
			else
				printf("����ɹ���\n");
			break;
		case 11:
			if (!CheckAction(*stateCodex))
				break;
			printf("�������ɾ��λ�ã�");
			scanf("%d", &location);
			Captcha = DeleteByLocation(s, location);
			if (Captcha == 0)
				printf("ɾ��ʧ�ܣ�λ�ò��Ϸ���\n");
			else
				printf("ɾ���ɹ���\n");
			break;
		case 12:
			if (!CheckAction(*stateCodex))
				break;
			printf("�������ɾ��Ԫ�أ�");
			scanf("%d", &element);
			Captcha = DeleteByElement(s, element);
			if (Captcha == 0)
				printf("ɾ��ʧ�ܣ�Ԫ�ز��Ϸ���\n");
			else
				printf("ɾ���ɹ���\n");
			break;
		case 13:
			if (!CheckAction(*stateCodex))
				break;
			SortSQList(s);
			printf("������\n");
			break;
		case 14:
			if (!CheckAction(*stateCodex))
				break;
			ShowSQList(s);
			break;
		case 15:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input != 15);
}

//case3
//�ϲ������ǵݼ���������Ա�
SQList* MergeList(SQList* ps, SQList* pss, SQList* temp)
{
	//����һ��������˳������ڴ洢�ϲ����˳���
	temp->capasity = ps->capasity + ps->capasity;
	temp->size = ps->size + pss->size;
	EmptyType* newtemp = (EmptyType*)malloc(sizeof(EmptyType) * temp->capasity);
	if (newtemp == NULL)
		perror("malloc error:");
	temp->a = newtemp;

	//����������β����
	for (int i = 0; i < ps->size; i++)
		*(temp->a + i) = *(ps->a + i);
	for (int i = ps->size; i < temp->size; i++)
		*(temp->a + i) = *(pss->a + i - ps->size);

	//����
	SortSQList(temp);

	//ȥ��
	Deduplication(temp);

	return temp;
}

int main() {
	int input = 0;//һ���˵�ѡ��
	SQList s;//˳���a
	SQList ss;//˳���b
	SQList temp;//�ϲ���˳���
	do {
		PrintMenu1();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			OperateMenu(&s, &StateA, &StateCodeA,"˳���A");
			break;
		case 2:
			OperateMenu(&ss, &StateB, &StateCodeB,"˳���B");
			break;
		case 3:
		{
			if (!(CheckAction(StateCodeB)&&CheckAction(StateCodeA)))
				break;
			InitSQList(&temp);
			MergeList(&s, &ss,&temp);
			ShowSQList(&temp);
			break;
		}
		case 4:
			printf("�����˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input != 4);
	return 0;
}