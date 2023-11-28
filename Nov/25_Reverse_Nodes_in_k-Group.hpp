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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cnt = 0;
        auto dummy_head = new ListNode();
        dummy_head->next = head;
        auto prev = dummy_head;
        for (auto t = head; t != nullptr; t = t->next) {
            cnt++;
            if (cnt == k) {
                cnt -= k;
                // reverse
                auto p = t->next;
                auto c = prev->next;
                auto next_prev = c;
                auto n = c->next;
                while (true) {
                    c->next = p;
                    if (c == t) {
                        prev->next = c;
                        prev = next_prev;
                        t = prev;
                        break;
                    }
                    p = c;
                    c = n;
                    n = n->next;
                }
            }
        }
        return dummy_head->next;
    }
};
