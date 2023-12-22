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
    int count(ListNode* it) {
        int res = 0;
        while (it) {
            it = it->next;
            res++;
        }
        return res;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        if (!head->next) return nullptr;
        int c = count(head);
        // 0-based index
        int index = c - n;
        if (index == 0) {
            return head->next;
        }
        auto it = head;
        for (int i = 0; i < index - 1; i++) {
            it = it->next;
        }
        auto tmp = it->next;
        it->next = tmp->next;
        delete tmp;
        return head;
    }
};
