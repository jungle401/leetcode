class Solution {
public:
    bool isPowerOfTwo(long n) {
        if (!n) return false;
        return !(n&(n - 1));
    }
};
