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

int main() {
    int n, m;
    cin >> n >> m;
    set<pii> conflict;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conflict.insert({--a, --b});
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        bool ok = true;
        for (auto& p : conflict) {
            if ((mask & (1 << p.first)) && (mask & (1 << p.second))) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
