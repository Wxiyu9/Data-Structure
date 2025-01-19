#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void PrintMenu()
{
	printf("**************************\n");
	printf("*      1.初始化队列      *\n");
	printf("*      2.队尾入队列      *\n");
	printf("*      3.队头出队列      *\n");
	printf("*   4.获取队列头部元素   *\n");
	printf("*   5.获取队列队尾元素   *\n");
	printf("* 6.获取队列有效元素个数 *\n");
	printf("*    7.检测是否为空      *\n");
	printf("*        8.销毁队列      *\n");
	printf("*        9.输出队列      *\n");
	printf("*        0.退出程序      *\n");
	printf("**************************\n");

}

void PrintQueue(Queue* q)
{
	QNode* pcur = q->_front;
	while (pcur)
	{
		printf("%d->", pcur->_data);
		pcur = pcur->_next;
	}
	printf("NULL\n");
}

int main()
{
	PrintMenu();
	int input = 0;
	QDataType data = 0;
	Queue q;
	do {
		printf("请输入选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			QueueInit(&q);
			printf("初始化成功\n");
			break;
		case 2:
			printf("请输入输入数据：");
			scanf("%d", &data);
			QueuePush(&q, data);
			break;
		case 3:
			QueuePop(&q);
			printf("删除成功\n");
			break;
		case 4:
			printf("队头元素为：%d\n", QueueFront(&q));
			break;
		case 5:
			printf("队尾元素为：%d\n", QueueBack(&q));
			break;
		case 6:
			printf("队列元素个数为：%d\n", QueueSize(&q));
			break;
		case 7:
			if (QueueEmpty(&q) == 0)
			{
				printf("不空\n");
			}
			else {
				printf("空\n");
			}
			break;
		case 8:
			QueueDestroy(&q);
			printf("销毁成功\n");
			break;
		case 9:
			PrintQueue(&q);
			break;
		case 0:
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input != 0);
	return 0;
}