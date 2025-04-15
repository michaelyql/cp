#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int cnt[1440];

void solve() {
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vi a(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < 1440; i++) {
        ans = max(ans, cnt[i]);
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
