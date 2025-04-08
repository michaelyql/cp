#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


void q1(int& x, int& y, ll& d, int xstart, int xend, int ystart, int yend, int n) {
	if (n == 0) return;
	
	int e1 = xstart + (1 << (n - 1));
	int e2 = ystart + (1 << (n - 1));
	
	if (x < e1 && y < e2) {
		q1(x, y, d, xstart, e1, ystart, e2, n - 1);
		
	} else if (x < e1 && y >= e2) {
		d += (1ll << ((n - 1) * 2)) * 3;
		q1(x, y, d, xstart, e1, e2, yend, n - 1);
		
	} else if (x >= e1 && y < e2) {
		d += (1ll << ((n - 1) * 2)) * 2;
		q1(x, y, d, e1, xend, ystart, e2, n - 1);
		
	} else {
		d += (1ll << ((n - 1) * 2));
		q1(x, y, d, e1, xend, e2, yend, n - 1);
	}
	
}


void q2(ll d, ll start, ll end, int& x, int& y, int n) {
	if (n == 0) return;
	
	ll jump = (end-start+1)/4;
	
	ll e1 = start + jump;
	ll e2 = start + 2 * jump;
	ll e3 = start + 3 * jump;
	
	if (d >= start && d < e1) {
		q2(d, start, e1, x, y, n - 1);
		
	} else if (d >= e1 && d < e2) {
		
		x += 1 << (n - 1);
		y += 1 << (n - 1);
		
		q2(d, e1, e2, x, y, n - 1);
		
	} else if (d >= e2 && d < e3) {
		x += 1 << (n - 1);
		
		q2(d, e2, e3, x, y, n - 1);
		
	} else {
		y += 1 << (n - 1);
		
		q2(d, e3, end, x, y, n - 1);
	}
}


void solve() {
	int n, q;
	cin >> n >> q;
	ll end = 1ll << (2 * n);
	
	string s;
	int x, y;
	ll d;
	rep(k, 0, q) {
		cin >> s;
		if (s[1] == '>') {
			cin >> x >> y;
			ll d = 1;
			
			q1(x, y, d, 1, end, 1, end, n);
			
			cout << d << endl;
			
		} else {
			cin >> d;
			int x = 1, y = 1;
			q2(d, 1, end, x, y, n);
			cout << x << " " << y << endl;
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
