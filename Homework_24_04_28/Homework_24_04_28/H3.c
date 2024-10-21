#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* hasCycle(struct ListNode* head) {
    struct ListNode* slow = head; //��ָ��
    struct ListNode* fast = head; //��ָ��
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next; //��ָ����һ��
        fast = fast->next->next; //��ָ��������
        if (slow == fast) //����ָ���������������
            return slow;
    }
    return NULL;
} //��������
struct ListNode* detectCycle(struct ListNode* head) {
    //�ҵ������Ľڵ�
    struct ListNode* meet = hasCycle(head);
    if (meet == NULL)
        return NULL;

    //��������B
    struct ListNode* headA = head;
    //��������B
    struct ListNode* headB = meet->next;

    //������Ͽ�
    meet->next = NULL;

    struct ListNode* pcurA = headA;
    struct ListNode* pcurB = headB;

    //��¼��������
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

    //������ͷ������
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

    //��ͬǰ����Ѱ����ͬ��һ����ͬ�ڵ㣬Ҳ�����뻷�׽ڵ�
    while (pcurA != pcurB)
    {
        pcurA = pcurA->next;
        pcurB = pcurB->next;
    }
    return pcurA;
}




//�ⷨ��

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