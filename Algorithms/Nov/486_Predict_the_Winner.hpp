class Solution {
public:
    vector<int> ns;
    vector<vector<vector<int>>> dp;
    int rec(bool a_turn, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (dp[l][r][a_turn] != -1) return dp[l][r][a_turn];
        if (a_turn) {
            auto take_l = rec(!a_turn, l + 1, r) + ns[l];
            auto take_r = rec(!a_turn, l, r - 1) + ns[r];
            return dp[l][r][a_turn] = max(take_l, take_r);
        } else {
            auto take_l = rec(!a_turn, l + 1, r);
            auto take_r = rec(!a_turn, l, r - 1);
            return dp[l][r][a_turn] = min(take_l, take_r);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() <= 2) return true;
        auto tt = accumulate(nums.begin(), nums.end(), 0);
        ns = move(nums);
        dp = vector<vector<vector<int>>>(ns.size(),
            vector<vector<int>>(ns.size(),
            vector<int>(2, -1)));
        auto a_max = rec(1, 0, ns.size() - 1);
        auto b_score = tt - a_max;

        return a_max >= b_score;
    }
};
