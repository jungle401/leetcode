class Solution {
public:
    string addBinary(string a, string b) {
        int l = a.size() - 1;
        int r = b.size() - 1;
        int carry = 0;
        auto res = string();
        while (l >= 0 || r >= 0 || carry) {
            auto n1 = (l < 0) ? 0 : (a[l] == '1') ? 1 : 0;
            auto n2 = (r < 0) ? 0 : (b[r] == '1') ? 1 : 0;
            auto sum = n1 + n2 + carry;
            res.push_back(sum % 2 + '0');
            carry = sum / 2;
            l--; r--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
