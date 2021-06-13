/**
 *
 * File:    leetcode142.cpp
 *          环形链表2
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode *node = head;
                while (slow != node) {
                    slow = slow->next;
                    node = node->next;
                }
                return slow;
            }
        } 
        return nullptr;
    }
};