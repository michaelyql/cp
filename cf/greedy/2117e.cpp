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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {

	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	multiset<int> s1, s2;

	if (a[n - 1] == b[n - 1]) {
		cout << n << endl;
		return;
	}
	
	int ans = 0; 
	
	for (int i = n - 1; i >= 1; i--) {
		
		if (a[i] == b[i]) {
			ans = max(ans, i + 1);
		}
		
		// assume no match till now
		if (i & 1) {
			s1.insert(a[i]);
			s2.insert(b[i]);
		} else {
			s1.insert(b[i]);
			s2.insert(a[i]);
		}
		
		if (i & 1) {
			if (i - 1 >= 0) {
				if (s1.find(a[i - 1]) != s1.end() || s2.find(b[i - 1]) != s2.end()) {
					ans = max(ans, i);
				}
			} 
			if (i - 2 >= 0) {
				if (s1.find(a[i - 2]) != s1.end() || s2.find(b[i - 2]) != s2.end()) {
					ans = max(ans, i - 1);
				}
			}
		} else {
			if (i - 1 >= 0) {
				if (s1.find(b[i - 1]) != s1.end() || s2.find(a[i - 1]) != s2.end()) {
					ans = max(ans, i);
				}
			} 
			if (i - 2 >= 0) {
				if (s1.find(b[i - 2]) != s1.end() || s2.find(a[i - 2]) != s2.end()) {
					ans = max(ans, i - 1);
				}
			}
		}
	}
	
	cout << max(ans, a[0] == b[0] ? 1 : 0) << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
