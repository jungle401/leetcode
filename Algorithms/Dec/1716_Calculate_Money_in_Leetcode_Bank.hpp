class Solution {
public:
    int totalMoney(int n) {
        auto l = n / 7;
        auto r = n - l * 7;
        auto res = 28 * l;
        res += 7 * ((l - 1) * l / 2);
        res += ((l + 1) + (l + r)) * r / 2;
        return res;
    }
};
