#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
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

void solve() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	const int INF = 1e9;
	vi d(n + 1, INF);
	d[0] = -INF;
	
	for (int i = 0; i < n; i++) {
		int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[l - 1] + 1 < a[i] && a[i] < d[l]) {
			d[l] = a[i];
		}
	}
	
	int ans = 0;
	
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    
    cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
