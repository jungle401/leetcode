class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int j = i;
      int repeat = 0;
      while (j + 1 < nums.size() && nums[j] + 1 >= nums[j + 1]) {
        if (nums[j + 1] == nums[j]) {
          repeat++;
        }
        j++;
      }
      res = max(res, j - i + 1 - repeat);
      i = j;
    }
    return res;
  }
};
