#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

// �ѵĳ�ʼ��
void HeapInit(Heap* php) {
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// �ѵ����ϵ���
void AdjustUp(HPDataType* a, int child) {
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[parent] < a[child]) {
			HPDataType temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	// ����ռ�
	if (hp->_capacity == hp->_size) {
		int newCapacity = hp->_capacity == 0 ? 4 : 2 * hp->_capacity;
		HPDataType* Temp = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newCapacity);
		if (Temp == NULL) {
			perror("realloc fail:");
		}
		hp->_a = Temp;
		hp->_capacity = newCapacity;
	}
	hp->_a[hp->_size] = x;
	AdjustUp(hp->_a, hp->_size);
	hp->_size++;
}
//     0
//   1   2
//  3 4 5 6
// 7 
//�ѵ����µ���
void AdjustDown(HPDataType* a,int n , int parent) {
	assert(a);
	int child = (parent * 2) + 1;
	while (child < n) {
		if (child + 1 < n && a[child] < a[child + 1]) {
			child++;
		}
		if (a[parent] < a[child]) {
			HPDataType temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			parent = child;
			child = (parent * 2) + 1;
		}
		else {
			break;
		}
	}
}

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	assert(hp && hp->_size > 0);
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_a, hp->_size , 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
// 0Ϊ�ǿ�
// 1Ϊ��
int HeapEmpty(Heap* hp) {
	assert(hp);
	if (hp->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}

}

//������
void HeapSort(int* a, int n) {
	assert(a);
	// ���򣬽�С��
	// ���򣬽����
	// 
	// 
	// ���ϵ�������
	for (int i = 0; i < n; i++) {
		AdjustUp(a, i);
	}
	
	// ���µ�������
	for (int i = (n - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}

	for (int i = 0; i < n; i++) {
		HPDataType temp = a[n - 1 - i];
		a[n - 1 - i] = a[0];
		a[0] = temp;
		AdjustDown(a, n - i - 1, 0);
	}
	

}