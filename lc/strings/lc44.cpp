class Solution {
  public:
      bool isMatch(string s, string p) {
          int n = max(s.size(), p.size());
          vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
          return _isMatch(s, p, 0, 0, dp);
      }
      int _isMatch(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
          if (dp[i][j] != -1) return dp[i][j];
          if (i == s.size()) { // reach end of s
              if (j < p.size()) {
                  if (p[j] == '*') return dp[i][j] = _isMatch(s, p, i, j + 1, dp);
                  else return dp[i][j] = 0;
              } 
              return dp[i][j] = 1;
          }
          if (j == p.size()) return dp[i][j] = 0; // not at the end of s, but reach end of p
          if (p[j] == '?') return dp[i][j] = _isMatch(s, p, i + 1, j + 1, dp);
          if (p[j] != '*') return dp[i][j] = (s[i] == p[j]) && _isMatch(s, p, i + 1, j + 1, dp); 
          return dp[i][j] = _isMatch(s, p, i, j + 1, dp) // empty sequence
              || _isMatch(s, p, i + 1, j + 1, dp) // match only current character
              || _isMatch(s, p, i + 1, j, dp); // match > 1 character
      }
  };
