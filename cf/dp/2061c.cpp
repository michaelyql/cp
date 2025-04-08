#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int mod = 998244353;

void solve() {
	// cout<<"----\n";
	int n;
	cin >> n;
	vi a(n+1);
	rep(i,1,n+1) cin >> a[i];
	vvi dp(n+1, vi(2, 0)); 
	dp[0][0]=1;
	dp[1][1] = 1;
	if (a[1] == 0) dp[1][0] = 1;
	rep(i, 2, n+1) {
		// FT
	    if (a[i] == a[i-2] + 1) dp[i][0] = (dp[i][0] + dp[i-2][0]) % mod;
		
		// TT
		if (a[i] == a[i - 1]) {
			dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
		}
		
		// TF
		dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
	}

	cout << (dp[n][0] + dp[n][1]) % mod << endl;
	// rep(i,1,n+1){
	// 	rep(j,0,2){
	// 		printf("dp[%d][%d]=%d\n", i,j,dp[i][j]); fflush(stdout);
	// 	}
	// }
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
