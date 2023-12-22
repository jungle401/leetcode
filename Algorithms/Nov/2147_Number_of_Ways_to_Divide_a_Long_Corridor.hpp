class Solution {
public:
    int numberOfWays(string cor) {
        int n = cor.size();
        auto scnt = 0;
        for (auto& c : cor) {
            if (c == 'S') {
                scnt++;
            }
        }
        if (scnt == 0 || scnt % 2 == 1) return 0;
        scnt = 0;
        auto prev_sofa_end = 0;
        for (int i = 0; i < n; i++) {
            if (cor[i] == 'S') {
                scnt++;
                if (scnt == 2) {
                    prev_sofa_end = i;
                    break;
                }
            }
        }
        // cout << prev_sofa_end << endl;
        scnt = 0;
        auto sigma = vector<int>();
        for (int i = prev_sofa_end + 1; i < n; i++) {
            if (cor[i] == 'S') {
                if (scnt == 0) {
                    sigma.push_back(i - prev_sofa_end);
                }
                scnt++;
                if (scnt == 2) {
                    prev_sofa_end = i;
                    scnt = 0;
                }
            }
        }
        using ll = long long;
        ll res = 1;
        for (int i = 0; i < sigma.size(); i++) {
            // cout << sigma[i] << endl;
            res *= sigma[i];
            res = res % int(1e9 + 7);
        }
        return res;
    }
};
