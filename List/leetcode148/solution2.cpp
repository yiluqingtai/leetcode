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

        ListNode *p = head, *q = slow->next;
        slow->next = nullptr;

        p = sortList(p);
        q = sortList(q);

        ListNode *dummy = new ListNode(0);
        ListNode *node = dummy;
        while (p && q) {
            if (p->val < q->val) {
                node->next = p;
                p = p->next;
            } else {
                node->next = q;
                q = q->next;
            }
            node = node->next;
        }
        if (q) {
            node->next = q;
        } else {
            node->next = p;
        }
        return dummy->next;
    }
};