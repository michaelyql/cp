#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


void solve() {
	int n;
	cin >> n;
	vi odd, even;
	rep(i, 0, n) {
		int x;
		cin >> x;
		if (x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());
	if (even.empty()) {
		cout << odd.back() << endl;
		return;
	} 
	if (odd.empty()) {
		cout << even.back() << endl;
		return;
	}
	
	if (even.back() > odd.back()) {
		int give = even.back() - (even.back() + odd.back()) / 2;
		even[even.size() - 1] -= give;
		odd[odd.size() - 1] += give;
	}
	ll total = accumulate(even.begin(), even.end(), 0ll);
	rep(i, 0, odd.size() - 1) {
		total += (odd[i] - 1);
	}
	cout << total + odd.back() << endl;
	
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
