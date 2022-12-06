#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> gen(int n) { 
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> res = {""};
        // ( + g(n - 1) + )+ g(0) 
        // ( + g(n - 2) + )+ g(1) 
        // ( + g(n - 3) + )+ g(2) 
        // ...
        // ( + g(0) + g(n - 1) )
        for (int i = 0; i < n; i++) {
            // res.push_back("(" + g(n - i) + ")" + g(i));
            auto gl = gen(n - i - 1);
            auto gr = gen(i);
            for (const auto& l : gl) {
                for (const auto& r : gr) {
                    auto comb = string("(" + l + ")" + r);
                    if (comb.size() == 2*n) {
                    res.push_back(comb);

                    }
                }
            }
        }

        return res;
    }
    vector<string> generateParenthesis(int n) { 
        if (n == 1) {
            return vector<string>{"()"};
        }
        auto v = gen(n);
        return vector<string>(v.begin() + 1, v.end());
    }
};
