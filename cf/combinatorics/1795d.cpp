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

const int mod = 998244353;
const int MAXN = 3e5;
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

void calc() {
	fact[0] = 1;
	for (int i = 1; i <= MAXN; i++) fact[i] = mul(fact[i-1], i);
	ifact[MAXN] = modpow(fact[MAXN], mod - 2);
	for (int i = MAXN - 1; i >= 0; i--) ifact[i] = mul(ifact[i+1], i+1);
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n)cin>>a[i];
    int ans=1;
    for(int i=0;i<n;i+=3) {
        int w1=a[i], w2=a[i+1], w3=a[i+2];
        int x=w1+w2, y=w1+w3, z=w2+w3;
        int mx = max(max(x,y),z);
        int cnt = (x==mx) + (y==mx) + (z==mx);
        ans=mul(ans,cnt);
    }
    int s=0;
    for(int i=0;i<=n/6;i++){
        int v=nCr(n/6,i);
        v = mul(v,v);
        s = add(s, v);
    }
    ans=mul(ans,s);
    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
    auto t1 = chrono::high_resolution_clock::now();
    #endif

    calc();

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
