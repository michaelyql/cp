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

const ll mx = 9876543210ll;

void solve() {
	ll N;
	cin >> N;
	for (ll i = 1; i * N <= mx; i++) {
		ll j = i * N;
		vb used(10);
		ll s1 = j;
		bool ok = true;
		while (s1 > 0) {
			if (used[s1 % 10]) {ok = false; break;}
			used[s1 % 10] = true;
			s1 /= 10;
		}
		ll s2 = i;
		used.assign(10, false);
		while (s2 > 0) {
			if (used[s2 % 10]) {ok = false; break;}
			used[s2 % 10] = true;
			s2 /= 10;
		}
		if (ok) {
			cout << j << " / " << i << " = " << N << endl; 
		}
	}
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	int c = 0;
	while (t--) {
		solve();
		if (t >= 1) cout << endl;
	}
}
