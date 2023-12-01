class Solution {
public:
    vector<vector<int>> g;
    enum class STATE {
        UNVISITED, SAFE, UNSAFE, TRAVERSING,
    };
    vector<STATE> st;
    vector<int> res;
    bool cycle;
    void dfs(int v) {
        // This v should be ensured as non-visited
        st[v] = STATE::TRAVERSING;
        for (auto& w : g[v]) {
            if (st[w] == STATE::UNVISITED) {
                dfs(w);
            } else if (st[w] == STATE::UNSAFE || st[w] == STATE::TRAVERSING) {
                cycle = true;
            }
            if (cycle) break;
        }
        // If cycle is true, the currently traversed nodes are ensured
        // to be unsafe, and yet to be returned.
        if (cycle) {
            st[v] = STATE::UNSAFE;
        } else {
            st[v] = STATE::SAFE;
            res.push_back(v);
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        g = move(graph);
        st.resize(g.size());
        for (int i = 0; i < g.size(); i++) {
            if (st[i] == STATE::UNVISITED) {
                cycle = false;
                dfs(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
