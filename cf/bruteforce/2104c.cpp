#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
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

bool beats(int n, int x, int y) {
	if (x == 0) return y == n - 1;
	if (x == n - 1) return y != 0;
	return x > y;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	bool a_win = false;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == 'B') continue;

    // if Alice has a card which beats every single card that Bob can play initially,
		
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'B') ok &= beats(n, i, j);
		}

    // she will always play that card for every round and win eventually

		if (ok) a_win = true;
	}
	
	if (a_win) cout << "Alice";
	else cout << "Bob";
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
