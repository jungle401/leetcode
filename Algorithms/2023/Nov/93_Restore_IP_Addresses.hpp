class Solution {
public:
    vector<string> comb;
    vector<string> res;
    string s;
    bool vs(const string_view& w) {
        // digits exceeding
        if (w.size() > 3 || w.size() < 1) { return false; }
        // leading zero
        if (w.size() > 1 && w[0] == '0') { return false; }
        // if exceed 255
        const static string lim = "255";
        if (w.size() == 3) {
            for (int i = 0; i < 3; i++) {
                if (w[i] < lim[i]) {
                    return true;
                } else if (w[i] > lim[i]) {
                    return false;
                }
            }
        }
        // with leading zero cases being eliminated, w with w.size() < 3 is always valid
        return true;
    }
    void rec(int index, int pt) {
        // start from index, should insert pt points
        if (pt == 0) {
            if (vs(string_view(s.data() + index))) {
                auto tmp = comb[0]+'.'+comb[1]+'.'+comb[2]+'.'+s.substr(index);
                res.push_back(tmp);
            }
            return;
        }
        // 2.5525511135
        // 25.525511135
        // 255.25511135
        for (int i = 1; i <= 3; i++) {
            if (index + i > s.size()) continue;
            auto subs = string_view(s.data() + index, i);
            if (!vs(subs)) continue;
            comb.push_back(s.substr(index, i));
            rec(index + i, pt - 1);
            comb.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s_) {
        s = move(s_);
        rec(0, 3);
        return res;
    }
};
