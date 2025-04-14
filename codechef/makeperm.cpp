#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    int mn = n;
    vi cnt(n + 1, 0);
    rep(i, 0, n) {
        cin >> a[i];
        mn = min(mn, a[i]);
        cnt[a[i]]++;
    }
    if (mn > 1) {
        cout << "NO" << endl;
        return;
    }
    ll excess = 0;
    for (int i = n; i >= 1; i--) {
        if (!cnt[i]) {
            excess++;
            continue;
        }
        if (cnt[i] > excess + 1) {
            cout << "NO" << endl;
            return;
        }
        excess -= (cnt[i] - 1);
    }
    cout << "YES" << endl;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
