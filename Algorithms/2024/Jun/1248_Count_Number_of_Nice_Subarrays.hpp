class Solution {
public:
	bool is_odd(int num) {
		return num & 1;
	}
	int numberOfSubarrays(vector<int>& nums, int k) {
		// index of odd nums. when it's size reaches k, sub ararys should be calculated.
		auto q = queue<int>();
		// 0 1 2 3 4 5 6 7 8 9
		// 2 2 2 1 2 2 1 2 2 2
		//       *     *
		auto left_boarder = -1;
		auto last_odd_index = -1;
		auto res = 0;
		nums.push_back(1);
		for (int i = 0; i < nums.size(); i++) {
			if (is_odd(nums[i])) {
				q.push(i);
				if (q.size() == k + 1) {
					res += (q.front() - left_boarder) * (i - last_odd_index);
					left_boarder = q.front();
					q.pop();
				}
				last_odd_index = i;
			}
		}
		return res;
	}
};
