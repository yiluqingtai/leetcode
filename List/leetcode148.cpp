/**
 *
 * File:    leetcode148.cpp
 *          排序链表
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *list1 = head, *list2 = slow->next;
        slow->next = nullptr;
        return merge(sortList(list1), sortList(list2));
    }

    ListNode* merge(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1) p->next = list1;
        if (list2) p->next = list2;
        return dummy->next;
    }
};