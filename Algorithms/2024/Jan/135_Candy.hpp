class Solution {
public:
    int n;
    vector<int> rs;
    vector<int> cs;
    int mn = INT_MAX;
    int getc(int i) {
        if (cs[i] != 0) return cs[i];
        if (rs[i] == mn) return 1;
        auto res = 1;
        if (i + 1 < n && rs[i] > rs[i + 1]) {
            res = getc(i + 1) + 1;
        }
        if (i > 0 && rs[i] > rs[i - 1]) {
            res = max(res, getc(i - 1) + 1);
        }
        cs[i] = res;
        return cs[i];
    }
    int candy(vector<int>& ratings) {
        rs = move(ratings);
        n = rs.size();
        for (int i = 0; i < n; i++) {
            if (mn > rs[i]) {
                mn = rs[i];
            }
        }
        cs.resize(n);
        auto res = 0;
        for (int i = 0; i < n; i++) {
            cs[i] = getc(i);
            res += cs[i];
        }
        return res;
    }
};
