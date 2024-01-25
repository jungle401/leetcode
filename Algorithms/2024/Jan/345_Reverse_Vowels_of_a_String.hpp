class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        auto vowels = unordered_set<char>(
            {'a','e','i','o','u','A','E','I','O','U'}
        );
        while (true) {
            while (l < s.size() && !vowels.contains(s[l])) l++;
            while (r >= 0 && !vowels.contains(s[r])) r--;
            if (l >= r) break;
            swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};
