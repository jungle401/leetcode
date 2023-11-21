class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res{pref.front()};
        int prod = pref.front();
        for (int i = 1; i < pref.size(); i++) {
            res.push_back(pref[i] ^ prod);
            prod ^= res.back();
        }
        return res;
    }
};
