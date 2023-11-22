class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        auto res = vector<int>();
        auto lim = unordered_map<char, int>();
        for (auto& c : p) {
            lim[c]++;
        }
        auto state = unordered_map<char, int>();
        auto count = 0;
        for (int i = 0; i < s.size(); i++) {
            // check if the next char violate the limit
            if (!lim.contains(s[i])) {
                state.clear();
                count = 0;
                continue;
            }
            if (state[s[i]] == lim[s[i]]) {
                auto j = i - count;
                do {
                    state[s[j]]--;
                    count--;
                } while (s[j++] != s[i]);
            }
            // add this char
            state[s[i]]++;
            count++;
            // examine and record
            if (count == p.size()) {
                res.push_back(i - count + 1);
            }
        }
        return res;
    }
};
