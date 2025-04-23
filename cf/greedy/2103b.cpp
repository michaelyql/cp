#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int flip = 0;
	char state = '0';
	rep(i, 0, n) {
		if (s[i] != state) {
			flip++;
			state = s[i];
		} 	
	}
	if (flip == 0) {
		cout << n << endl;
		return;
	}
	if (flip == 1 || flip == 2) {
		cout << n + 1 << endl;
		return;
	}
	cout << n + flip - 2 << endl;
	
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
