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
    ListNode* partition(ListNode* head, int x) {
        auto dh = new ListNode(INT_MIN, head);
        ListNode* p1 = dh;
        ListNode* p2 = p1;
        while (p1) {
            if (p1->val >= x) {
                break;
            }
            p2 = p1;
            p1 = p1->next;
        }
        if (p1) cout << p1->val << endl;
        if (!p1) return dh->next;
        ListNode* p3 = p2;
        while (p1) {
            if (p1->val < x) {
                auto tmp = p1->next;
                p1->next = p2->next;
                p2->next = p1;
                p3->next = tmp;
                p1 = tmp;
                p2 = p2->next;
            } else {
                p3 = p1;
                p1 = p1->next;
            }
        }
        return dh->next;
    }
};
