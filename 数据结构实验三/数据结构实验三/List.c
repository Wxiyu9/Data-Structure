#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
	printf("*         15.退出程序             *\n");
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

//链表尾插
void SLTPushBack(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newNode;
	}
	else
	{
		SListNode* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}

//链表头插
void SLTPushFront(SListNode** pphead, SLTDataType x)
{
	assert(pphead);
	SListNode* newNode = SLTBuyNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
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


//9.在指定位置之前插入数据
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x)
{
	assert(pphead && pos && *pphead);
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


//删除指定位置的数据
void SLTErase(SListNode** pphead, SListNode* pos)
{
	assert(pphead && *pphead && pos);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SListNode* curpre = *pphead;
		while (curpre->next != pos)
		{
			curpre = curpre->next;
		}
		curpre->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

//删除指定位置之后的数据
void SLTEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* cur = pos->next;
	pos->next = cur->next;
	free(cur);
	cur = NULL;
}



int main()
{
	SListNode* head = NULL;
	int location;
	SLTDataType element;
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
			printf("链表长度为：%d", ListLength(head));
			break;
		}
		case 5:
		{
			printf("请输入要查找的位置：");
			scanf("%d", &location);
			SListNode* temp = SLTFindElement(head, location);
			if (temp == NULL)
			{
				printf("位置不合法！\n");
			}
			else {
				printf("该位置的元素为：%d ", temp->data);
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
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			printf("请输入待插入位置：");
			scanf("%d", &location);
			if(location == 1)
			SListNode* temp = SLTFindElement(head, location-1);
			if (temp == NULL)
			{
				printf("位置不合法！\n");
				break;
			}
			printf("请输入插入元素：");
			scanf("%d", &element);
			SLTInsert(&head, temp, element);
			printf("输入成功！\n");
			break;
		}
		case 10:
		{
			break;
		}
		case 11:
		{
			PrintList(head);
			break;
		}
		case 12:
		{
			break;
		}
		case 13:
		{
			break;
		}
		case 14:
		{
			break;
		}
		case 15:
		{
			break;
		}
		default:
		{

		}
		}
	} while (input != 15);
	return 0;
}