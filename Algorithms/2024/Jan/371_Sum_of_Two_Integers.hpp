class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);

        // 0111
        // 0101

        // 1010 (carry part)
        // 0010 (sum part)

        // add this two parts as initially again,
        // until there're no carry part

        if (!b) return a;
        auto carry_part = (a & b) << 1;
        auto sum_part = a ^ b;
        return getSum(sum_part, carry_part);
    }
};
