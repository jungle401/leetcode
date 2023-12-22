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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        auto dh = new ListNode();
        auto it = dh;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                it->next = l1;
                if (!l1->next) {
                    l1->next = l2;
                    break;
                }
                l1 = l1->next;
            } else {
                it->next = l2;
                if (!l2->next) {
                    l2->next = l1;
                    break;
                }
                l2 = l2->next;
            }
            it = it->next;
        }
        return dh->next;
    }
};
