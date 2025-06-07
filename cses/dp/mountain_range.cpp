#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int (i) = (a); (i) < (b); (i)++) 
#define rrep(i, a, b) for (int i = a; i >= b; i--)
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

int f(int i, vi& dp, vi& l, vi& r) {
    if (dp[i] != 0) return dp[i];
    int ret = 1;
    if (l[i] != -1) ret += f(l[i], dp, l, r);
    if (r[i] != -1) ret = max(ret, 1 + f(r[i], dp, l, r));
    return dp[i] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi l(n, -1), r(n, -1);
    stack<pii> st;
    rep(i, 0, n) {
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (!st.empty()) l[i] = st.top().second;
        st.push({a[i], i});
    }
    while (!st.empty()) st.pop();
    rrep(i, n - 1, 0) {
        while (!st.empty() && st.top().first <= a[i]) st.pop();
        if (!st.empty()) r[i] = st.top().second;
        st.push({a[i], i});
    }
    vi dp(n, 0);
    int ans = 1;
    rep(i, 0, n) if (dp[i] == 0) ans = max(ans, f(i, dp, l, r));
    cout << ans << endl;
}
