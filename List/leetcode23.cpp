/**
 *
 * File:    leetcode23.cpp
 *          合并K个升序链表
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/5/30
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeLists(vector<ListNode*> lists, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            auto left_list = mergeLists(lists, l, m);
            auto right_list = mergeLists(lists, m + 1, r);
            return mergetTwoLists(left_list, right_list);
        } else if (l == r) {
            return lists[l];
        }
        return nullptr;
    } 

    ListNode* mergetTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (l1 && l2) {
            if (l1 ->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return dummy->next;
    }
};