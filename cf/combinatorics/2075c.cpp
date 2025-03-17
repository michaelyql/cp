#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	// cout<<"--"<<endl;
	int n, m;
	cin >> n >> m;
	vi a(m);
	rep(i, 0, m) cin >> a[i];
	sort(a.begin(), a.end());
	int i = 0, j = m - 1;
	ll ans = 0;
	vector<ll> shortage(m + 1, 0);
	for (int i = 1; i <= m; i++) {
		shortage[i] = shortage[i - 1];
		if (a[i - 1] == n) continue;
		shortage[i] += n - 1 - a[i - 1];
	}
	
	while (i < j) {
		int prev_j = j;
		while (i < j && a[i] + a[j] >= n) j--; 
		j++;
		// cout<<"a[i]="<<a[i]<<",a[j]="<<a[j]<<endl;
		// cout << "shortage="<<shortage[m]-shortage[j]<<endl;
		// cout <<"m-j="<<m-j<<endl;
		// cout <<"add1="<<  2 * (1ll * a[i] * (m - j) - (shortage[m] - shortage[j]))<<endl;
		
		j = min(prev_j, j);
		if (a[i] + a[j] >= n) {
			ans +=  2 * (1ll * min(a[i], n - 1) * (m - j) - (shortage[m] - shortage[j]));	
		}
		i++;
	}
	
	while (j < m) {
		// cout<<"a[j]="<<a[j]<<endl;
		// cout << "add2="<<( 2 * (1ll * min(a[j], n - 1) * (m-j-1) - shortage[m] + shortage[j + 1]))<<endl;
		ans += 2 * (1ll * min(a[j], n - 1) * (m-j-1) - shortage[m] + shortage[j + 1]);
		j++;
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
