#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++)

using vi = vector<int>;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    unordered_map<ll, int> mp;
    ll s = 0;
    int ans = 0;
    mp[0] = 1;
    rep(i, 0, n) {
        s += a[i];
        ans += mp[s - 47];
        mp[s]++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
