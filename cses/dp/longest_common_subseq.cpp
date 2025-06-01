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

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    rep(i, 0, n) cin >> a[i];
    rep(j, 0, m) cin >> b[j];
    vvi dp(n + 1, vi(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
            } else {
                dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
    }
    cout << dp[0][0] << endl;
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            ans.push_back(a[i]);
            i++, j++; 
        } else {
            if (dp[i + 1][j] > dp[i][j + 1]) i++;
            else j++;
        }
    }
    for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
}
