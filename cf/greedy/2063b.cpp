#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		l--;
		r--;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		
		// cout << "\n-------" << endl;
		// cout << "A unsorted: ";
		// for (int i = 0; i < n; i++) cout << a[i] << " ";
		// cout << endl;
		
		vector<int> b = a;
		sort(a.begin(), a.begin() + r + 1);
		
		// cout << "A sorted from " << 0 << " to " << r << " (inclusive): ";
		// for (int i = 0; i <= r; i++) cout << a[i] << " ";
		// cout << endl;
		
		// cout << "B unsorted: ";
		// for (int i = 0; i < n; i++) cout << b[i] << " ";
		// cout << endl;
		
		sort(b.begin() + l, b.end());
		
		// cout << "B sorted from " << l << " to " << n - 1 << " (inclusive): ";
		// for (int i = l; i <= n - 1; i++) cout << b[i] << " ";
		// cout << endl;
		
		
		int k = r - l + 1;
		// cout << "k: " << k << endl;
		ll ans1 = accumulate(a.begin(), a.begin() + k, 0ll);
		ll ans2 = accumulate(b.begin() + l, b.begin() + l + k, 0ll);
		cout << min(ans1, ans2) << endl;
	}
}
