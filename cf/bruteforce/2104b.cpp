#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define debug
 
#ifdef debug
#define db(x) cout << #x " = " << x << endl;
#define bp(x) cout << #x << endl;
#else 
#define db(x) 
#define bp(x)
#endif

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	unordered_map<int, int> del;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		del[a[i]]++;
	}
	priority_queue<int> pq(a.begin(), a.end());
	int mn = 2e9;
	ll s = 0;
	for (int k = 1; k <= n; k++) {
		// get the largest element on the left
		while (!pq.empty() && del[pq.top()] == 0) pq.pop();
		int j = pq.empty() ? 0 : pq.top();
		cout << s + j << " ";
		del[a[n - k]]--;
		s += a[n - k];
	}
	cout << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
