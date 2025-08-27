#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    int n;
    cin >> n;
    string s = "";
    for (int i = 1; i <= n; i++) {
        s = s + to_string(i) + (i < n ? " " : "");
    }
    vector<vector<int>> g(n + 1);
    int maxl = 0;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n << " " << s << endl;
        cout.flush(); 
        int l;
        cin >> l;
        maxl = max(maxl, l);
        g[l].push_back(i);
    }
    int prev = g[maxl][0];
    vector<int> ans;
    ans.push_back(prev);
    for (int l = maxl; l > 1; l--) {
        for (int j = 0; j < g[l - 1].size(); j++) {
            cout << "? " << prev << " 2 " << prev << " " << g[l - 1][j] << endl;
            cout.flush(); 
            int res;
            cin >> res;
            if (res == 2) {
                prev = g[l - 1][j];
                ans.push_back(prev);
                break;
            }
        }
    }
    cout << "! " << ans.size() << " ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i < ans.size() ? " " : "");
    }
    cout << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
