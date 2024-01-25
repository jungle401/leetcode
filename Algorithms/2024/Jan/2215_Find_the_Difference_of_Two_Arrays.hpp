class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(), n1.end());
        sort(n2.begin(), n2.end());
        int p = 0, q = 0;
        auto res = vector<vector<int>>(2);
        while (p < n1.size() || q < n2.size()) {
            if (p == n1.size()) {
                if (res[1].size() && res[1].back() == n2[q]) {
                    q++;
                    continue;
                }
                res[1].push_back(n2[q]);
                q++;
            } else if (q == n2.size()) {
                if (res[0].size() && res[0].back() == n1[p]) {
                    p++;
                    continue;
                }
                res[0].push_back(n1[p]);
                p++;
            } else if (n1[p] == n2[q]) {
                while (p + 1 < n1.size() && n1[p + 1] == n1[p]) p++;
                while (q + 1 < n2.size() && n2[q + 1] == n2[q]) q++;
                p++;
                q++;
            } else if (n1[p] < n2[q]) {
                if (res[0].size() && res[0].back() == n1[p]) {
                    p++;
                    continue;
                }
                res[0].push_back(n1[p]);
                p++;
            } else {
                if (res[1].size() && res[1].back() == n2[q]) {
                    q++;
                    continue;
                }
                res[1].push_back(n2[q]);
                q++;
            }
        }
        return res;
    }
};
