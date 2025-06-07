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

const int N = 1000;
int a[N][N], dp[N][N];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr); 
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    const int inf = 1e9;
    vi d(n + 1, inf);
    d[0] = 0;
    rep(i, 0, n) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l - 1] < a[i] && a[i] < d[l]) {
            d[l] = a[i];
        }
    }
    int ans = 1;
    rep(i, 1, n + 1) if (d[i] != inf) ans = max(ans, i);
    cout << ans << endl;
}
