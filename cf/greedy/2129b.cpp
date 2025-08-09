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
using uint = unsigned int;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// usage: shuffle(all(a), rng)
// usage: uint32_t r = rng()

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];

    // compute I_{ij} counts and S0 = inversions of p
    long long S0 = 0;
    // naive O(n^2) calculation of w_i:
    vector<int> w(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (p[i] > p[j]) {
                S0 += 1;
                // I_{ij} = 1 contributes: for w: A_i counts p[j]>p[i], so here no
                // but B_j increases etc. We directly compute w by definition below.
            }
        }
    }

    // compute w_i = (# j>i with p[j]>p[i]) - (# j<i with p[j]>p[i])
    for (int i = 0; i < n; ++i) {
        int Ai = 0, Bi = 0;
        for (int j = i+1; j < n; ++j) if (p[j] > p[i]) ++Ai;
        for (int j = 0; j < i; ++j) if (p[j] > p[i]) ++Bi;
        w[i] = Ai - Bi;
    }

    // choose x_i = 1 iff w[i] < 0
    vector<int> x(n, 0);
    for (int i = 0; i < n; ++i) if (w[i] < 0) x[i] = 1;

    // build a and count inversions to verify
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (x[i]) a[i] = 2*n - p[i];
        else a[i] = p[i];
    }

    long long inv = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (a[i] > a[j]) ++inv;

    cout << inv << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
