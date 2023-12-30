class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int chars[26] = {0};
        for (auto& w : words) {
            for (auto& c : w) {
                chars[c - 'a']++;
            }
        }
        for (auto& num : chars) {
            if (num % words.size()) return false;
        }
        return true;
    }
};
