#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

// 二叉树节点结构体

typedef char BiTreeDataType;
typedef struct BiTreeNode {
	struct BiTreeNode* lchild;
	struct BiTreeNode* rhild;
	BiTreeDataType data;
}Node;

// 1.创建二叉树
void CreateBiTree(Node** root) {
	assert(root);
	char ch = 0;
	scanf("%c", &ch);
	if (ch == '$') {
		*root = NULL;
	}
	else {
		*root = (Node*)malloc(sizeof(Node));
		(*root)->data = ch;
		CreateBiTree(&((*root)->lchild));
		CreateBiTree(&((*root)->rhild));
	}
}

// 2.先序遍历二叉树（递归）
void PreOrderTraversal(Node* root) {
	assert(root);
	if (root) {
		printf("%c", root->data);
		if (root->lchild != NULL) {
			PreOrderTraversal(root->lchild);
		}
		if ((root)->rhild != NULL) {
			PreOrderTraversal(root->rhild);
		}
	}
	return;
}


// ------------------  实现栈  ------------------
typedef Node STDataType;

//通过顺序表来实现栈
typedef struct Stack {
	STDataType* _a;
	int _top;		//栈顶
	int _capacity;	//容量
}Stack;

//初始化栈
void StackInit(Stack* ps) {
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

//检查空间是否足够
void CheckCapacity(Stack* ps)
{
	if (ps->_top == ps->_capacity)
	{
		int NewCapacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
		STDataType* NewA = (STDataType*)realloc(ps->_a, sizeof(STDataType) * NewCapacity);
		if (NewA == NULL)
		{
			perror("realloc fail");
		}
		ps->_capacity = NewCapacity;
		ps->_a = NewA;
	}
}

//入栈
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	CheckCapacity(ps);
	*(ps->_a + ps->_top) = data;
	ps->_top++;
}

//出栈
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	ps->_top--;
}

//获取栈顶元素
STDataType* StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	return (ps->_a + ps->_top - 1);
}

//检测栈是否为空，若为空则返回非零结果
//若不为空则返回0
int StackEmpty(Stack* ps) {
	return ps->_top == 0;
}

//销毁栈
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ------------------  实现栈结束  ------------------


// 3.中序遍历二叉树 非递归1
void MiddleOrderTraversal1(Node* root) {
	Stack s;
	StackInit(&s);
	Node* treeNode = root;
	while (!StackEmpty(&s) || treeNode) {
		while (treeNode) {
			StackPush(&s, *treeNode);
			treeNode = treeNode->lchild;
		}
		treeNode = StackTop(&s);
		printf("%c", treeNode->data);
		StackPop(&s);
		treeNode = treeNode->rhild;
	}
	StackDestroy(&s);
}

// 4.中序遍历二叉树 非递归2
void MiddleOrderTraversal2(Node* root) {
	Stack s;
	StackInit(&s);
	Node* treeNode = root;
	while (!StackEmpty(&s) || treeNode) {
		if (treeNode) {
			StackPush(&s, *treeNode);
			treeNode = treeNode->lchild;
		}
		else {
			treeNode = StackTop(&s);
			printf("%c", treeNode->data);
			StackPop(&s);
			treeNode = treeNode->rhild;
		}
	}
	StackDestroy(&s);
}

// 5.后序遍历二叉树（递归）
void PostOrderTraversal(Node* root) {
	if (root) {
		if (root->lchild != NULL) {
			PostOrderTraversal(root->lchild);
		}
		if (root->rhild != NULL) {
			PostOrderTraversal(root->rhild);
		}
		printf("%c", root->data);
	}
	return;
}

// ----------------------  实现队列  ----------------------

typedef Node* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;

	//size_t size;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueueClear(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		cur->data = 0;
		cur = cur->next;
	}
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		assert(pq->head == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//return pq->head == NULL && pq->tail == NULL;
	return pq->head == NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);
	return pq->tail->data;
}

// ------------------  实现队列结束  -------------------

// 6.层序遍历二叉树
void SequenceTraversal(Node* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	Node* temp = root;
	while (!QueueEmpty(&q)) {
		if (QueueFront(&q)->lchild) {
			QueuePush(&q, QueueFront(&q)->lchild);
		}
		if (QueueFront(&q)->rhild) {
			QueuePush(&q, QueueFront(&q)->rhild);
		}
		temp = QueueFront(&q);
		QueuePop(&q);
		printf("%c", temp->data);
	}
	QueueDestory(&q);
}

// 7.求二叉树的深度
int BiTreeDepth(Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int Ldepth = BiTreeDepth(root->lchild);
		int Rdepth = BiTreeDepth(root->rhild);
		return (Ldepth > Rdepth ? Ldepth : Rdepth) + 1;
	}
}

// 8.求非叶子结点的个数
int NonLeafNum(Node* root) {
	Stack s;
	int num = 0;
	StackInit(&s);
	Node* treeNode = root;
	while (!StackEmpty(&s) || treeNode) {
		while (treeNode) {
			StackPush(&s, *treeNode);
			treeNode = treeNode->lchild;
		}
		treeNode = StackTop(&s);
		if (treeNode->lchild || treeNode->rhild)
			num++;
		StackPop(&s);
		treeNode = treeNode->rhild;
	}
	StackDestroy(&s);
	return num;
}


void Menu() {
	printf("**************************************\n");
	printf("***                                ***\n");
	printf("***     1.创建二叉树               ***\n");
	printf("***     2.先序遍历二叉树（递归）   ***\n");
	printf("***     3.中序遍历二叉树（非递归1）***\n");
	printf("***     4.中序遍历二叉树（非递归2）***\n");
	printf("***     5.后序遍历二叉树（递归）   ***\n");
	printf("***     6.层序遍历二叉树           ***\n");
	printf("***     7.求二叉树的深度           ***\n");
	printf("***     8.求非叶子结点的个数       ***\n");
	printf("***     9.退出                     ***\n");
	printf("***                                ***\n");
	printf("**************************************\n");
}

int main() {
	int input = 0;
	Node *root = NULL;
	Menu();
	do {
		printf("请选择：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("请输入树：");
			getchar();
			CreateBiTree(&root);
			printf("输入成功\n");
			break;
		case 2:
			printf("先序遍历结果为：");
			PreOrderTraversal(root);
			printf("\n");
			break;
		case 3:
			printf("中序遍历结果为：");
			MiddleOrderTraversal1(root);
			printf("\n");
			break;
		case 4:
			printf("中序遍历结果为：");
			MiddleOrderTraversal2(root);
			printf("\n");
			break;
		case 5:
			printf("后序遍历结果为：");
			PostOrderTraversal(root);
			printf("\n");
			break;
		case 6:
			printf("层序遍历结果为：");
			SequenceTraversal(root);
			printf("\n");
			break;
		case 7:
			printf("树的深度为：%d\n", BiTreeDepth(root));
			break;
		case 8:
			printf("树的非叶子节点个数为：%d\n", NonLeafNum(root));
			break;
		case 9:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} //do-while
	while (input != 9);
	return 0;
}//main