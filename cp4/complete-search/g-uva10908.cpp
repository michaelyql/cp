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

int M, N, Q;

void F(int r, int c, vector<string>& A) {
	int len = 0;
	bool ok = true;
	while (ok) {
		int nlen = len + 1;
		if (c - nlen < 0 || c + nlen >= N || r - nlen < 0 || r + nlen >= M) break;
		for (int i = c - nlen; i <= c + nlen; i++) {
			if (A[r - nlen][i] != A[r][c] || A[r + nlen][i] != A[r][c]) {
				ok = false;
				break;
			}
		}
		for (int i = r - nlen + 1; i <= r + nlen - 1; i++) {
			if (A[i][c - nlen] != A[r][c] || A[i][c + nlen] != A[r][c]) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
		len++;
	}
	cout << 1 + len * 2 << endl;
}

void solve() {
	cin >> M >> N >> Q;
	vector<string> A(M);
	rep(i, 0, M) cin >> A[i];
	vector<pii> queries(Q);
	rep(i, 0, Q) {
		int r, c;
		cin >> r >> c;
		queries[i] = {r, c};
	}
	cout << M << " " << N << " " << Q << endl;
	rep(i, 0, Q) {
		F(queries[i].first, queries[i].second, A);
	}
} 

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
