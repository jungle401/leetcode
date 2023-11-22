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
    void show_list(ListNode* h) {
        while (h) {
            cout << h->val << ' ';
            h = h->next;
        }
        cout << endl;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        auto dh = new ListNode(0, head);
        ListNode* p1 = dh;
        for (int i = 1; i < left; i++) {
            p1 = p1->next;
        }
        ListNode* p2 = p1;
        for (int i = 0; i < right - left + 1; i++) {
            p2 = p2->next;
        }
        ListNode* p3 = p1->next;
        ListNode* p4 = p2->next;
        // cout << p1->val << ' ' << p2->val << endl;
        // cout << p3->val << ' ' << p3->val << endl;
        p2->next = nullptr;

        auto p = (ListNode*) nullptr;
        auto c = p3;
        auto hd = c;
        auto n = p3->next;
        while (c->next) {
            c->next = p;
            p = c;
            c = n;
            n = n->next;
        }
        c->next = p;
        auto tl = c;

        p1->next = tl;
        hd->next = p4;
        return dh->next;
    }
};
