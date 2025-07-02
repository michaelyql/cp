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
    ll a[4], b[4];
    for (int i = 1; i < 4; i++) {
        cin >> a[i] >> b[i];
    }
    // single row or column
    ll ans = 5e18;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ll w = max(max(b[1], b[2]), b[3]);
                ll h = a[1] + a[2] + a[3];
                ans = min(ans, w * h);

                w = max(max(a[1], a[2]), a[3]);
                h = b[1] + b[2] + b[3];
                ans = min(ans, w * h);
                swap(a[3], b[3]);   
            }
            swap(a[2], b[2]);
        }
        swap(a[1], b[1]);
    }
    for (int i = 1; i <= 3; i++) {
        for (int ii = 0; ii < 2; ii++) {
            for (int j = 1; j <= 3; j++) {
                if (j == i) continue;
                for (int jj = 0; jj < 2; jj++) {
                    for (int k = 1; k <= 3; k++) {
                        if (k == i || k == j) continue;
                        for (int kk = 0; kk < 2; kk++) {
                            ll w = b[i] + max(b[j], b[k]);
                            ll h = max(a[i], a[j] + a[k]);
                            ans = min(ans, w * h);

                            w = max(b[i], b[j] + b[k]);
                            h = a[i] + max(a[j], a[k]);
                            ans = min(ans, w * h);
                            swap(a[k], b[k]);
                        }
                    }
                    swap(a[j], b[j]);
                }
            }
            swap(a[i], b[i]);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
