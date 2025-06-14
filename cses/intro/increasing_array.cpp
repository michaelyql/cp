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
using vb = vector<bool>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    rep(i, 1, n) {
        if (a[i] < a[i - 1]) {
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << ans << endl;
}
