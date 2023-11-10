class Solution {
public:
    vector<int>* c;
    vector<vector<int>> res;
    int t;
    void rec(vector<int>& comb, int sum, int index) {
        if (sum == t) {
            res.push_back(comb);
            return;
        } else if (sum > t) {
            return;
        }
        for (int i = index; i < c->size(); i++) {
            if (sum + (*c)[i] > t) {
                continue;
            }
            comb.push_back((*c)[i]);
            sum += (*c)[i];
            rec(comb, sum, i + 1);
            comb.pop_back();
            sum -= (*c)[i];
            while (i + 1 < c->size() && (*c)[i] == (*c)[i + 1]) {
                i++;
            }
        };
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        c = &candidates;
        t = target;
        vector<int> comb;
        int sum = 0;
        int index = 0;
        rec(comb, sum, index);
        return res;
    }
};
