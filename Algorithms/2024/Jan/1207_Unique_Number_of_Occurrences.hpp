class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        auto num2occ = unordered_map<int, int>();
        for (auto& num : arr) { num2occ[num]++; }
        auto occ2num = unordered_map<int, int>();
        for (auto& [num, occ] : num2occ) {
            if (occ2num.contains(occ)) return false;
            occ2num[occ] = num;
        }
        return true;
    }
};
