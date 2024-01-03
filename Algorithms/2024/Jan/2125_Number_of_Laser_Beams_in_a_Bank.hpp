class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        auto res = 0;
        auto prev_devices = 0;
        for (int i = 0; i < bank.size(); i++) {
            auto cur_devices = 0;
            for (int j = 0; j < bank[i].size(); j++) {
                cur_devices += (bank[i][j] == '1');
            }
            res += cur_devices * prev_devices;
            if (cur_devices != 0) prev_devices = cur_devices;
        }
        return res;
    }
};
