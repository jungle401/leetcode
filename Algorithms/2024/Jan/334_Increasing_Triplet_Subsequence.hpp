class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        auto st = set<int>();
        for (auto& n : nums) {
            auto lb = st.lower_bound(n);
            if (lb == st.end()) {
                st.insert(n);
                if (st.size() == 3) return true;
            } else const_cast<int&>(*lb) = n;
        }
        return false;
    }
};
