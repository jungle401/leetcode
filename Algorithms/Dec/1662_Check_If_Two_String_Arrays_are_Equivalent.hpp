class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0;
        int j = 0;
        for (auto& w : word1) {
            for (auto& c : w) {
                if (j == word2[i].size()) {
                    i++;
                    j = 0;
                    if (i == word2.size()) return false;
                }
                if (c != word2[i][j]) {
                    return false;
                }
                j++;
            }
        }
        return i == word2.size() - 1 && j == word2.back().size();
    }
};
