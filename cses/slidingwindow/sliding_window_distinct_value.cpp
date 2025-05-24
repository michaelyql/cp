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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, 0, n) cin >> a[i];
	unordered_map<int, int> mp;
	rep(i, 0, k) mp[a[i]]++;
	cout << mp.size() << " ";
	rep(i, 1, n - k + 1) {
		mp[a[i - 1]]--;
		mp[a[i + k - 1]]++;
		if (mp[a[i - 1]] == 0) mp.erase(a[i - 1]);
		cout << mp.size() << " ";
	}
}
