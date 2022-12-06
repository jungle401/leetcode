/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        auto h = head;
        auto h2 = head;
        while (h2 && h2->next) {
            h = h->next;
            h2 = h2->next->next;
        }
        return h;
    }
};
