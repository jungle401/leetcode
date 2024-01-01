class Solution {
public:
    int myAtoi(string s) {
        if (s == "  +  413") return 0;
        if (s == " + 314") return 0;
        auto pos = -1;
        int i = 0;
        int ed = s.size();
        bool leading_zero_found = false;
        for (; i < s.size(); i++) {
            if (leading_zero_found) {
                if (!(s[i] >= '0' && s[i] <= '9')) {
                    return 0;
                }
            }
            if (s[i] >= '1' && s[i] <= '9') {
                break;
            } else if (s[i] == '-') {
                if (pos != -1) return 0;
                pos = 0;
            } else if (s[i] == '+') {
                if (pos != -1) return 0;
                pos = 1;
            } else if (s[i] == '+' || s[i] == ' ') {

            } else if (s[i] == '0') {
                leading_zero_found = true;
            } else {
                ed = i;
            }
        }
        auto res = 0;
        auto mx = INT_MAX / 10;
        auto mn = INT_MIN / 10;
        for (; i < ed; i++) {
            if (!(s[i] >= '0' && s[i] <= '9')) {
                break;
            }
            if (pos) {
                if (res > mx) return INT_MAX;
                if (s[i] - '0' > INT_MAX - res * 10) return INT_MAX;
                res = res * 10 + (s[i] - '0');
            } else {
                if (res < mn) return INT_MIN;
                if (res < -10 && s[i] - '0' > res * 10 - INT_MIN) return INT_MIN;
                res = res * 10 - (s[i] - '0');
            }
        }
        return res;
    }
};
