class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i1 = 0, i2 = 0;
        auto res = string();
        while (i1 < word1.size() || i2 < word2.size()) {
            if (i1 < word1.size()) res.push_back(word1[i1++]);
            if (i2 < word2.size()) res.push_back(word2[i2++]);
        }
        return res;
    }
};
