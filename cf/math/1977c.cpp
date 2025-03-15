#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int check(map<int, int>& mp, int d) {
	ll LCM = 0;
	int cnt = 0;
	for (auto& p : mp) {
		int k = p.first;
		int v = p.second;
		
		if (d % k == 0) {
			if (LCM == 0) LCM = k;
			else LCM = lcm(LCM, k);
			
			cnt += v;
		}
	}
	if (LCM != d) return 0;
	else return cnt;
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	map<int, int> mp;
	int mx = 0;
	ll LCM = 0;
	
	rep(i, 0, n) {
		cin >> a[i];
		mp[a[i]]++;
		mx = max(mx, a[i]);
	}

	rep(i, 0, n) {
		if (LCM == 0) LCM = a[i];
		else LCM = lcm(LCM, a[i]);
		if (LCM > mx) {
			cout << n << endl;
			return;
		}
	}
	
	int ans = 0;
	for (int i = 1; i * i <= mx; i++) {
		if (mx % i == 0) {
			if (mp.find(i) == mp.end())	{
				ans = max(ans, check(mp, i));
			}
      if (mp.find(mx / i) == mp.end()) {
			  ans = max(ans, check(mp, mx / i));
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
