#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	int i;
	for (i = n - 1; i > 0; i--) {
		if (s[i] == '0') ans++;
		else break;
	}
	
	for (int j = 0; j < i; j++) {
		if (s[j] != '0') ans++;
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
