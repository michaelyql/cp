#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	int n;
	cin >> n;
	string s;
	
	vector<int> even, odd;
	int ones = 0, zeros = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.size() & 1) odd.push_back(s.size());
		else even.push_back(s.size());
		
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '0') zeros++;
			else ones++;
		}
	}
	
	// cout << "ones="<<ones<<endl;
	// cout << "zeros="<<zeros<<endl;
	// cout << "even size="<<even.size()<<endl;
	// cout << "odd size="<<odd.size()<<endl;
	
	int ans = 0;
	for (int i = 0; i < even.size(); ) {
		if (ones > 1) {
			if (ones >= even[i]) {
				ones -= even[i];
				ans++;
				i++;
			} else {
				int use = ones; // use up everything
				if (ones & 1) use = ones - 1;
				even[i] -= use;
				ones -= use;
			}
		} else {
			if (zeros > 1) {
				if (zeros >= even[i]) {
					zeros -= even[i];
					ans++;
					i++;
				} else {
					int use = zeros;
					if (zeros & 1) use = zeros - 1;
					even[i] -= use;
					zeros -= use;
				}
			} else {
				break;
			}
		}
	}
	
	for (int i = 0; i < odd.size(); ) {
		if (ones >= 1) {
			if (ones >= odd[i]) {
				ones -= odd[i];
				ans++;
				i++;
			} else {
				odd[i] -= ones;
				ones = 0;
			}
		} else {
			if (zeros >= 1) {
				if (zeros >= odd[i]) {
					zeros -= odd[i];
					ans++;
					i++;
				} else {
					odd[i] -= zeros;
					zeros = 0;
				}
			} else {
				break;
			}
		}
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
