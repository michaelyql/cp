#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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
	int n, x;
	cin >> n >> x;
	vi ans(n);
	int i;
	for (i = 0; i < x; i++) ans[i] = i;
	i++;
	if (x < n) ans[n - 1] = x;
	else ans[n - 1] = n - 1;
	
	for (int j = n - 2; j >= x; j--) {
		ans[j] = i;
		i++;
	}
	rep(i, 0, n) cout << ans[i] << " ";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
