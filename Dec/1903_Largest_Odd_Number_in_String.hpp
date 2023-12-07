class Solution {
public:
    string largestOddNumber(string n) {
        auto end = n.size() - 1;
        for (int i = n.size() - 1; i >= 0; i--) {
            // if ((n[i] - '0') & 1) {
            // if (st.contains(n[i])) {
            if (
                n[i] == '1' ||
                n[i] == '3' ||
                n[i] == '5' ||
                n[i] == '7' ||
                n[i] == '9'
                ) {
                end = i;
                break;
            }
            if (i == 0) return "";
        }
        for (int i = 0; i <= end; i++) {
            if (n[i] != '0') return n.substr(i, end - i + 1);
        }
        return "";
    }
};
