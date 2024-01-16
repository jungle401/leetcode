class Solution {
public:
    vector<int> countBits(int n) {
        auto res = vector<int>(n + 1);
        auto base = 0;
        for (int i = 1; i <= n; i++) {
            if (i == pow(2, base + 1)) base++;
            res[i] = res[int(i - pow(2, base))] + 1;
        }
        return res;
        // 0       0
        // 1       1   1
        // 10      1   2
        // 11      2   2
        // 100     1   4
        // 101     2   4
        // 110     2   4
        // 111     3   4
        // 1000    1   8
        // 1001    2
        // 1010    2
        // 1011    3
        // 1100    2
        // 1101    3
        // 1110    3
        // 1111    4
    }
};
