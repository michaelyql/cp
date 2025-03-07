#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
	// cout << "---"<<endl;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	int l = 0, r = 0;
	int mn_cnt = 0;
	
	for (int i = 0; i < n; i++) {
		int more = 0, lesss = 0;
		
		for (int j = i + 1; j < n; j++) {
			
			if (a[i] > a[j]) {
				more++;
			} else if (a[i] < a[j]) {
				lesss++;
			} 
			
			int change = lesss - more;
			
			// cout << "i="<<i<<", j="<<j<<", chg="<<change<<", mn_cnt="<<mn_cnt<<endl;
			
			if (change < mn_cnt) {
				mn_cnt = change;
				l = i;
				r = j;
			}
		}	
	}
	l++;
	r++;
	cout << l << " "  << r << endl;
	
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
