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

const int N = 1e5 + 5;
int t[N], x[N], y[N];
const int inf = 1e9;

int main() {
    int r, n;
    cin >> r >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }
    vector<int> pmax(n + 1, 0), ans(n + 1, -inf);
    int _ans = 0;
    for (int i = 1; i <= n; i++) {
        pmax[i] = pmax[i - 1];
        int cur = 0;
        int k = i - 2 * r;
        if (k > 0) cur = pmax[k];
        for (int j = i - 1; j > max(0, k); j--) {
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
                cur = max(cur, ans[j]);
            }
        }
        if (x[i] + y[i] - 2 <= t[i]) {
            ans[i] = 1 + cur;
            pmax[i] = max(pmax[i], ans[i]);
            _ans = max(_ans, ans[i]);
        }
    }
    cout << _ans << endl;
}
