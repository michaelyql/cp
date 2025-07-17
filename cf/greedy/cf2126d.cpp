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

struct node {
    int l, r, real;
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<node> a(n);
    rep(i, 0, n) {
        cin >> a[i].l >> a[i].r >> a[i].real;
    }
    sort(all(a), [](const node& n1, const node& n2) {
        if (n1.l != n2.l) return n1.l < n2.l;
        return n1.real < n2.real;
    });
    
    int c = k, i = 0;
    priority_queue<pii> pq;
    while (true) {
        while (i < n && a[i].l <= c) {
            pq.push({a[i].real, i});
            i++;
        }
        bool found = false;
        while (!pq.empty()) {
            auto [real, idx] = pq.top();
            pq.pop();
            if (c <= a[idx].r) {
                if (c < real) {
                    c = real;
                    found = true;
                } else {
                    break;
                }
            }
        }
        if (!found) break;
    }

    cout << max(c, k) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
