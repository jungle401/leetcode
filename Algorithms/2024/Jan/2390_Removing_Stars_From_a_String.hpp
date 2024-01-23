class Solution {
public:
    string removeStars(string s) {
        auto res = string();
        for (auto& c : s) {
            if (c != '*') {
                res.push_back(c);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};
