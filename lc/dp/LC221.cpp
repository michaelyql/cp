class Solution {
  public:
      int maximalSquare(vector<vector<char>>& matrix) {
          int m = matrix.size();
          int n = matrix[0].size();
          vector<vector<int>> dp(m, vector<int>(n, 0));
          int max_w = 0;
          for (int i = 0; i < m; i++) {
              for (int j = 0; j < n; j++) {
                  if (matrix[i][j] == '0') continue;
                  int left = 0, top = 0, diag = 0;
                  if (i > 0) left = dp[i - 1][j];
                  if (j > 0) top = dp[i][j - 1];
                  if (i > 0 && j > 0) diag = dp[i - 1][j - 1];
                  dp[i][j] = min(min(left, top), diag) + 1;
                  max_w = max(max_w, dp[i][j]);
              }
          }
          return max_w * max_w;
      }
  };
