class Solution {
public:
    int compress(vector<char>& chars) {
        char c;
        int t;
        int m = 0;
        for (int i = 0; i < chars.size(); i++) {
            c = chars[i];
            t = 1;
            while (i + 1 < chars.size() && chars[i + 1] == c) {
                i++;
                t++;
            }
            if (t == 1) {
                chars[m] = c;
                m++;
            } else {
                chars[m++] = c;
                auto tmp = to_string(t);
                for (int j = 0; j < tmp.size(); j++) {
                    chars[m++] = tmp[j];
                }
                // s = s + c + to_string(t);
            }
        }
        return m;
    }
};
