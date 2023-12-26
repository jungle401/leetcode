class Solution {
public:
    int minOperations(string s) {
        auto z1 = 0;
        auto o1 = 0;
        // z1: 010101...
        // o1: 10101....
        bool flip = 1;
        for (auto& c : s) {
            if (flip) {
                if (c == '0') {
                    z1++;
                } else {
                    o1++;
                }
            } else {
                if (c == '0') {
                    o1++;
                } else {
                    z1++;
                }
            }
            flip = !flip;
        }
        return min(z1, o1);
    }
};
