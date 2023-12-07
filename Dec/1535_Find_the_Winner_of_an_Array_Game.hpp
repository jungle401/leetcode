class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        auto q = queue<int>();
        auto winner = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            q.push(arr[i]);
        }
        auto win_times = 0;
        int n = arr.size();
        while (win_times < k && win_times < pow(n, 2)) {
            if (winner > q.front()) {
                win_times++;
                q.push(q.front());
                q.pop();
            } else {
                q.push(winner);
                winner = q.front();
                win_times = 1;
                q.pop();
            }
        }
        return winner;
    }
};
