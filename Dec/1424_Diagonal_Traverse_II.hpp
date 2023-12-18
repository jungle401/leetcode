class Solution {
public:
    struct Comp {
        bool operator()(const pair<int, int>& lhs, pair<int, int>& rhs) const {
            auto d1 = lhs.first + lhs.second;
            auto d2 = rhs.first + rhs.second;
            if (d1 < d2) {
                return false;
            } else if (d1 > d2) {
                return true;
            } else {
                return lhs.first < rhs.first;
            }
        }
    };
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // max diag
        auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, Comp>();
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                pq.push(make_pair(i, j));
            }
        }
        auto res = vector<int>();
        while (!pq.empty()) {
            res.push_back(nums[pq.top().first][pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
