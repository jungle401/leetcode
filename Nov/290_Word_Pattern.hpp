class Solution {
public:
    bool wordPattern(string pattern, string s) {
        auto um = unordered_map<char, string>();
        auto us = unordered_set<string>();
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') continue;
            auto j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            auto str = s.substr(i, j - i);
            // cout << str << endl;
            if (!um.contains(pattern[k])) {
                if (us.contains(str)) {
                    return false;
                }
                um[pattern[k]] = str;
                us.insert(str);
            } else {
                if (str != um[pattern[k]]) {
                    return false;
                }
            }
            k += 1;
            i = j;
        }
        // return k == 
        if (k != pattern.size()) {
            return false;
        }
        return true;
    }
};
