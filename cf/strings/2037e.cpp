#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	
	int res;
	
	int z = 0, ones = 0;
	
	string ans = "";

	cout << "? 1 2" << endl; cout.flush();
	cin >> res;

	int j = 3;
	if (res == 0) {
		// could be 00xxxx or 10xxxx or 11xxxx
		while (j <= n) {
			cout << "? 1 " << j << endl;
			cin >> res;
			if (res == 0) {
				j++;
			} else {
				if (res >= j) {
					cout << "! IMPOSSIBLE" << endl; cout.flush(); return;
				}
				for (int i = 0; i < j - 1 - res; i++) ans += '1';
				for (int i = 0; i < res; i++) ans += '0', z++;
				ans += '1';
				ones = res;
				j++;
				break;
			}
		}
		if (ones == 0) {
			cout << "! IMPOSSIBLE" << endl; cout.flush(); return;
		}
	} else {
		z++;
		ans = "01";
		ones = 1;
	}
		
	while (j <= n) {
		cout << "? 1 " << j << endl; cout.flush();
		cin >> res;
		if (res == ones) {
			z++;
			ans += '0';
		} else {
			if (res != ones + z) {
				cout << "! IMPOSSIBLE" << endl; cout.flush(); return;
			}
			ones = res;
			ans += '1';
		}
		j++;
	}

	cout << "! " << ans << endl; cout.flush();
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
