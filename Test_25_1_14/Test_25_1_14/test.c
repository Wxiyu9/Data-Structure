#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>

typedef struct BTNode {
	int data;
	struct BTNode* left;
	struct BTNode* right;
}BTNode;
int TreeLeafSize(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return 1;
	}
	else {
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
	}
}

int TreeHigh(BTNode* root) {
	if (root == NULL) {
		return 0;
	}
	int LeftHigh = TreeHigh(root->left);
	int RightHigh = TreeHigh(root->right);
	return LeftHigh > RightHigh ? LeftHigh + 1 : RightHigh + 1;
}
#endif


#include <stdio.h>

int CharSum(char* str) {
	int i = 0;
	while (*str != '\0') {
		i++;
		str++;
	}
	return i;
}

int main() {
	char str[] = "123456";
	printf("%d", CharSum(str));
	return 0;
}
