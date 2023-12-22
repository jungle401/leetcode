class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int inc = 1;
        for (int i = 0; i < target.size(); i++) {
            if (target[i] == inc) {
                res.push_back("Push");
                inc++;
            } else {
                while (target[i] != inc) {
                    res.push_back("Push");
                    res.push_back("Pop");
                    inc++;
                }
                res.push_back("Push");
                inc++;
            }
        }
        return res;
    }
};
