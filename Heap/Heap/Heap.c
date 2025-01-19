#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

// 堆的初始化
void HeapInit(Heap* php) {
	assert(php);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// 堆的向上调整
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

// 堆的插入
void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);
	// 申请空间
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
//堆的向下调整
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

// 堆的删除
void HeapPop(Heap* hp)
{
	assert(hp && hp->_size > 0);
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_a, hp->_size , 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(hp->_size > 0);
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
// 0为非空
// 1为空
int HeapEmpty(Heap* hp) {
	assert(hp);
	if (hp->_size == 0) {
		return 1;
	}
	else {
		return 0;
	}

}

//堆排序
void HeapSort(int* a, int n) {
	assert(a);
	// 降序，建小堆
	// 升序，建大堆
	// 
	// 
	// 向上调整建堆
	for (int i = 0; i < n; i++) {
		AdjustUp(a, i);
	}
	
	// 向下调整建堆
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