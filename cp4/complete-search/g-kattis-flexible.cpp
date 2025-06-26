#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++) 
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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vb = vector<bool>;

void solve() {
	
} 

int main() {
	int W, P;
	cin >> W >> P;
	vi a(P);
	rep(i, 0, P) cin >> a[i];
	set<int> ans;
	ans.insert(W);
	for (int i = 0; i < P; i++) {
		ans.insert(a[i]);
		ans.insert(W - a[i]);
		for (int j = i + 1; j < P; j++) {
			ans.insert(a[j] - a[i]);
		}
	}
	for (auto x : ans) cout << x << " ";
	cout << endl;
}
