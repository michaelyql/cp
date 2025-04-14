#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); i++)

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
    int n, y;
    cin >> n >> y;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int x = 0;
    rep(i, 0, n) {
        rep(j, 0, 20) {
            if ((1 << j) & a[i]) {
                x |= 1 << j;
            }
        }
    }
    if (x > y) {
        cout << -1 << endl;
        return;
    }
    int ans = 0;
    rep(i, 0, 20) {
        int k = 1 << i;
        if (k & y) {
            if (!(k & x)) {
                ans |= k;
            }
        } else {
            if (k & x) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << ans << endl;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
