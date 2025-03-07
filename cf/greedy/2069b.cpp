#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int N = 705;
const int M = 705;
int A[N][M];

bool ok[N * M + 1];
bool exists[N * M + 1];

int n, m;

void solve() {
	 cin >> n >> m;
	 
	 memset(ok, true, sizeof(ok));
	 memset(exists, false, sizeof(exists));
	 
	 for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 		cin >> A[i][j];
	 		exists[A[i][j]] = true;
	 	}
	 }

	 for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
	 		if (i > 0 && A[i - 1][j] == A[i][j]) ok[A[i][j]] = false;
	 		if (i + 1 < n && A[i + 1][j] == A[i][j]) ok[A[i][j]] = false;
	 		if (j > 0 && A[i][j - 1] == A[i][j]) ok[A[i][j]] = false;
	 		if (j + 1 < m && A[i][j + 1] == A[i][j]) ok[A[i][j]] = false;
	 	}
	 }
	 
	 int ans = 0;
	 bool has_adj = false;
	 
	 for (int i = 1; i <= n * m; i++) {
	 	if (!exists[i]) continue;
	 	if (ok[i]) {
	 		// cout << "i="<<i<<" is ok"<<endl;
	 		ans += 1;
	 	}
	 	else {
	 		ans += 2;
	 		has_adj = true;
	 	}
	 }
	 
	 //cout<<"ans before minus="<<ans<<endl;
	 //cout << "has adj="<<has_adj<<endl;
	 if (has_adj) ans -= 2;
	 else ans -= 1;
	 
	 cout << ans << endl;
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	int t;
	cin >> t;
	while (t--) solve();
}
