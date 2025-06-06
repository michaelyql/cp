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
    int n;
    cin >> n;
    int x = n * (n + 1) / 2;
    const int mod = 1e9 + 7;
    const int inv2 = 500000004;
    vi dp(x / 2 + 1, 0);
    dp[0] = 1;
    if (x % 2 == 0) {
        rep(i, 1, n + 1) {
            vi next(x / 2 + 1, 0);
            rep(j, 0, x / 2 + 1) {
                next[j] = dp[j];
                if (j - i >= 0 && dp[j - i]) next[j] = (next[j] + dp[j - i]) % mod;
            }
            dp = next;
        }
    }
    cout << (x > 1 ? (1ll * dp[x / 2] * inv2) % mod : 0) << endl;
}
