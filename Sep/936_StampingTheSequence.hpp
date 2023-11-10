class Solution {
public:
    bool same (string& stamp, string& target, int j) {     
        bool res = true;
        bool allMasked = true;
        for (int i = 0; i < stamp.size(); i++) {
            if (target[j + i] != '?') allMasked = false;
            if (target[j + i] != '?' && stamp[i] != target[j + i]) {
                res = false;
                break;
            }
        }
        if (allMasked == true) return false;
        return res;
    }
    vector<int> movesToStamp(string stamp, string target) { 
        bool find;
        vector<int> res;
        for (int i = 0; i < target.size(); i++) {  
            find = false;
            for (int j = 0; j < target.size() - stamp.size() + 1; j++) {
                find = same(stamp, target, j);
                if (find) {
                    // mask
                    for (int k = j; k < j + stamp.size(); k++) {
                        target[k] = '?';
                    }
                    res.push_back(j);
                    break;
                }
            }
            if (find == false) break;
        }
        for (int i = 0; i < target.size(); i++) {
            if (target[i] != '?') return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
