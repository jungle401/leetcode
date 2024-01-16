class RandomizedSet {
public:
    unordered_set<int> s;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        auto [it, bl] = s.insert(val);
        return bl;
    }
    
    bool remove(int val) {
        return s.erase(val);
    }
    
    int getRandom() {
        auto r = rand() % s.size();
        auto it = s.begin();
        for (int i = 0; i < r; i++) {
            it = next(it);
        }
        auto res = *it;
        // s.erase(it);
        return res;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
