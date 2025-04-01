#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	ll hi = 0;
	rep(i, 0, n) {
		cin >> a[i];
		hi = max(hi, a[i]);
	}
	ll total = accumulate(a.begin(), a.end(), 0ll);
	ll low = total / n;
	if (total % n != 0) low++;
	ll amax = 0;
	while (low <= hi) {
		ll mid = low + (hi - low) / 2;
		ll excess = 0;
		rep(i, 0, n - 1) {
			if (a[i] > mid) excess += a[i] - mid;
			else if (a[i] < mid) excess = max(0ll, excess - mid + a[i]);
		}
		if (a[n - 1] + excess <= mid) {
			amax = mid;
			hi = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	low = *min_element(a.begin(), a.end());
	hi = amax;
	ll amin = amax;
	while (low <= hi) {
		ll mid = low + (hi - low) / 2;
		ll need = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] < mid) {
				need += mid - a[i];
			} else if (a[i] > mid) {
				need = max(0ll, need - a[i] + mid);
			}
		}
		if (a[0] - need >= mid) {
			amin = mid;
			low = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << amax - amin << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
