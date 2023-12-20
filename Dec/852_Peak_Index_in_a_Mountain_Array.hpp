class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        auto l = 0;
        auto r = arr.size() - 1;
        while (l < r) {
            auto m = (l + r) / 2;
            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
                return m;
            } else if (arr[m] > arr[m + 1]) {
                r = m;
            } else if (arr[m] < arr[m + 1]) {
                l = m;
            }
        }
        return 0;
    }
};
