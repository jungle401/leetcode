class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Simply a black magic
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        // A heap gives the desired worker, compared by the first and second value in order. (first by the cost and second by the index)
        auto pq = priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        >();

        // Two indices start from left and right
        int l = 0;
        int r = costs.size() - 1;

        // The heap should be initialized by putting 2 * candidates workers inside it. The iterating of the two indices is not neccessary to be synchronized, the implementation here is just for the simplicity for array bound controlling.
        candidates *= 2;
        for (auto flip = 1; l <= r && candidates--;) {
            if (flip) {
                pq.push({costs[l], l});
                l++;
            } else {
                pq.push({costs[r], r});
                r--;
            }
            flip = flip ^ 1;
        }

        // Pop the best and valid choice on iterations and record it to res. On each iteration, the only thing is to distinguish which elements, on the left the right one, being popped. If the left element is popped, then move the left pointer, and the same for the right one. Avoiding intersection of the two pointers is needed.
        long long res = 0;
        for (int i = 0; i < k; i++) {
            res += pq.top().first;
            if (l > r) {
                pq.pop(); 
            } else {
                if (pq.top().second < l) {
                    pq.pop();
                    pq.push({costs[l], l});
                    l++;
                } else if (pq.top().second > r) {
                    pq.pop();
                    pq.push({costs[r], r});
                    r--;
                }
            }
        }
        return res;
    }
};
