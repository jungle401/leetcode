class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (!s.size() || !g.size()) return 0;
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int j = 0;
        int i = 0;
        while (j < s.size() && i < g.size()) {
            if (s[j] >= g[i]) {
                j++;
                i++;
            } else if (s[j] < g[i]) {
                j++;
            }
        }
        return i;
    }
};
