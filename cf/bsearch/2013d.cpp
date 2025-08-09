#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	/*
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

	*/

	int n;
	cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // prefix sums p[k] = sum of a[0..k-1], p[0] = 0
    vector<ll> p(n+1, 0);
    for (int i = 0; i < n; ++i) p[i+1] = p[i] + a[i];
    ll S = p[n];

    // compute m* = min_{1<=k<=n} floor(p_k / k)
    ll mstar = LLONG_MAX;
    for (int k = 1; k <= n; ++k) {
        ll val = p[k] / k;            // floor division for nonnegative values
        mstar = min(mstar, val);
    }

    // compute M* = max_{1<=t<=n} ceil(s_t / t)
    // where s_t = sum of last t elements = S - p[n-t]
    ll Mstar = LLONG_MIN;
    for (int t = 1; t <= n; ++t) {
        ll st = S - p[n - t];
        // ceil division for positive integers: (st + t - 1) / t
        ll val = (st + t - 1) / t;
        Mstar = max(Mstar, val);
    }

    // result is M* - m*
    cout << (Mstar - mstar) << '\n';
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
