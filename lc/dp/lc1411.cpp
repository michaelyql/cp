class Solution {
    static const int mod = 1e9 + 7;
    void gen_masks(int prev_mask, vector<int>& masks) {
        for (int i = 3; i >= 1; i--) {
            if ((prev_mask & 0b110000) == (i << 4)) continue;
            for (int j = 3; j >= 1; j--) {
                if ((prev_mask & 0b001100) == (j << 2)) continue;
                for (int k = 3; k >= 1; k--) {
                    if ((prev_mask & 0b000011) == k) continue;
                    if (i != j && j != k) {
                        masks.push_back((i << 4) + (j << 2) + k);
                    }
                }
            }
        }
    }
    int count(int row, int mask, vector<vector<int>>& dp, int n) {
        if (row == n) return 1;
        if (dp[row][mask] != -1) return dp[row][mask];
        vector<int> next_masks;
        gen_masks(mask, next_masks);
        int ans = 0;
        for (auto x : next_masks) {
            ans = (ans + count(row + 1, x, dp, n)) % mod;
        }
        return dp[row][mask] = ans;
    }
public:
    int numOfWays(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(64, -1));
        return count(0, 0, dp, n);
    }
};
