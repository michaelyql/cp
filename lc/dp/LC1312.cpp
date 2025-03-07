class Solution {
  int dp[501][501];
  int lps(string& s, int l, int r) {
      if (l > r) return 0;
      if (l == r) return dp[l][r] = 1;
      if (dp[l][r] != -1) return dp[l][r];
      if (s[l] == s[r]) return dp[l][r] = 2 + lps(s, l + 1, r - 1);
      else return dp[l][r] = max(lps(s, l + 1, r), lps(s, l, r - 1));
  }
public:
  int minInsertions(string s) {
      memset(dp, -1, sizeof(dp));
      return s.length() - lps(s, 0, s.length() - 1);
  }
};

