class Solution {
public:
    int hammingWeight(uint32_t n) {
        auto res = 0;
        while (n) {
            n = (n & (n - 1));
            res++;
        }
        return res;
    }
};
