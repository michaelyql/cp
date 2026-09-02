// #define NDEBUG // comment out to disable asserts
// compilation: g++ -Wall -std=c++17 sol.cpp -o sol && ./sol < in > out 2>&1
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <cmath>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i, a, b) for (int i = (a); i < (b); (i)++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;

#ifdef DEBUG
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[ ";
    for (const auto& i : v) os << i << " ";
    os << "]";
    return os;
}

void debug_out() { cerr << endl; }

template <typename head, typename... tail> 
void debug_out(head h, tail... t) {
    cerr << h << ' ';
    debug_out(t...);
}

#define dbg(...) do { cerr << "(" << #__VA_ARGS__ << "): "; debug_out(__VA_ARGS__); } while (0)
#else
#define dbg(...) 
#endif

const int MAXN = 3e5;
const int mod = 998244353;
int sum[41][MAXN + 1];
int fact[MAXN + 1], ifact[MAXN + 1];

int mul(int a, int b) {
    return (ll) a % mod * b % mod;
}

int add(int a, int b) {
    return ((a % mod) + (b % mod)) % mod;
}

int sub(int a, int b) {
    return a >= b ? a - b : (a % mod) + mod - b;
}

int nCr(int n, int r) {
    if (n < 0 || r > n || r < 0) return 0;
    return mul(mul(fact[n], ifact[n - r]), ifact[r]);
}

int modpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

void solve() {
    memset(sum, 0, sizeof(sum));
    memset(fact, 0, sizeof(fact));
    memset(ifact, 0, sizeof(ifact));

    int n, m;
    cin >> n >> m;
    
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=mul(fact[i-1],i);
    ifact[n]=modpow(fact[n], mod-2);
    for(int i=n-1; i>=0; i--) ifact[i]=mul(ifact[i+1], i+1);

    vector<pii> edges;
    vi l(n+1), r(n+1);
    vi d(n+2, 0);

    for(int i=1;i<=n;i++){
        cin >> l[i] >> r[i];
        d[l[i]]++;
        d[r[i]+1]--;
    }

    vi cnt(n+1, 0);
    for(int i=1; i<=n; i++){
        cnt[i] = cnt[i-1] + d[i];
    }
    
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        edges.pb({u,v});
    }

    for(int k=2; k<=m*2; k++) {
        for(int i=k; i<=n; i++) {
            sum[k][i] = add(sum[k][i-1], nCr(cnt[i]-k, i-k));
        }
    } 

    int ans = 0;

    for (int i = 1; i<=n; i++) {
        ans = add(ans, nCr(cnt[i], i));
    }

    for(int i=0;i<(1<<m); i++){
        unordered_set<int> s;
        int L = 1, R = n;
        for(int j=0;j<m;j++){
            if (!(i & (1<<j))) continue;
            auto [u,v] = edges[j];
            s.insert(u);
            s.insert(v);
            L = max(L, max(l[u], l[v]));
            R = min(R, min(r[u], r[v]));
        }
        if (L > R) continue;
        int k = (int) s.size();
        int v = sub(sum[k][R], sum[k][L-1]);
        if (__builtin_popcount(i) & 1) {
            ans = sub(ans, v);
        } else {
            ans = add(ans, v);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
    auto t1 = chrono::high_resolution_clock::now();
    #endif

    // calc();

    solve();
    // int t;
    // cin >> t; 
    // for(int i=1;i<=t;i++){
    //     #ifdef DEBUG
    //     cerr << "-------- Test case " << i << " -----\n";
    //     #endif
    //     solve();
    // }

    #ifdef DEBUG
    auto t2 = chrono::high_resolution_clock::now();
    auto t3 = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
    cerr << "\nTook: " << t3.count() << " ms\n";
    #endif
}
