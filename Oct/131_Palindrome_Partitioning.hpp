class Solution {
public:
    vector<vector<string>> res;
    string s;
    // palindrome table
    vector<vector<int>> pt;
    void set_pt() {
        int n = s.size();
        pt.resize(n);
        for (auto& i : pt) {
            i.resize(n);
        }
        for (int i = 0; i < n; i++) {
            pt[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                pt[i - 1][i] = 1;
            }
        }
        for (int i = 2; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                if (pt[j + 1][j + i - 1] && s[j] == s[j + i]) {
                    pt[j][j + i] = 1;
                }
            }
        }
    }
    vector<string> part;
    void rec(int l, int r) {
        if (pt[l][r]) {
            part.push_back(s.substr(l, r - l + 1));
            res.push_back(part);
            part.pop_back();
        }
        for (int i = l; i < r; i++) {
            if (!pt[l][i]) {
                continue;
            }
            part.push_back(s.substr(l, i - l + 1));
            rec(i + 1, r);
            part.pop_back();
        }
    }
    vector<vector<string>> partition(string ss) {
        s = ss;
        set_pt();
        for (auto& i : pt) {
            for (auto& j : i) {
                cout << j << ' ';
            }
            cout << endl;
        }
        rec(0, ss.size() - 1);
        return res;
    }
};
