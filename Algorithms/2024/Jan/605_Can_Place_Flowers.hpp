class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        auto prev1 = -2;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                auto cons0 = i - prev1 - 1;
                n -= (--cons0) / 2;
                prev1 = i;
            }
        }
        return n <= 0;
    }
};
