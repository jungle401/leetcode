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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      // cp: critical point
      int idx_first_cp = -1;
      int idx = 0;
      int min_dist = INT_MAX;
      int idx_last_cp = - 1;
      while (h´ead->next->next) {
        auto prev_val = head->val;
        auto cur_val = head->next->val;
        auto next_val = head->next->next->val;
        if (
          (prev_val < cur_val && cur_val > next_val) ||
          (prev_val > cur_val && cur_val < next_val)
        ) {
          if (idx_first_cp == -1) {
            idx_first_cp = idx;
          } else {
            min_dist = min(min_dist, idx - idx_last_cp);
          }
          idx_last_cp = idx;
        }
        idx++;
        head = head->next;
      }
      if (min_dist == INT_MAX) {
        return {-1, -1};
      } else {
        return {min_dist, idx_last_cp - idx_first_cp};
      }
    }
};
