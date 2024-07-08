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
    ListNode* deleteDuplicates(ListNode* head) {
      auto dummy_head = new ListNode();
      dummy_head->next = head;
      auto it = dummy_head;
      while (it->next && it->next->next) {
        auto it2 = it->next;
        if (it2->next && it2->val == it2->next->val) {
          do {
            it2 = it2->next;
          } while (it2->next && it2->val == it2->next->val);
          it2 = it2->next;
          it->next = it2;
        } else {
          it = it->next;
        }
      }
      return dummy_head->next;
    }
};
