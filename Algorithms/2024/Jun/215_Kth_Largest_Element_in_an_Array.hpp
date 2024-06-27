class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      auto pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), nums.begin() + k);
      for (int i = k; i < nums.size(); i++) {
        if (pq.top() < nums[i]) {
          pq.pop();
          pq.push(nums[i]);
        }
      }
      return pq.top();
    }
};
