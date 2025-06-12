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
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {
	int n;
	cin >> n;
	ull k;
	cin >> k;
	vi a(n);
	vi indices;
	int ans = 0;
	rep(i, 0, n) {
		cin >> a[i];
		rep(j, 0, 31) {
			if (!(a[i] & (1 << j))) {
				indices.push_back(j);
			} else {
				ans++;
			}
		}
		indices.push_back(31); 
		rep(j, 32, 64) indices.push_back(j);
	}
	sort(all(indices));
	int i = 0;
	while (i < indices.size() && k >= (1ull << indices[i])) {
		k -= (1ull << indices[i]);
		ans++;
		i++;
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
