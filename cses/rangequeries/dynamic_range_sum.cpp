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
    vi a(n + 1);
    vll T(n + 1);
    rep(i, 1, n + 1) {
        cin >> a[i];
        int j = i;
        while (j <= n) {
            T[j] += a[i];
            j += j & (-j);
        }
    }
    rep(i, 0, q) {
        int c;
        cin >> c;
        if (c == 1) {
            int k, u;
            cin >> k >> u;
            int delta = u - a[k];
            a[k] = u;
            int j = k;
            while (j <= n) {
                T[j] += delta;
                j += j & (-j);
            }
        } else {
            int a, b;
            cin >> a >> b;
            ll sum1 = 0, sum2 = 0;
            int j = b;
            while (j > 0) {
                sum1 += T[j];
                j -= j & (-j);
            }
            j = a - 1;
            while (j > 0) {
                sum2 += T[j];
                j -= j & (-j); 
            }
            cout << sum1 - sum2 << endl;
        }
    }

}
