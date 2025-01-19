#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void PrintMenu()
{
	printf("**************************\n");
	printf("*      1.��ʼ������      *\n");
	printf("*      2.��β�����      *\n");
	printf("*      3.��ͷ������      *\n");
	printf("*   4.��ȡ����ͷ��Ԫ��   *\n");
	printf("*   5.��ȡ���ж�βԪ��   *\n");
	printf("* 6.��ȡ������ЧԪ�ظ��� *\n");
	printf("*    7.����Ƿ�Ϊ��      *\n");
	printf("*        8.���ٶ���      *\n");
	printf("*        9.�������      *\n");
	printf("*        0.�˳�����      *\n");
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
		printf("������ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			QueueInit(&q);
			printf("��ʼ���ɹ�\n");
			break;
		case 2:
			printf("�������������ݣ�");
			scanf("%d", &data);
			QueuePush(&q, data);
			break;
		case 3:
			QueuePop(&q);
			printf("ɾ���ɹ�\n");
			break;
		case 4:
			printf("��ͷԪ��Ϊ��%d\n", QueueFront(&q));
			break;
		case 5:
			printf("��βԪ��Ϊ��%d\n", QueueBack(&q));
			break;
		case 6:
			printf("����Ԫ�ظ���Ϊ��%d\n", QueueSize(&q));
			break;
		case 7:
			if (QueueEmpty(&q) == 0)
			{
				printf("����\n");
			}
			else {
				printf("��\n");
			}
			break;
		case 8:
			QueueDestroy(&q);
			printf("���ٳɹ�\n");
			break;
		case 9:
			PrintQueue(&q);
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input != 0);
	return 0;
}