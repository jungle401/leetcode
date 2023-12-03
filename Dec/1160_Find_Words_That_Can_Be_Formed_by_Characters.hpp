class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        auto um = unordered_map<char, int>();
        for (auto& c : chars) {
            um[c]++;
        }
        auto res = 0;
        for (auto& w : words) {
            auto umw = unordered_map<char, int>();
            for (auto& c : w) {
                umw[c]++;
            }
            auto ok = true;
            for (auto& [c, t] : umw) {
                if (t > um[c]) {
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
