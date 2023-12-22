#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int curPos = startFuel;
        int ans = 0;
        priority_queue<int> pq;
        int it_stat = 0;
        while (true) {
            // enlist all available fuel, of whose corresponding stations being prior (or equal) to the current position
            while (it_stat < stations.size() && stations[it_stat][0] <= curPos) {
                pq.push(stations[it_stat][1]);
                it_stat++;
            }
            // move one maximum fuel in list forward
            if (!pq.empty() && curPos < target) {
                curPos += pq.top();
                pq.pop();
                ans++;
            } else if (curPos >= target) {
                return ans;
            } else if (pq.empty()) {
                if (curPos < target) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
