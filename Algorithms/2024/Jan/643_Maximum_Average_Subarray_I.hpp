class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int s = 0;
        int i = 0;
        while (i < k) {
            s += nums[i];
            i++;
        }
        int mx = s;
        int j = 0;
        while (i < nums.size()) {
            s += nums[i], s -= nums[j];
            mx = max(mx, s);
            i++, j++;
        }
        return double(mx) / k;
    }
};
