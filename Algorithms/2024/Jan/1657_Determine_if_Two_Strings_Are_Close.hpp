class Solution {
public:
    bool closeStrings(string word1, string word2) {
        auto m1 = map<char, int>();
        auto m2 = map<char, int>();
        for (auto& c : word1) { m1[c]++; }
        for (auto& c : word2) { m2[c]++; }
        auto v1 = vector<int>();
        auto v2 = vector<int>();
        for (auto& [a, b] : m1) { v1.push_back(b); b = 0;}
        for (auto& [a, b] : m2) { v2.push_back(b); b = 0;}
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2 && m1 == m2;
    }
};
