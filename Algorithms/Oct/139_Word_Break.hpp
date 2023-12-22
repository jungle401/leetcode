class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1);
        unordered_set<string> words;
        for (auto& i : wordDict) {
            words.insert(i);
        }
        for (int i = 1; i <= n; i++) {
            auto si = s.substr(0, i);
            if (words.contains(si)) {
                dp[i] = 1;
            } else {
                for (int j = i - 1; j > 0; j--) {
                    if (dp[j] && words.contains(s.substr(j, i - j))) {
                        dp[i] = 1;
                    }
                }
            }
        }
        return dp[n];
    }
};

