#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include<stdio.h>
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���

  struct ListNode {
      int val;
      struct ListNode *next;
  };
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}