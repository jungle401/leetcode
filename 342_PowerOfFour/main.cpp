class Solution {
public:
    bool isPowerOfFour(int n) { 
        if (n == 1) return true;
        if (n == 0) return false;
        do {
            int r = n % 4;
            if (r != 0) {
                return false;
            }
            n /= 4;
        } while (n != 1);
        return true;
    }
};
