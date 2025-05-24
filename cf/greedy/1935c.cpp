#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define LSOne(S) ((S) & -(S)) 
#define all(x) (x).begin(), (x).end()
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
	int n, l;
	cin >> n >> l;
	int a, b;
	vector<pii> v;
	rep(i, 0, n) {
		cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(all(v));
	int ans = 0;
	rep(i, 0, n) {
		ll sum = 0;
		priority_queue<int> pq;
		rep(j, i, n) {
			sum += v[j].second;
			pq.push(v[j].second);
			while (!pq.empty() && 1ll * v[j].first - v[i].first + sum > l) {
				int k = pq.top();
				sum -= k;
				pq.pop();
			}
			ans = max(ans, (int) pq.size());
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
