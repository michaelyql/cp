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


int main() {
	int l, h;
	cin >> l >> h;
	int ans = 0;
	for (int i = l; i <= h; i++) {
		vi used(10);
		int temp = i;
		for (int j = 0; j < 6; j++) {
			used[temp % 10]++;
			temp /= 10;
		}
		bool ok = true;
		int t_used = 0;
		for (int j = 1; j < 10; j++) {
			if (used[j]) {
				t_used++;
				if (used[j] != 1) ok = false;
			}
		}
		if (t_used != 6) ok = false;
		if (ok) {
			for (int j = 1; j < 10; j++) {
				if (used[j]) ok = ok && (i % j == 0);
			}
		}
		if (ok) {
			ans++;
		}
	}
	cout << ans << endl;
}
