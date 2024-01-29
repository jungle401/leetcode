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
    int res = INT_MIN;
    ListNode* left;
    int node_num = 0;
    void rec(ListNode* right) {
        if (right) {
            node_num += 1;
            rec(right->next);
            if (!node_num) return;
            node_num -= 2;
            res = max(res, left->val + right->val);
            left = left->next;
        }
    }
    int pairSum(ListNode* head) {
        left = head;
        rec(left);
        return res;
    }
};
