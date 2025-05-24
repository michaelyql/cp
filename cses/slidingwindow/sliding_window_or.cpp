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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;
	ll x, a, b, c;
	cin >> x >> a >> b >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = x;
		x = (a * x % c + b) % c;
	}
	int ans = 0;
	for (int i = 0; i < 31; i++) {
		int cnt = 0, par = 0;
		int b = 1 << i;
		for (int j = 0; j < k; j++) if (v[j] & b) cnt++;
		if (cnt) par++;
		for (int j = 1; j < n - k + 1; j++) {
			cnt -= (v[j - 1] & b) != 0;
			cnt += (v[j + k - 1] & b) != 0;
			if (cnt) par++;
		}
		if (par & 1) ans |= b;
	}
	cout << ans << endl;
}
