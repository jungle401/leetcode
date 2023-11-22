class Solution {
public:
    bool checkRecord(string s) {
        auto conslate = 0;
        auto cnta = 0;
        for (auto& c : s) {
            if (c == 'A') {
                cnta++;
                if (cnta == 2) return false;
            } else if (c == 'L') {
                conslate++;
                if (conslate == 3) return false;
            }
            if (c != 'L') {
                conslate = 0;
            }
        }
        return true;
    }
};
