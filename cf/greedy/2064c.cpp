#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 5;
int A[N];
int n;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	
	vector<ll> pfx(n);
	if (A[0] > 0) pfx[0] = A[0];
	for (int i = 1; i < n; i++) {
		pfx[i] = pfx[i - 1];
		if (A[i] > 0) pfx[i] += A[i];
	}
	
	vector<ll> sfx(n);
	if (A[n - 1] < 0) sfx[n - 1] = -A[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sfx[i] = sfx[i + 1];
		if (A[i] < 0) sfx[i] -= A[i];
	}
	
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, pfx[i] + sfx[i]);
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
