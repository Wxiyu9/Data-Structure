#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 状态码定义
#define FIRST_ELEMENT   1 // 目标元素是第一个元素
#define NO_PREDECESSOR  2 // 未找到目标元素
#define HAS_PREDECESSOR 3 // 找到目标元素的前驱

#define LAST_ELEMENT_NO_SUCCESSOR 1 // 目标元素是最后一个元素，没有后驱
#define NO_SUCCESSOR              2 // 未找到目标元素
#define HAS_SUCCESSOR             3 // 找到目标元素的后驱


typedef int SLTDataType;

//定义链表节点结构体
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//菜单打印
void PrintMenu()
{
	printf("**********************************\n");
	printf("*                                *\n");
	printf("*       1.初始化或重置链表       *\n");
	printf("*           2.销毁链表           *\n");
	printf("*         3.清空链表             *\n");
	printf("*         4.链表长度             *\n");
	printf("*       5.指定位置的元素值       *\n");
	printf("*     6.链表已存在元素的位序     *\n");
	printf("*     7.求输入元素的直接前驱     *\n");
	printf("*     8.求输入元素的直接后继     *\n");
	printf("*    9.在第i个位置插入一个元素   *\n");
	printf("*        10.删除第i个元素        *\n");
	printf("*      11.输出有的链表元素       *\n");
	printf("* 12.初始化并用头/尾插法输入元素 *\n");
	printf("*     13.实现单链表的逆序存放    *\n");
	printf("*      14.实现单链表的排序       *\n");
	printf("*         15.退出程序            *\n");
	printf("*                                *\n");
	printf("**********************************\n");
}

//2.销毁链表
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

//1.初始化链表
void InitList(SListNode** pphead)
{
	SListDesTroy(pphead);
}

//3.清空链表
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

// 4.求链表长度
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
//5.根据位置寻找元素值
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

//6.根据元素寻找位置
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
	return -1;//该元素不存在
}

//查找
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

//创建新节点
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

//链表头插
void SLTPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}

//链表尾插
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

//链表尾删
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

//链表头删
void SLTPopFront(SListNode** pphead)
{
	assert(pphead && *pphead);
	SListNode* cur = *pphead;
	*pphead = (*pphead)->next;
	free(cur);
	cur = NULL;
}

// 7.求输入元素的直接前驱
int findPredecessor(SListNode* head, int target, int* predecessorValue) {
	assert(head);
	// 检查目标元素是否是第一个元素
	if (head->data == target) {
		return FIRST_ELEMENT; // 该元素是第一个元素
	}

	SListNode* current = head;

	while (current->next != NULL) {
		if (current->next->data == target) {
			*predecessorValue = current->data; // 返回前驱值
			return HAS_PREDECESSOR; // 正常返回前驱
		}
		current = current->next;
	}

	return NO_PREDECESSOR; // 未找到目标元素
}

// 8.求输入元素的直接后驱
int findSuccessor(SListNode* head, int target, int* successorValue) {
	assert(head);
	SListNode* current = head;

	while (current != NULL) {
		if (current->data == target) {
			if (current->next != NULL) {
				*successorValue = current->next->data;
				return HAS_SUCCESSOR; // 正常返回后驱
			}
			else {
				return LAST_ELEMENT_NO_SUCCESSOR; // 目标元素是最后一个元素
			}
		}
		current = current->next;
	}

	return NO_SUCCESSOR; // 未找到目标元素
}

//9.在指定位置之前插入数据

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
	if (pos == *pphead)//头插
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


// 10.删除第i个元素
// 返回0：位置不合法
// 返回1：删除成功
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

// 11.链表打印
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

// 12.初始化并用头插法或尾插法输入元素
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

// 12.逆置
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

// 13.排序
SListNode* SLTSort(SListNode* head)
{
	if (head == NULL || head->next == NULL) {
		return head;
	}

	int swapped; // 标志位，表示是否进行了交换
	SListNode* current;
	SListNode* lastSorted = NULL; // 最后一个已排序的节点

	do {
		swapped = 0; // 每次开始排序时重置标志位
		current = head;

		// 遍历链表
		while (current->next != lastSorted) {
			if (current->data > current->next->data) {
				// 交换数据
				int temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
				swapped = 1; // 设置标志位
			}
			current = current->next; // 移动到下一个节点
		}
		lastSorted = current; // 更新最后一个已排序的节点
	} while (swapped); // 如果进行了交换，继续排序

	return head; // 返回排序后的链表头节点
}

int main()
{
	SListNode* head = NULL;
	int location;
	int predecessorValue = 0; // 存储前驱节点的数据
	int successorValue = 0; // 存储后驱节点的数据
	SLTDataType element;
	SListNode* temp = NULL;
	int means; //插入模式选择
	PrintMenu();
	int input = 0;
	do {
		printf("请选择操作：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			InitList(&head);
			printf("初始化成功！\n");
			break;
		}
		case 2:
		{
			SListDesTroy(&head);
			printf("销毁成功！\n");
			break;
		}
		case 3:
		{
			if (EmptyList(&head))
				printf("清空成功！\n");
			else
				printf("链表为空或传参不合法，清空失败！\n");
			break;
		}
		case 4:
		{
			printf("链表长度为：%d\n", ListLength(head));
			break;
		}
		case 5:
		{
			printf("请输入要查找的位置：");
			scanf("%d", &location);
			SListNode* temp = SLTFindElement(head, location - 1);
			if (temp == NULL)
			{
				printf("位置不合法！\n");
			}
			else {
				printf("该位置的元素为：%d\n", temp->data);
			}
			break;
		}
		case 6:
		{
			printf("请输入要查找的元素：");
			scanf("%d", &element);
			int temp = SLTFindLocation(head, element);
			if (temp == -1)
				printf("该元素不存在\n");
			else
				printf("该元素为第%d个节点\n", temp);
			break;
		}
		case 7:
		{
			printf("请输入待查元素：");
			scanf("%d", &element);
			int result = findPredecessor(head, element, &predecessorValue);
			// 根据返回值输出提示信息
			switch (result) {
			case FIRST_ELEMENT:
				printf("该元素是第一个元素，没有前驱\n");
				break;
			case NO_PREDECESSOR:
				printf("无该元素\n");
				break;
			case HAS_PREDECESSOR:
				printf("元素 %d 的前驱是 %d\n", element, predecessorValue);
				break;
			}
			break;
		}
		case 8:
		{
			printf("请输入待查元素：");
			scanf("%d", &element);
			int result = findSuccessor(head, element, &successorValue);

			// 根据返回值输出提示信息
			switch (result) {
			case LAST_ELEMENT_NO_SUCCESSOR:
				printf("该元素是最后一个元素，没有后驱\n");
				break;
			case NO_SUCCESSOR:
				printf("无该元素\n");
				break;
			case HAS_SUCCESSOR:
				printf("元素 %d 的后驱是 %d\n", element, successorValue);
				break;
			}
			break;
		}
		case 9:
		{
			printf("请输入待插入位置：");
			scanf("%d", &location);
			printf("请输入元素：");
			scanf("%d", &element);
			int check = SLTInsert(&head, location-1, element);
			if (check == 0) {
				printf("位置不合法\n");
			}
			else {
				printf("插入成功\n");
			}
			break;
		}
		case 10:
		{
			printf("请输入待删除位置：");
			scanf("%d", &location);
			int result = DelNode(&head, location);
			if (result == 0)
				printf("位置不合法\n");
			else
				printf("删除成功\n");
			break;
		}
		case 11:
		{
			PrintList(head);
			break;
		}
		case 12:
		{
			printf("插入模式有\n1.头插法\n2.尾插法\n请你选择：");
			scanf("%d", &means);
			if (means == 1 || means == 2)
			{
				printf("请输入插入元素(-1结尾)：");
				InitAndInsert(&head, means);
				printf("插入成功\n");
			}
			else
			{
				printf("选择不合法\n");
			}
			break;
		}
		case 13:
		{
			head = SLTInverst(head);
			printf("逆置成功\n");
			break;
		}
		case 14:
		{
			head = SLTSort(head);
			printf("排序成功\n");
			break;
		}
		case 15:
		{
			printf("程序退出。。。\n");
			break;
		}
		default:
		{
			printf("输入错误，请重新输入:");
		}
		}
	} while (input != 15);
	return 0;
}