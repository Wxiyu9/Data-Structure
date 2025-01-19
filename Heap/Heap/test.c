#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

int main() {
	int a[] = { 3,5,7,4,25,3,26,65,245,754,243,7,3567134,8,468,647,786,04356,54,37,05};
	int size = sizeof(a) / sizeof(int);
	HeapSort(a, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}