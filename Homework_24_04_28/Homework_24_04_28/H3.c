#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* hasCycle(struct ListNode* head) {
    struct ListNode* slow = head; //慢指针
    struct ListNode* fast = head; //快指针
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next; //慢指针走一步
        fast = fast->next->next; //快指针走两步
        if (slow == fast) //快慢指针相遇，链表带环
            return slow;
    }
    return NULL;
} //链表不带环
struct ListNode* detectCycle(struct ListNode* head) {
    //找到相遇的节点
    struct ListNode* meet = hasCycle(head);
    if (meet == NULL)
        return NULL;

    //定义链表B
    struct ListNode* headA = head;
    //定义链表B
    struct ListNode* headB = meet->next;

    //将链表断开
    meet->next = NULL;

    struct ListNode* pcurA = headA;
    struct ListNode* pcurB = headB;

    //记录两链表长度
    int countA = 0;
    int countB = 0;
    while (pcurA)
    {
        countA++;
        pcurA = pcurA->next;
    }
    while (pcurB)
    {
        countB++;
        pcurB = pcurB->next;
    }

    //让两者头部对齐
    pcurA = headA;
    pcurB = headB;
    if (countA > countB)
    {
        for (int i = 0; i < countA - countB; i++)
        {
            pcurA = pcurA->next;
        }
    }
    else {
        for (int i = 0; i < countB - countA; i++)
        {
            pcurB = pcurB->next;
        }
    }

    //共同前进，寻找相同第一个相同节点，也就是入环首节点
    while (pcurA != pcurB)
    {
        pcurA = pcurA->next;
        pcurB = pcurB->next;
    }
    return pcurA;
}




//解法二

struct ListNode* hasCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* meet = hasCycle(head);
    struct ListNode* slow = head;
    if (meet == NULL)
        return NULL;
    else {
        while (slow != meet)
        {
            slow = slow->next;
            meet = meet->next;
        }
        return meet;
    }
}