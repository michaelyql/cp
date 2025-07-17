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
    int n, k;
    cin >> n >> k;
    k--;
    vi h(n);
    rep(i, 0, n) cin >> h[i];
    int curH = h[k];
    sort(all(h));
    int maxH = h[n - 1];
    int i = 0;
    int t = 0;
    while (i < n && h[i] != curH) i++;
    for (; i < n && h[i] != maxH; i++) {
        int j = i + 1;
        while (j < n && h[j] == h[i]) j++;
        int dt = h[j] - curH;
        
        if (t + dt > curH) {
            cout << "NO" << endl;
            return;
        }
        t = t + dt;
        curH = h[j];
    }
    cout << "YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
