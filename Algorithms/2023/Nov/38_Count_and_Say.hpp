class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        auto prev = countAndSay(n - 1);
        // 333222211011
        // i. j
        //.   i.  j
        int s = prev.size();
        auto res = string();
        for (int i = 0; i < s; i++) {
            auto j = i + 1;
            while (j != s && prev[j] == prev[i]) {
                j++;
            }
            auto cnt = j - i;
            res += to_string(cnt) + prev[i];
            i = j - 1;
        }
        return res;
    }
};
