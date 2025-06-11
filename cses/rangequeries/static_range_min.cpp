#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
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
using vvll = vector<vll>;

const int MAX_N = 2e5;
int st[20][MAX_N];

int _log2(int x) {
    int ret = 0;
    while (x > 1) x >>= 1, ret++;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    for (int j = 0; j < n; j++) {
        st[0][j] = a[j];
    }
    for (int k = 1; k <= _log2(n); k++) {
        int offset = 1 << (k - 1);
        for (int j = 0; j + offset < n; j++) {
            st[k][j] = min(st[k - 1][j], st[k - 1][j + offset]);
        }
    }
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        int k = _log2(b - a + 1);
        a--; // make the range 0-indexed
        cout << min(st[k][a], st[k][b - (1 << k)]) << endl;
    }

}
