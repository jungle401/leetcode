class Solution {
public:
    int garbageCollection(vector<string>& gar, vector<int>& t) {
        auto res = 0;
        t.insert(t.begin(), 0);
        for (int i = 1; i < t.size(); i++) {
            t[i] += t[i - 1];
        }
        int last_m, last_p, last_g;
        last_m = last_p = last_g = 0;
        int cm, cp, cg;
        cm = cp = cg = 0;
        for (int i = 0; i < gar.size(); i++) {
            for (auto& c : gar[i]) {
                if (c == 'M') {
                    cm++;
                    last_m = i;
                } else if (c == 'P') {
                    cp++;
                    last_p = i;
                } else { // c == 'G'
                    cg++;
                    last_g = i;
                }
            }
        }
        res = cm + cp + cg;
        if (last_m != -1) {

        }
        res += t[last_m];
        res += t[last_p];
        res += t[last_g];
        return res;
    }
};
