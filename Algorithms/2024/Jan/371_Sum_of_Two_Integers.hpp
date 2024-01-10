class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int d = 1;
        int c = 0;
        for (int i = 0; i < 32; i++) {
            if (c) {
                if (d & a & b) {
                    // 3
                    res |= d;
                    c = 1;
                } else if (d & (a | b)) {
                    // 2
                    c = 1;
                } else {
                    // 1
                    res |= d;
                    c = 0;
                }
            } else {
                if (d & a & b) {
                    // 2
                    c = 1;
                } else if (d & (a | b)) {
                    // 1
                    res |= d;
                }
            }
            d <<= 1;
        }
        // if (res >= 0) {
        //     cout << "??" << endl;
        //     res |= d;
        // }
        return res;
    }
};
