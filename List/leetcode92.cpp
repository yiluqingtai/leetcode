/**
 *
 * File:    leetcode92.cpp
 *          反转链表 2
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/21
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*获取四个定位节点*/
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = head, *q = head;
        ListNode *prev = dummy, *tail = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        } 
        p = prev->next;
        for (int j = 0; j < right - 1; j++) {
            q = q->next;
        }
        tail = q->next;

        /*迭代方式内部反转链表*/
        ListNode *pre = tail, *cur = p;
        while (cur != tail) {
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
        prev->next = q;

        return dummy->next;
    }
};