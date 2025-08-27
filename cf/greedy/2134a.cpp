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
    int n, a, b;
    cin >> n >> a >> b;
    if (b == n) {
        cout << "YES" << endl;
        return;
    }
    if (b > a) {
        if (n & 1) {
            if (b & 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (b % 2 == 0) cout << "YES" << endl; 
            else cout << "NO" << endl;
        }
    } else {
        if (n & 1) {
            if ((b & 1) && (a & 1)) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (b % 2 == 0 && a % 2 == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
