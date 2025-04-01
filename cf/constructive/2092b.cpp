#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int p = 0, q = 0, r = 0, s = 0;
	
	for (int i = 0; i < n; i += 2) {
		if (a[i] == '0') {
			p++;
		} else {
			q++;
		}
	}
	
	for (int i = 1; i < n; i += 2) {
		if (b[i] == '0') {
			p++;
		} else {
			q++;
		}
	}
	
	for (int i = 1; i < n; i += 2) {
		if (a[i] == '0') {
			r++;
		} else {
			s++;
		}
	}
	
	for (int i = 0; i < n; i += 2) {
		if (b[i] == '0') {
			r++;
		} else {
			s++;
		}
	}
	
	if (n & 1) {
		if (p > q && r >= s - 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		if (p >= q && r >= s) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	
} 


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
