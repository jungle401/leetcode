class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto res = vector<vector<int>>();
        if (!intervals.size()) intervals.push_back(newInterval);
        intervals.push_back(intervals.back());
        auto inserted = false;
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
            else res.back()[1] = max(res.back()[1], intervals[i][1]);
            if (!inserted && intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i + 1][0]) {
                intervals[i] = newInterval;
                i--;
                inserted = true;
            }
        }
        return res;
    }
};
