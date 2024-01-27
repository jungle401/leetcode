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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        auto *o = head, *e = head->next;
        auto *oi = o, *ei = e;
        while (true) {
            if (!ei->next) {
                oi->next = e;
                break;
            } else {
                oi->next = ei->next;
                oi = oi->next;
            }
            if (!oi->next) {
                oi->next = e;
                ei->next = nullptr;
                break;
            } else {
                ei->next = oi->next;
                ei = ei->next;
            }
        }
        return o;
    }
};
