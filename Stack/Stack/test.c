#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"

void Menu()
{
	printf("***********************\n");
	printf("*  1.初始化           *\n");
	printf("*  2.入栈             *\n");
	printf("*  3.出栈             *\n");
	printf("*  4.获取栈顶元素     *\n");
	printf("*  5.获取有效元素个数 *\n");
	printf("*  6.判空             *\n");
	printf("*  7.销毁栈           *\n");
	printf("*  8.输出栈           *\n");
	printf("***********************\n");
}

int main()
{
	int input = 0;
	int data = 0;
	Stack s;
	Menu();
	do {	
		printf("请输入选项：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//初始化
			StackInit(&s);
			break;
		case 2:
			//入栈
			printf("请输入数据：");
			scanf("%d", &data);
			StackPush(&s, data);
			break;
		case 3:
			//出栈
			StackPop(&s);
			break;
		case 4:
			//获取栈顶元素
			printf("%d\n",StackTop(&s));
			break;
		case 5:
			//获取栈中有效元素个数
			printf("%d\n", StatckSize(&s));
			break;
		case 6:
			//检测是否为空
			if (StackEmpty(&s) == 0)
			{
				printf("不为空\n");
			}
			else {
				printf("为空\n");
			}
			break;
		case 7:
			//销毁栈
			StackDestroy(&s);
			break;
		case 8:
			//输出栈
			PrintStack(&s);
			break;
		default:
			break;
		}
	} while (input != 0);
	return 0;
}