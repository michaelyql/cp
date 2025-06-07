#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int mod = 1e9 + 7;

void generate_mask(int row, int cur_mask, int new_mask, vi& next_masks, int n) {
    if (row >= n) {
        if (row == n) next_masks.push_back(new_mask);
        return;
    }
    if (!(cur_mask & (1 << row)) && !(cur_mask & (1 << (row + 1)))) {
        generate_mask(row + 2, cur_mask, new_mask, next_masks, n);
    }
    if (!(cur_mask & (1 << row)) && !(new_mask & (1 << (row)))) {
        generate_mask(row + 1, cur_mask, new_mask + (1 << row), next_masks, n);
    }
    if (cur_mask & (1 << row)) {
        generate_mask(row + 1, cur_mask, new_mask, next_masks, n);
    }
}

int count(int col, int mask, vvi& dp, int m, int n) {   
    if (col == m) return dp[col][mask] = mask == 0;
    if (dp[col][mask] != -1) return dp[col][mask];
    vi next_masks;
    generate_mask(0, mask, 0, next_masks, n);
    int ans = 0;
    for (auto x : next_masks) {
        ans = (ans + count(col + 1, x, dp, m, n)) % mod;
    }
    return dp[col][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, m;
    cin >> n >> m;
    vvi dp(m + 1, vi(1 << n, -1)); 
    cout << count(0, 0, dp, m, n) << endl;
}
