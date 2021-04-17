/**
 *
 * File:    leetcode25.cpp
 *          K个一组翻转链表
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

    // 反转链表
    pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail) {
        ListNode *p = head;
        ListNode *prev = tail->next;
        while (prev != tail) {
            ListNode *curr = p->next;
            p->next = prev;
            prev = p;
            p = curr;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tail = dummy;

        while (head) {
            ListNode *prev = tail;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            ListNode *next = tail->next;
            auto reversed = reverse(head, tail);
            head = reversed.first;
            tail = reversed.second;
            prev->next = head;
            tail->next = next;
            head = next;
        }

        return dummy->next;
    }
};