#define _CRT_SECURE_NO_WARNINGS 1
#include <stdbool.h>
#include<stdio.h>
//给你一个链表的头节点 head ，判断链表中是否有环。

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