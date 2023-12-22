class Solution {
public:
    int n;
    int res;
    vector<int> vist;
    void rec(int index) {
        if (index == n) {
            res++;
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (vist[i]) {
                continue;
            }
            int id = index + 1;
            int num = i;
            if (num == id || (num > id && num % id == 0)
            || (num < id && id % num == 0)) {
                vist[i] = true;
                rec(index + 1);
                vist[i] = false;
            }
        }
    }
    int countArrangement(int n_) {
        n = n_;
        vist.resize(n + 1);
        res = 0;
        rec(0);
        return res;
    }
};
