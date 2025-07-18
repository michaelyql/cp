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
    set<int> s;
    vi h(n);
    rep(i, 0, n) {
        cin >> h[i];
        s.insert(h[i]);
    }
    int curH = h[k];
    int maxH = *s.rbegin();
    int t = 0;
    auto it = s.begin();
    while (it != s.end() && *it <= curH) it++;
    while (it != s.end()) {
        int dt = *it - curH;
        if (t + dt > curH) {
            cout << "NO" << endl;
            return;
        }
        t += dt;
        curH = *it;
        it++;
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
