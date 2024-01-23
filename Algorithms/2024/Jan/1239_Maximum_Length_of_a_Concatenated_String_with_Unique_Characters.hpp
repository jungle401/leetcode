class Solution {
public:
    vector<int> occ;
    int len;
    int res;
    vector<string> ar;
    void rec(int idx) {
        if (idx == -1) return;
        for (int i = idx - 1; i > -1; i--) {
            auto valid = true;
            for (int j = 0; j < ar[i].size(); j++) {
                if (occ[ar[i][j] - 'a'] == 1) {
                    valid = false;
                    for (int k = 0; k < j; k++) {
                        occ[ar[i][k] - 'a'] = 0;
                    }
                    break;
                } else {
                    occ[ar[i][j] - 'a'] = 1;
                }
            }
            if (valid) {
                for (int j = 0; j < ar[i].size(); j++) {
                    occ[ar[i][j] - 'a'] = 1;
                }
                len += ar[i].size();
                res = max(res, len);
                rec(i);
                for (int j = 0; j < ar[i].size(); j++) {
                    occ[ar[i][j] - 'a'] = 0;
                }
                len -= ar[i].size();
            }
        }
    }
    int maxLength(vector<string>& arr) {
        ar = move(arr);
        occ.resize(26);
        rec(ar.size());
        return res;
    }
};
