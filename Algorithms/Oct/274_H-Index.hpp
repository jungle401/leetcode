class Solution {
public:
    int hIndex(vector<int>& cs) {
        sort(cs.begin(), cs.end());
        reverse(cs.begin(), cs.end());
        int n = cs.size();
        int i = 0;
        for (; i < n; i++) {
            if (cs[i] < i + 1) {
                break;
            }
        }
        return i;
    }
};
