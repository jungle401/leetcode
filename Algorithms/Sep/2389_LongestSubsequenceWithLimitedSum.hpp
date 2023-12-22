#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        auto ps = nums;
        std::sort(ps.begin(), ps.end());
        for (int i = 1; i < ps.size(); i++) {
            ps[i] += ps[i - 1];
        }
        auto res = std::vector<int>();
        for (const auto& q : queries) { 
            auto r = std::upper_bound(ps.begin(), ps.end(), q);
            auto ri = std::distance(ps.begin(), r);
            std::cout << ri << '\t';
            res.push_back(ri);
        }
        std::cout << '\n';
        return res;
    }
};
