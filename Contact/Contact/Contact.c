#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "SeqList.h"

//ʵ��ͨѶ¼��ز�������

//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con)
{
	SLInit(con);
}

//ͨѶ¼������
void ContactDestroy(Contact* con)
{
	SLDestroy(con);
}

//ͨѶ¼�������
void ContactAdd(Contact* con)
{
	peoInfo info;
	printf("������Ҫ��ӵ���ϵ��������");
	scanf("%s", info.name);

	printf("������Ҫ��ӵ���ϵ���Ա�");
	scanf("%s", info.gender);

	printf("������Ҫ��ӵ���ϵ�����䣺");
	scanf("%d", &info.age);

	printf("������Ҫ��ӵ���ϵ�˵绰��");
	scanf("%s", info.tel);

	printf("������Ҫ��ӵ���ϵ�˵�ַ��");
	scanf("%s", info.addr);

	//����Ϣ��ӵ�ͨѶ¼��
	SLPushBack(con, info);
}

//�����ֲ�����ϵ��
int FindByName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (!strcmp(con->arr->name, name))
		{
			//�ҵ���
			return i;
		}
	}
	//û�ҵ�
	return -1;
}
//ͨѶ¼ɾ������
void ContactDel(Contact* con)
{
	//�ж�Ҫɾ������ϵ���Ƿ����
	char name[NAME_MAX];
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("����ϵ�˲����ڣ�");
		return;
	}
	//��ϵ�˴��ڣ�ɾ������ϵ��
	SLErase(con, find);
	printf("ɾ�����\n");
}

//ͨѶ¼���޸�
void ContactModify(Contact* con)
{
	//�ж�Ҫɾ������ϵ���Ƿ����
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ�ˣ�");
	scanf("%s", name);
	int find = FindByName(con, name);
	if (find < 0)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	//��ϵ�˴��ڣ��޸���Ϣ
	printf("�������µ�������");
	scanf("%s", con->arr[find].name);
	printf("�������µ��Ա�");
	scanf("%s", con->arr[find].gender);
	printf("�������µ����䣺");
	scanf("%d", con->arr[find].age);
	printf("�������µĵ绰��");
	scanf("%s", con->arr[find].tel);
	printf("�������µĵ�ַ��");
	scanf("%s", con->arr[find].addr);
}

//ͨѶ¼����
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ��������")��
}

//��ӡͨѶ¼����
void ContactShow(Contact* con);