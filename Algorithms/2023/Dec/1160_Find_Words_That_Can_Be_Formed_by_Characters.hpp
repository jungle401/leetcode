class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {0};
        for (auto& c : chars) {
            cnt[c - 'a']++;
        }
        auto res = 0;
        for (auto& w : words) {
            int wcnt[26] = {0};
            auto ok = true;
            for (auto& c : w) {
                wcnt[c - 'a']++;
                if (wcnt[c - 'a'] > cnt[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res += w.size();
            }
        }
        return res;
    }
};
