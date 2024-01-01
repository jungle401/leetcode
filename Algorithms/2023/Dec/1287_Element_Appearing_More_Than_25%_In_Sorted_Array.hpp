class Solution {
public:
    vector<int> arr;
    int find_max_index(int l, int r) {
        auto x = arr[l];
        while (l + 1 < r) {
            auto m = (l + r) / 2;
            if (arr[m] <= x) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
    int findSpecialInteger(vector<int>& arr_) {
        arr = move(arr_);
        int n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            // for this element, find the largest index with the identical value.
            auto right_most = find_max_index(i, n);
            auto num = right_most - i + 1;
            if (num > arr.size() / 4) return arr[i];
            i = right_most;
        }
        return 0;
    }
};
