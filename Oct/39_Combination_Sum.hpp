class Solution {
public:
    vector<vector<int>> res;
    int t;
    void rec(vector<int>& candidates, vector<int>& comb, int sum) {
        if (sum == t) {
            res.push_back(comb);
        } else if (sum > t) {
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (comb.size() > 0 && candidates[i] < comb.back()) {
                continue;
            }
            sum += candidates[i];
            comb.push_back(candidates[i]);
            rec(candidates, comb, sum);
            sum -= candidates[i];
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        t = target;
        vector<int> comb;
        int sum = 0;
        rec(candidates, comb, sum);
        return res;
    }
};
