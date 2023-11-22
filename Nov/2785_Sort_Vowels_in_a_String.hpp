class Solution {
public:
    bool is_vowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
        ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    string sortVowels(string s) {
        auto vowels = vector<char>();
        for (auto& c : s) {
            if (is_vowel(c)) {
                vowels.push_back(c);
            }
        }
        int j = 0;
        sort(vowels.begin(), vowels.end());
        for (auto& c : s) {
            if (is_vowel(c)) {
                c = vowels[j++];
            }
        }
        return s;
    }
};
