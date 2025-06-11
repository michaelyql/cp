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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n, q;
    cin >> n >> q;
    vi a(n);
    vll p(n + 1);
    rep(i, 0, n) cin >> a[i];
    rep(i, 1, n + 1) {
        p[i] = p[i - 1] + a[i - 1];
    }
    rep(i, 0, q) {
        int a, b;
        cin >> a >> b;
        cout << p[b] - p[a - 1] << endl;
    }
}
