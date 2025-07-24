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
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    vi up(n), down(n);
    int i = n - 1;
    while (i > 0) {
        up[i] = i;
        int j = i;
        while (j >= 1 && a[j - 1] <= a[j]) {
            up[j - 1] = i;
            j--;
        }
        i = j - 1;
    }
    i = n - 1;
    while (i > 0) {
        down[i] = i;
        if (i == 0) break;
        int j = i;
        while (j >= 1 && a[j - 1] >= a[j]) {
            down[j - 1] = i;
            j--;
        }
        i = j - 1;
    }
    
    int l, r;
    rep(i, 0, m) {
        cin >> l >> r;
        l--, r--;
        if (up[l] >= r || down[up[l]] >= r) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
