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
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	if (n == 2) {
		if ((a[0] + a[n - 1]) % 2 == 0) cout << 0 << endl; 
		else cout << 1 << endl;
		return;
	}
	sort(all(a));
	if ((a[0] + a[n - 1]) % 2 == 0) {
		cout << 0 << endl;
		return;
	}
	if (a[0] & 1) {
		int j = 0;
		while (a[n - 1 - j] % 2 == 0) j++;
		
		int k = 0;
		while (a[k] & 1) k++;
		
		cout << min(j, k) << endl;
	} else {
		int j = 0;
		while (a[n - 1 - j] & 1) j++;
		
		int k = 0;
		while (a[k] % 2 == 0) k++;
		
		cout << min(j, k) << endl;
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
