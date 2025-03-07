#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;
int p[N], a[N];

ll calc(int x, int n, int k) {
	ll cur = 0;
	ll mx = 0;
	int i = 0;
	vector<bool> vis(n);
	while (!vis[x] && i < min(n, k)) {
		vis[x] = true;
		mx = max(mx, cur + 1ll * a[x] * (k - i));
		cur += a[x];
		x = p[x];
		i++;
	}
	return mx;
}

void solve() {
	int n, k, B, S;
	cin >> n >> k >> B >> S;
	B--; S--;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) cin >> a[i];
	
	ll b_score = calc(B, n, k);
	ll s_score = calc(S, n, k);
	
	if (b_score > s_score) {
		cout << "Bodya" << endl;
	} else if (b_score < s_score) {
		cout << "Sasha" << endl;
	}
	else cout << "Draw" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
