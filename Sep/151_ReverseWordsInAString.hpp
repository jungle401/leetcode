class Solution {
public:
    string reverseWords(string s) {
        auto ss = stringstream(s);
        auto str = string();
        auto v = stack<string>();
        while (ss >> str) {  
            v.push(str);
        }
        auto res = string();
        while (!v.empty()) {
            res.insert(res.end(), v.top().begin(), v.top().end());
            res.push_back(' ');
            v.pop();
        }
        if (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }
};
