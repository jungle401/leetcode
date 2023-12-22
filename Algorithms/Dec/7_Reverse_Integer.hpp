class Solution {
public:
    int reverse(int x) {
        auto res = 0;
        auto mx = INT_MAX / 10;
        auto mn = INT_MIN / 10;
        while (x) {
            if (res > mx || res < mn) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
