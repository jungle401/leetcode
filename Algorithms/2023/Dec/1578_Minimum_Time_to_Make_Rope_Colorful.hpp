class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        auto res = 0;
        for (int i = 0; i < colors.size(); i++) {
            auto cons_sum = neededTime[i];
            auto max_val = neededTime[i];
            auto cons_num = 1;
            int j;
            for (j = i + 1;
                j < colors.size() && colors[j] == colors[i];
                j++) {
                    cons_num++;
                    max_val = max(max_val, neededTime[j]);
                    cons_sum += neededTime[j];
            }
            i = j - 1;
            res += cons_sum - max_val;
        }
        return res;
    }
};
