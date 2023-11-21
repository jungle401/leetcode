class Solution {
public:
    bool canConstruct(string r, string m) {
        sort(r.begin(), r.end());
        sort(m.begin(), m.end());
        auto i = 0; 
        auto j = 0; 
        while (i < r.size() && j < m.size()) {
            if (r[i] == m[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == r.size();
    }
};
