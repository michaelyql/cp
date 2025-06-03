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

const int mod = 998244353;

ll binpow(ll a, ll b) {
	if (b == 0) return 1;
	ll ret = 1;
	while (b > 0) {
		if (b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int add(int x, int y) {
	return (x % mod + y % mod) % mod;
}

int calc(int x, int y) {
	return add(binpow(2, x), binpow(2, y));
}

void solve() {
	int n;
	cin >> n;
	vi p(n), q(n);
	rep(i, 0, n) cin >> p[i];
	rep(i, 0, n) cin >> q[i];
	map<int, vector<pii>> mp;
	vi r(n);
	for (int i = 0; i < n; i++) {
		mp[p[i]].push_back({i, 0}); // 0 from p
		mp[q[i]].push_back({i, 1}); // 1 from q
		auto indices = (*mp.rbegin()).second;
		if (indices.size() == 1) {
			int j = indices[0].first;
			int which = indices[0].second; 
			if (which == 0) {
				r[i] = calc(p[j], q[i - j]);
			} else {
				r[i] = calc(q[j], p[i - j]);
			}
		} else {
			int which = indices[0].second;
			int j = indices[0].first;
			int k = indices[1].first;
			
			if (which == 0) {
				int a = q[i - j];
				int b = p[i - k];
				
				if (a > b) {
					r[i] = calc(p[j], q[i - j]);
				} else {
					r[i] = calc(q[k], p[i - k]);
				}
			} else {
				int a = p[i - j];
				int b = q[i - k];
				
				if (a > b) {
					r[i] = calc(q[j], p[i - j]);
				} else {
					r[i] = calc(p[k], q[i - k]);
				}
			}
		}
	}
	rep(i, 0, n) cout << r[i] << " ";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
