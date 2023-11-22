class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto carry = 0;
        digits.back()++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            auto sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
