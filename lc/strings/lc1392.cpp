const int m = 1e9 + 7;
const int p = 26; 

class Solution {
public:
    string longestPrefix(string s) {
        long long h1 = 0, h2 = 0;
        int n = s.size();

        long long pw = 1;
        int res = 0;

        for (int i = 0, j = n - 1; i < n - 1; i++, j--) {
            h1 = (h1 + (s[i] - 'a') * pw) % m;
            pw = pw * 26 % m;

            h2 = h2 * 26 % m;
            h2 = h2 + s[j] - 'a';
            if (h1 == h2) {
                res = i + 1;
            }
        }
        return s.substr(0, res);
    }
};
