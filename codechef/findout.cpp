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
    int pos = 0, neg = 0, x = 0, y = 0;
    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] > 0) pos++, x = max(x, a[i]);
        else if (a[i] < 0) neg++, y = min(y, a[i]);
    }
    if (pos + neg == 0) { // all zeros
        cout << -1 << endl;
        return;
    }
    if (pos + neg == 1) { 
        // only one positive and all zeros, or
        // only one negative and all zeros 
        if (x) cout << x << " " << x << endl;
        else cout << y << " " << y << endl;
        return;
    }
    if (pos >= 2) {
        cout << x << " " << x << endl;
        return;
    }
    if (neg >= 2) {
        cout << y << " " << y << endl;
        return;
    }
    // exactly one pos and one neg
    // just pick any one of them, 2*their value will work
    cout << x << " " << x << endl;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
