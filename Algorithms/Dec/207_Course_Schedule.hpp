class Solution {
public:
    vector<vector<int>> es;
    vector<int> preq_cnt;
    vector<int> released;
    void release(int i) {
        if (released[i]) return;
        if (preq_cnt[i] != 0) return;
        for (auto& w : es[i]) {
            preq_cnt[w]--;
            if (preq_cnt[w] == 0) {
                release(w);
            }
        }
        released[i] = true;
    }
    bool canFinish(int n, vector<vector<int>>& preq) {
        es.resize(n);
        preq_cnt.resize(n);
        released.resize(n);
        // auto es = vector<vector<int>>(n);
        // auto preq_cnt = vector<int>(n);
        for (auto& i : preq) {
            es[i[1]].push_back(i[0]);
            preq_cnt[i[0]]++;
        }
        for (int i = 0; i < n; i++) {
            release(i);
        }
        for (auto& i : preq_cnt) {
            if (i > 0) return false;
            else if (i < 0) cout << "WWRONG" << endl;
        }
        return true;
    }
};
