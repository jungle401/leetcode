class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        auto poss = vector<int>();
        auto negs = vector<int>();
        for (auto& a : asteroids) {
            if (a > 0) {
                poss.push_back(a);
            } else {
                while (poss.size() && -a >= poss.back()) {
                    if (-a > poss.back()) {
                        poss.pop_back();
                    } else {
                        poss.pop_back();
                        break;
                    }
                }
            }
        }
        for (int i = asteroids.size() - 1; i >= 0; i--) {
            auto& a = asteroids[i];
            if (a < 0) {
                negs.push_back(a);
            } else {
                while (negs.size() && a >= -negs.back()) {
                    if (a > -negs.back()) {
                        negs.pop_back();
                    } else {
                        negs.pop_back();
                        break;
                    }
                }
            }
        }
        reverse(negs.begin(), negs.end());
        negs.insert(negs.end(), poss.begin(), poss.end());
        return negs;
    }
};
