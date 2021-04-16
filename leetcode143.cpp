/**
 *
 * File:    leetcode143.cpp
 *          重排链表
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/16
 *          
 **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        // 找到链表中点
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转后半段链表
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        slow->next = nullptr;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // 拼接两个链表
        ListNode *p = head, *q = prev;
        while (p && q) {
            ListNode *node1 = p->next;
            ListNode *node2 = q->next;
            p->next = q;
            q->next = node1;
            p = node1;
            q = node2;
        }
    }
};