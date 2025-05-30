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
    int n, x;
    cin >> n >> x;
    vi h(n), s(n);
    rep(i, 0, n) cin >> h[i];
    rep(i, 0, n) cin >> s[i];
    vvi dp(n+1, vi(x + 1));
    rep(i,1,n+1){
        rep(j,0,x+1){
            dp[i][j]=dp[i-1][j];
            if(j >= h[i-1]) dp[i][j]=max(dp[i][j], dp[i-1][j - h[i-1]] + s[i-1]);
        }
    }
    cout << dp[n][x] << endl;
}
