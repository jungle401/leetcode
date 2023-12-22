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
    ListNode* rev(ListNode* cur) {
        ListNode *n, *p = nullptr;
        while(cur) {
            n = cur->next;
            cur->next = p;
            p = cur;
            cur = n;
        }
        return p;
    }
    void show(ListNode* h) {
        while (h) {
            cout << h->val << ' ';
            h = h->next;
        }
        cout << endl;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto res = new ListNode();
        auto it = res;
        auto car = 0;
        l1 = rev(l1);
        l2 = rev(l2);
        while (l1 || l2) {
            auto sum = 0;
            if (l1 && l2) {
                sum = l1->val + l2->val + car;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                sum = l1->val + car;
                l1 = l1->next;
            } else if (l2) {
                sum = l2->val + car;
                l2 = l2->next;
            }
            it->next = new ListNode(sum % 10);
            it = it->next;
            car = sum / 10;
        }
        if (car == 1) {
            it->next = new ListNode(1);
        }
        auto r = res->next;
        r = rev(r);
        return r;
    }
};
