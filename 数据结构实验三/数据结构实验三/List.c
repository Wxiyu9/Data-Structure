#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// ״̬�붨��
#define FIRST_ELEMENT   1 // Ŀ��Ԫ���ǵ�һ��Ԫ��
#define NO_PREDECESSOR  2 // δ�ҵ�Ŀ��Ԫ��
#define HAS_PREDECESSOR 3 // �ҵ�Ŀ��Ԫ�ص�ǰ��

#define LAST_ELEMENT_NO_SUCCESSOR 1 // Ŀ��Ԫ�������һ��Ԫ�أ�û�к���
#define NO_SUCCESSOR              2 // δ�ҵ�Ŀ��Ԫ��
#define HAS_SUCCESSOR             3 // �ҵ�Ŀ��Ԫ�صĺ���


typedef int SLTDataType;

//��������ڵ�ṹ��
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//�˵���ӡ
void PrintMenu()
{
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*       1.��ʼ������������       *\n");
	printf("*           2.��������           *\n");
	printf("*         3.�������             *\n");
	printf("*         4.������             *\n");
	printf("*       5.ָ��λ�õ�Ԫ��ֵ       *\n");
	printf("*     6.�����Ѵ���Ԫ�ص�λ��     *\n");
	printf("*     7.������Ԫ�ص�ֱ��ǰ��     *\n");
	printf("*     8.������Ԫ�ص�ֱ�Ӻ��     *\n");
	printf("*    9.�ڵ�i��λ�ò���һ��Ԫ��   *\n");
	printf("*        10.ɾ����i��Ԫ��        *\n");
	printf("*      11.����е�����Ԫ��       *\n");
	printf("* 12.��ʼ������ͷ/β�巨����Ԫ�� *\n");
	printf("*     13.ʵ�ֵ������������    *\n");
	printf("*      14.ʵ�ֵ����������       *\n");
	printf("*         15.�˳�����            *\n");
	printf("*                                *\n");
	printf("**********************************\n");
}

//2.��������
void SListDesTroy(SListNode** pphead)
{
	assert(pphead);
	SListNode* temp = *pphead;
	while (temp)
	{
		SListNode* next = temp->next;
		free(temp);
		temp = next;
	}
	*pphead = NULL;
}

//1.��ʼ������
void InitList(SListNode** pphead)
{
	SListDesTroy(pphead);
}

//3.�������
int EmptyList(SListNode** pphead)
{
	if (pphead == NULL || *pphead == NULL)
	{
		return 0;
	}
	SListNode* cur = *pphead;
	while (cur)
	{
		cur->data = 0;
		cur = cur->next;
	}
	return 1;
}

// 4.��������
int ListLength(SListNode* phead)
{
	int Length = 0;
	SListNode* cur = phead;
	while (cur)
	{
		Length++;
		cur = cur->next;
	}
	return Length;
}
//5.����λ��Ѱ��Ԫ��ֵ
SListNode* SLTFindElement(SListNode* phead, int location)
{
	SListNode* cur = phead;
	int times = 0;
	//20 10 NULL
	
	while (cur)
	{
		if (times == location)
			return cur;
		cur = cur->next;
		times++;
	}
	return NULL;
}

//6.����Ԫ��Ѱ��λ��
int SLTFindLocation(SListNode* phead, SLTDataType x)
{
	int location = 0;
	SListNode* cur = phead;
	while (cur)
	{
		location++;
		if (x == cur->data)
			return location;
		cur = cur->next;
	}
	return -1;//��Ԫ�ز�����
}

//����
SListNode* SLTFind(SListNode* phead, SLTDataType x)
{
	SListNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//�����½ڵ�
SListNode* SLTBuyNode(SLTDataType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
	{
		perror("malloc error");
		exit(1);
	}

	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

//����ͷ��
void SLTPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//����β��
void SLTPushBack(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode** pcur = pphead;
	SListNode* NewNode = SLTBuyNode(x);
	if (*pcur == NULL)
	{
		*pcur = NewNode;
	}
	else {
		while ((*pcur)->next)
		{
			pcur = &((*pcur)->next);
		}
		(*pcur)->next = NewNode;
	}

}

//����βɾ
void SLTPopBack(SListNode** pphead)
{
	assert(*pphead && pphead);
	SListNode* cur = *pphead;
	SListNode* curpre = *pphead;
	if ((*pphead)->next == NULL)
	{
		free((*pphead));
		*pphead = NULL;
	}
	else
	{
		//1 2 3 null
		while (cur->next)
		{
			curpre = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		curpre->next = NULL;
	}
}

//����ͷɾ
void SLTPopFront(SListNode** pphead)
{
	assert(pphead && *pphead);
	SListNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

// 7.������Ԫ�ص�ֱ��ǰ��
int findPredecessor(SListNode* head, int target, int* predecessorValue) {
	assert(head);
	// ���Ŀ��Ԫ���Ƿ��ǵ�һ��Ԫ��
	if (head->data == target) {
		return FIRST_ELEMENT; // ��Ԫ���ǵ�һ��Ԫ��
	}

	SListNode* current = head;

	while (current->next != NULL) {
		if (current->next->data == target) {
			*predecessorValue = current->data; // ����ǰ��ֵ
			return HAS_PREDECESSOR; // ��������ǰ��
		}
		current = current->next;
	}

	return NO_PREDECESSOR; // δ�ҵ�Ŀ��Ԫ��
}

// 8.������Ԫ�ص�ֱ�Ӻ���
int findSuccessor(SListNode* head, int target, int* successorValue) {
	assert(head);
	SListNode* current = head;

	while (current != NULL) {
		if (current->data == target) {
			if (current->next != NULL) {
				*successorValue = current->next->data;
				return HAS_SUCCESSOR; // �������غ���
			}
			else {
				return LAST_ELEMENT_NO_SUCCESSOR; // Ŀ��Ԫ�������һ��Ԫ��
			}
		}
		current = current->next;
	}

	return NO_SUCCESSOR; // δ�ҵ�Ŀ��Ԫ��
}

//9.��ָ��λ��֮ǰ��������

int SLTInsert(SListNode** pphead, int location, SLTDataType x)
{
	//0
	assert(pphead);
	SListNode* pcur = *pphead;
	int num = 0;
	while (pcur)
	{
		num++;
		pcur = pcur->next;
	}
	if (location > num || location < 0)
	{
		return 0;
	}
	else {
		pcur = *pphead;
		if (pcur == NULL)
		{
			SLTPushFront(pphead, x);
			return 1;
		}
		while (num)
		{
			num--;
			pcur = pcur->next;
		}
		if (pcur == NULL)
		{
			SLTPushBack(pphead, x);
			return 1;
		}
		SListNode* newNode = SLTBuyNode(x);
		SListNode* temp = pcur->next;
		pcur->next = newNode;
		newNode->next = temp;
		return 1;
	}
}


/*
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	if (pos == *pphead)//ͷ��
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		newNode->next = pos;
		cur->next = newNode;
	}
}
*/


// 10.ɾ����i��Ԫ��
// ����0��λ�ò��Ϸ�
// ����1��ɾ���ɹ�
int DelNode(SListNode** pphead, int location)
{
	int length = ListLength(*pphead);
	if (location < 0 || location > length)
		return 0;
	if (location == 1)
	{
		SLTPopFront(pphead);
		return 1;
	}
	SListNode* delpre = *pphead;
	for (int i = 0; i < location - 2; i++)
	{
		delpre = delpre->next;//1 2 3 4 5
	}
	SListNode* del = delpre->next;
	delpre->next = delpre->next->next;
	free(del);
	del = NULL;
	return 1;
}

// 11.�����ӡ
void PrintList(SListNode* phead)
{
	SListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 12.��ʼ������ͷ�巨��β�巨����Ԫ��
void InitAndInsert(SListNode** pphead,int means)
{
	InitList(pphead);
	int x = 0;
	if (means == 1)
	{
		while (1) {
			scanf("%d", &x);
			if (x == -1)
				break;
			SLTPushFront(pphead, x);
		}
	}
	else {
		while (1) {
			scanf("%d", &x);
			if (x == -1)
				break;
			SLTPushBack(pphead, x);
		}
	}
}

// 12.����
SListNode* SLTInverst(SListNode* phead)
{
	// 1 2 3
	assert(phead);
	SListNode* cur = phead;
	SListNode* curpre = NULL;
	while (cur != NULL)
	{
		SListNode* temp = cur->next;
		cur->next = curpre;
		curpre = cur;
		cur = temp;
	}
	return curpre;
}

// 13.����
SListNode* SLTSort(SListNode* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}

	int swapped; // ��־λ����ʾ�Ƿ�����˽���
	SListNode* current;
	SListNode* lastSorted = NULL; // ���һ��������Ľڵ�

	do {
		swapped = 0; // ÿ�ο�ʼ����ʱ���ñ�־λ
		current = head;

		// ��������
		while (current->next != lastSorted) {
			if (current->data > current->next->data) {
				// ��������
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1; // ���ñ�־λ
			}
			current = current->next; // �ƶ�����һ���ڵ�
		}
		lastSorted = current; // �������һ��������Ľڵ�
	} while (swapped); // ��������˽�������������

	return head; // ��������������ͷ�ڵ�
}

int main()
{
	SListNode* head = NULL;
	int location;
	int predecessorValue = 0; // �洢ǰ���ڵ������
	int successorValue = 0; // �洢�����ڵ������
	SLTDataType element;
	SListNode* temp = NULL;
	int means; //����ģʽѡ��
	PrintMenu();
	int input = 0;
	do {
		printf("��ѡ�������");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			InitList(&head);
			printf("��ʼ���ɹ���\n");
			break;
		}
		case 2:
		{
			SListDesTroy(&head);
			printf("���ٳɹ���\n");
			break;
		}
		case 3:
		{
			if (EmptyList(&head))
				printf("��ճɹ���\n");
			else
				printf("����Ϊ�ջ򴫲β��Ϸ������ʧ�ܣ�\n");
			break;
		}
		case 4:
		{
			printf("������Ϊ��%d\n", ListLength(head));
			break;
		}
		case 5:
		{
			printf("������Ҫ���ҵ�λ�ã�");
			scanf("%d", &location);
			SListNode* temp = SLTFindElement(head, location - 1);
			if (temp == NULL)
			{
				printf("λ�ò��Ϸ���\n");
			}
			else {
				printf("��λ�õ�Ԫ��Ϊ��%d\n", temp->data);
			}
			break;
		}
		case 6:
		{
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &element);
			int temp = SLTFindLocation(head, element);
			if (temp == -1)
				printf("��Ԫ�ز�����\n");
			else
				printf("��Ԫ��Ϊ��%d���ڵ�\n", temp);
			break;
		}
		case 7:
		{
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			int result = findPredecessor(head, element, &predecessorValue);
			// ���ݷ���ֵ�����ʾ��Ϣ
			switch (result) {
			case FIRST_ELEMENT:
				printf("��Ԫ���ǵ�һ��Ԫ�أ�û��ǰ��\n");
				break;
			case NO_PREDECESSOR:
				printf("�޸�Ԫ��\n");
				break;
			case HAS_PREDECESSOR:
				printf("Ԫ�� %d ��ǰ���� %d\n", element, predecessorValue);
				break;
			}
			break;
		}
		case 8:
		{
			printf("���������Ԫ�أ�");
			scanf("%d", &element);
			int result = findSuccessor(head, element, &successorValue);

			// ���ݷ���ֵ�����ʾ��Ϣ
			switch (result) {
			case LAST_ELEMENT_NO_SUCCESSOR:
				printf("��Ԫ�������һ��Ԫ�أ�û�к���\n");
				break;
			case NO_SUCCESSOR:
				printf("�޸�Ԫ��\n");
				break;
			case HAS_SUCCESSOR:
				printf("Ԫ�� %d �ĺ����� %d\n", element, successorValue);
				break;
			}
			break;
		}
		case 9:
		{
			printf("�����������λ�ã�");
			scanf("%d", &location);
			printf("������Ԫ�أ�");
			scanf("%d", &element);
			int check = SLTInsert(&head, location-1, element);
			if (check == 0) {
				printf("λ�ò��Ϸ�\n");
			}
			else {
				printf("����ɹ�\n");
			}
			break;
		}
		case 10:
		{
			printf("�������ɾ��λ�ã�");
			scanf("%d", &location);
			int result = DelNode(&head, location);
			if (result == 0)
				printf("λ�ò��Ϸ�\n");
			else
				printf("ɾ���ɹ�\n");
			break;
		}
		case 11:
		{
			PrintList(head);
			break;
		}
		case 12:
		{
			printf("����ģʽ��\n1.ͷ�巨\n2.β�巨\n����ѡ��");
			scanf("%d", &means);
			if (means == 1 || means == 2)
			{
				printf("���������Ԫ��(-1��β)��");
				InitAndInsert(&head, means);
				printf("����ɹ�\n");
			}
			else
			{
				printf("ѡ�񲻺Ϸ�\n");
			}
			break;
		}
		case 13:
		{
			head = SLTInverst(head);
			printf("���óɹ�\n");
			break;
		}
		case 14:
		{
			head = SLTSort(head);
			printf("����ɹ�\n");
			break;
		}
		case 15:
		{
			printf("�����˳�������\n");
			break;
		}
		default:
		{
			printf("�����������������:");
		}
		}
	} while (input != 15);
	return 0;
}