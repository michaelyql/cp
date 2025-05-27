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

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int oc = 0, zc = 0;
	rep(i, 0, n) {
		if (s[i] == '1') oc++;
		else zc++;
	}	
	int a = oc, b = zc;
	if (a > b) swap(a, b);
	int min_k = n / 2 - min(a, b);
	int max_k = a / 2 + b / 2;
	if (k < min_k || k > max_k || abs(min_k - k) & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
