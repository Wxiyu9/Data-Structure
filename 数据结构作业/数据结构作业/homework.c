#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int NodeType;

//��������
typedef struct Gather {
	NodeType data;
	struct Gather* next;
}Gat;

void PrintMenu()
{
	printf("**************************************\n");
	printf("******     1.���뼯��A��B       ******\n");
	printf("******     2.�󼯺�A��B         ******\n");
	printf("******     3.�󼯺�A��B         ******\n");
	printf("******     4.�󼯺�A-B          ******\n");
	printf("******   5.�ж�A�Ƿ���B���Ӽ�   ******\n");
	printf("******    �˳�������һ��������  ******\n");
	printf("**************************************\n");
}

//�ж������Ƿ����
int Judgment(Gat* phead, NodeType num) {
	Gat* cur = phead;
	while (cur)
	{
		if (cur->data == num)
			return 1;//����
		cur = cur->next;
	}
	return 0;//������
}

//�����ڵ�
Gat* CreatNode(NodeType x) {
	Gat* Node = (Gat*)malloc(sizeof(Gat));
	Node->data = x;
	Node->next = NULL;
	return Node;
}

//����β������
void PushBack(Gat** pphead, NodeType x) {
	assert(pphead);
	Gat* NewNode = CreatNode(x);
	//������
	if (*pphead == NULL)
	{
		*pphead = NewNode;
	}
	else {
		Gat* cur = *pphead;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = NewNode;
	}
}

//��������
void DesList(Gat** pphead)
{
	Gat* cur = *pphead;
	while (cur)
	{
		Gat* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//��������
void Input(Gat** pphead, int n){
	DesList(pphead);
	printf("���������ݣ�");
	for (int i = 0; i < n; i++)
	{
		NodeType num = 0;
		scanf("%d", &num);
		if (Judgment(*pphead, num))
		{
			printf("%d�Ѵ��ڣ��������������\n",num);
			i--;
		}
		else {
			PushBack(pphead, num);
		}
	}
	printf("����ɹ���\n");

}

//�󼯺Ͻ���
void Jiaoji(Gat* pheada, int na, Gat* pheadb, int nb) {
	printf("�����Ͻ���Ϊ��{");
	Gat* cur = pheada;
	while (cur)
	{
		if (Judgment(pheadb, cur->data))
			printf(" %d ", cur->data);
		cur = cur->next;
	}
	printf("}\n");
}

//�󼯺ϲ���
void Bingji(Gat* pheada, Gat* pheadb) {
	printf("�����ϵĲ���Ϊ��{");
	Gat* cur = pheada;
	//��������A
	while (cur)
	{
		if (!Judgment(pheadb, cur->data))
			printf(" %d ", cur->data);
		cur = cur->next;
	}
	Gat* curb = pheadb;
	while (curb)
	{
		printf(" %d ", curb->data);
		curb = curb->next;
	}
	//��������B
	printf("}\n");
}

//�󼯺����
void Jian(Gat* pheada, Gat* pheadb) {
	printf("������������Ϊ��{");
	Gat* cur = pheada;
	while (cur)
	{
		if (!Judgment(pheadb, cur->data))
			printf(" %d ", cur->data);
		cur = cur->next;
	}
	printf("}\n");
}

//�ж��Ƿ�Ϊ�Ӽ�
int Panduan(Gat* pheada, Gat* pheadb) {
	Gat* cur = pheada;
	while (cur)
	{
		if (!Judgment(pheadb, cur->data))
			return 0;//�����Ӽ�
		cur = cur->next;
	}
	return 1;//���Ӽ�
}

int main()
{
	Gat* pheada = NULL;
	Gat* pheadb = NULL;
	int na = 0;
	int nb = 0;
	int input = 0;
	do {
		PrintMenu();
		printf("��ѡ��");
		scanf("%d", &input);
		getchar();
		if (input < 0)
		{
			printf("�����˳�");
			break;
		}
		switch (input) {
		case 1:
			printf("�����뼯��A���ݸ�����");
			scanf("%d", &na);
			Input(&pheada,na);
			printf("�����뼯��B���ݸ�����");
			scanf("%d", &nb);
			Input(&pheadb,nb);
			break;
		case 2:
			Jiaoji(pheada,na,pheadb,nb);
			break;
		case 3:
			Bingji(pheada,pheadb);
			break;
		case 4:
			Jian(pheada, pheadb);
			break;
		case 5:
			if (Panduan(pheada, pheadb))
				printf("����A�Ǽ���B���Ӽ�\n");
			else
				printf("����A���Ǽ���B���Ӽ�\n");
			break;
		default:
			printf("����������������룡\n");
		}
	} while (1);
	return 0;
}