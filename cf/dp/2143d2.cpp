#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
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
using vll = vector<long long>;
using vvll = vector<vll>;
using vb = vector<bool>;
using uint = unsigned int;

random_device rnd;
mt19937 mt(rnd());
// usage: shuffle(all(a), mt)
// usage: uint32_t r = mt()

const int mod = 1e9 + 7;

struct fenwick {
    int n;
    vll f;
    fenwick() : n(0) {}
    fenwick(int n_): n(n_), f(n_ + 1) {
        f.assign(n_ + 1, 0);
    }

    void reset(int n_){ n = n_; f.assign(n+1, 0); }
    
    void add(int i, ll delta){
        while(i <= n){
            f[i] += delta;
            if(f[i] >= mod) f[i] -= mod;
            i += i & -i;
        }
    }
    ll sumPrefix(int i) const {
        ll s = 0;
        while(i > 0){
            s += f[i];
            if(s >= mod) s -= mod;
            i -= i & -i;
        }
        return s;
    }
};

void solve() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n) cin >> a[i];

    vll vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = (int) vals.size();          
    map<ll, int> comp;
    rep(i, 0, m) comp[vals[i]] = i+1;

    int N = m + 1; 

    vector<fenwick> bitX(N), bitY(N);
    rep(i, 0, N) {
        bitX[i] = fenwick(N);
        bitY[i] = fenwick(N);
    }

    auto idx = [&](int rank) -> int{
        return rank + 1;
    };

    bitX[0].add(idx(0), 1);
    bitY[0].add(idx(0), 1);

    vll s0(N), s1(N);

    rep(i, 0, n) {
        int v = comp[a[i]];
        int vidx = idx(v);  

        rep(y, 0, m + 1) {
            s0[y] = bitX[y].sumPrefix(vidx);
        }
        rep(x, 0, m + 1) {
            s1[x] = bitY[x].sumPrefix(vidx);
        }

        rep(y, 0, m + 1) {
            int x_index = vidx;      
            int y_index = idx(y);    
            ll add = s0[y];
            if(add == 0) continue;
            bitX[y].add(x_index, add);
            bitY[v].add(y_index, add);
        }

        rep(x, v + 1, m + 1) {
            int x_index = idx(x);    
            int y_index = vidx;     
            ll add = s1[x];
            if(add == 0) continue;
            bitX[v].add(x_index, add);
            bitY[x].add(y_index, add); 
        }
    }

    ll ans = 0;
    for (int x = 0; x <= m; ++x) {
        ll rowSum = bitY[x].sumPrefix(N); 
        ans += rowSum;
        if (ans >= mod) ans -= mod;
    }
    cout << ans % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
