class Solution {
public:
    int maxVowels(string s, int k) {
        auto l = 0;
        auto r = k - 1;
        auto max_num = 0; // ?
        auto v_num = 0;
        auto res = 0;
        auto v = unordered_set<char>({'a','e','i','o','u'});
        for (int i = 0; i <= r; i++) {
            if (v.contains(s[i])) v_num++;
        }
        max_num = v_num;
        if (max_num) res = 1;
        for (int i = r + 1; i < s.size(); i++) {
            if (v.contains(s[i])) {
                v_num++;
            }
            if (v.contains(s[l])) {
                v_num--;
            }
            if (v_num > max_num) {
                res = 1;
                max_num = v_num;
            } else if (v_num == max_num) {
                res++;
            }
            l++;
        }
        return max_num;
    }
};
