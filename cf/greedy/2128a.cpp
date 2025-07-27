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
    int n, c;
    cin >> n >> c;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    ll p = 1;
    int cost = 0;
    int i = n - 1;
    while (i >= 0 && a[i] > c) {
        i--;
        cost++;
    }
    while (i >= 0) {
        while (i >= 0 && a[i] * p > c) {
            i--;
            cost++;
        }
        p *= 2;
        i--;
    }
    cout << cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
